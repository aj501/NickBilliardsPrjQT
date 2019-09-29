#include "utils.h"
#include "rate.h"

namespace Utils {
    double priceCal(const Bill * const bill) {
        double total = 0;
        QList<QPair<QTime, int>> numPlayers = bill->getAllNumPlayers();
        QTime start = bill->getStartTime();
        for (int i = 0; i < numPlayers.length(); i++) {
            QPair<QTime, int> numPlayer = numPlayers[i];
            total += priceCal(start, numPlayer.first, numPlayer.second, bill->getIsMember(), bill->getIsSpecialRate(),
                              bill->getTableType());
            if (i == numPlayers.length()-1) {
                total += priceCal(numPlayer.first, bill->getEndTime(), numPlayer.second, bill->getIsMember(), bill->getIsSpecialRate(),
                                  bill->getTableType());
            }
            start = numPlayer.first;
        }
        // Discount
        total *= (100-bill->getDiscount())/100;

        // Senior/Military
        double eachPersonBill = total/bill->getNumPlayers();
        int numSenMil = bill->getNumSeniorOrMilitary();
        int numNonSenMil = bill->getNumPlayers()-numSenMil;
        total = eachPersonBill*numNonSenMil +
                eachPersonBill/2*numSenMil;
        // Food
       // total += bill->getFoodAndBeverage();
        return total;
    }

    double priceCal(QTime start, QTime end, int numPlayers, bool isMemberRate, bool isSpecialRate, TableType tableType) {
        double total = 0.0;
        if (isMemberRate && tableType == TableType::SevenFooter && isAfterSevenPm(start)) {
            total = Rate::SpecialMemberRate * numPlayers;
        } else if (isBeforeSevenPm(end)) {
            double hours = CalculateHours(start, end);
            total = priceCalBefore7pm(numPlayers, isSpecialRate, hours);
        } else if (isAfterSevenPm(start)) {
            double hours = CalculateHours(start, end);
            total = priceCalAfter7pm(numPlayers, hours);
        } else {
            double dayHours = CalculateHours(start, QTime(19, 0, 0));
            double nightHours = CalculateHours(QTime(19, 0, 0), end);
            total = priceCalBefore7pm(numPlayers, isSpecialRate, dayHours) + priceCalAfter7pm(numPlayers, nightHours);
        }
        return total;
    }

    double priceCalBefore7pm(int numPlayers, bool isSpecialRate, double hours) {
        double total;
        if(isSpecialRate)
        {
            total = numPlayers*Rate::DailySpecialRate;
        }
        else
        {
            total  = numPlayers*hours*Rate::DailyRate;
        }
        return total;
    }

    double priceCalAfter7pm(int numPlayers, double hours) {
        double total = 0.0;
        LoadRate();
        QTextStream out(stdout);
        out << Rate::NightRateOnePlayer;
        switch (numPlayers) {
        case 1:
            total = Rate::NightRateOnePlayer*hours;
            break;
        case 2:
            total = Rate::NightRateTwoPlayer*hours;
            break;
        case 3:
            total = Rate::NightRateThreePlayer*hours;
            break;
        case 4:
            total = Rate::NightRateFourPlayer*hours;
            break;
        case 5:
            total = Rate::NightRateFivePlayer*hours;
            break;
        case 6:
            total = Rate::NightRateSixPlayer*hours;
            break;
        }
        return total;
    }

    bool isBeforeSevenPm(QTime time) {
        if (time.hour() >= 10 && time.hour() < 19) {
            return true;
        }
        return false;
    }

    bool isAfterSevenPm(QTime time) {
        if (time.hour() >= 19 || time.hour() <= 2) {
            return true;
        }
        return false;
    }

    double CalculateHours(QTime start, QTime end) {
        int msecs = start.msecsTo(end);
        if (msecs < 0) {
            msecs += 86400000;
        }
        return msecs/3.6e+6;
    }

    void LoadRate() {
        QTextStream out(stdout);

        //The QDomDocument class represents an XML document.
        QDomDocument xmlBOM;
        // Load xml file as raw data

        QDir bin(QCoreApplication::applicationDirPath());
        #if defined(Q_OS_DARWIN)
            bin.cdUp();    /* Fix this on Mac because of the .app folder, */
            bin.cdUp();    /* which means that the actual executable is   */
            bin.cdUp();    /* three levels deep. Grrr.                    */
        #endif
            QDir::setCurrent(bin.absolutePath());

        QString path = bin.path();
        path.append("/ratedata.xml");
        out << path;
        QFile f(path);

        if (!f.open(QIODevice::ReadOnly ))
        {
            // Error while loading file
            out << "can't open file";
            return;
        }
        // Set data into the QDomDocument before processing
        xmlBOM.setContent(&f);
        f.close();

        QDomElement root=xmlBOM.documentElement();
        // Get the first child of the root (Markup COMPONENT is expected)
        //QDomElement Rate=root.firstChildElement("Rate");
        QDomNode child = root.firstChild();
        QDomElement Rate = child.toElement();
        out << Rate.isNull();
        // Loop while there is a child
        while(!Rate.isNull())
        {
            out << Rate.tagName();
            // Check if the child tag name is COMPONENT
            if (Rate.tagName()=="RATE")
            {
                // Get the first child of the component
                QDomElement Child=Rate.firstChild().toElement();
                out << Child.tagName() + "\n";
                // Read each child of the component node
                while (!Child.isNull())
                {
                    out << Child.tagName();
                    // Read Name and value
                    if (Child.tagName()=="NAME") {
                        out << Child.tagName();
                        if (Child.firstChild().toText().data() == "SpecialMemberRate") {
                            Rate::SpecialMemberRate = Child.firstChild().toText().data().toDouble();
                        }
                        if (Child.firstChild().toText().data() == "DailyRate") {
                            Rate::DailyRate = Child.firstChild().toText().data().toDouble();
                        }

                        if (Child.firstChild().toText().data() == "DailySpecialRate") {
                            Rate::DailySpecialRate = Child.firstChild().toText().data().toDouble();
                        }

                        if (Child.firstChild().toText().data() == "NightRateOnePlayer") {
                            Rate::NightRateOnePlayer = Child.firstChild().toText().data().toDouble();
                        }

                        if (Child.firstChild().toText().data() == "NightRateTwoPlayer") {
                            Rate::NightRateTwoPlayer = Child.firstChild().toText().data().toDouble();
                        }

                        if (Child.firstChild().toText().data() == "NightRateThreePlayer") {
                            Rate::NightRateThreePlayer = Child.firstChild().toText().data().toDouble();
                        }

                        if (Child.firstChild().toText().data() == "NightRateFourPlayer") {
                            Rate::NightRateFourPlayer = Child.firstChild().toText().data().toDouble();
                        }

                        if (Child.firstChild().toText().data() == "NightRateFivePlayer") {
                            Rate::NightRateFivePlayer = Child.firstChild().toText().data().toDouble();
                        }

                        if (Child.firstChild().toText().data() == "NightRateSixPlayer") {
                            Rate::NightRateSixPlayer = Child.firstChild().toText().data().toDouble();
                        }


                    }
                    // Next child
                    Child = Child.nextSibling().toElement();
                }
            }

            // Next component
            Rate = Rate.nextSibling().toElement();
        }
    }
}
