#include "utils.h"
#include "rate.h"

namespace Utils {
    double priceCal(const Bill * const bill) {
        double total = 0;
        QTextStream out(stdout);

        QList<QPair<QTime, int>> numPlayers = bill->getAllNumPlayers();
        out << numPlayers.length();
        out << bill->getAllSenMils().length();
        QTime start = bill->getStartTime();
        for (int i = 0; i < numPlayers.length(); i++) {
            QPair<QTime, int> numPlayer = numPlayers[i];
            total += priceCal(start, numPlayer.first, numPlayer.second, bill->getIsMember(), bill->getIsSpecialRate(),
                              bill->getAllSenMils()[i], bill->getTableType());
            if (i == numPlayers.length()-1) {
                total += priceCal(numPlayer.first, bill->getEndTime(), numPlayer.second, bill->getIsMember(), bill->getIsSpecialRate(),
                                  bill->getAllSenMils()[i], bill->getTableType());
            }
            start = numPlayer.first;
        }
        // Discount
        total *= (100-bill->getDiscount())/100;
        return total;
    }

    double priceCal(QTime start, QTime end, int numPlayers, bool isMemberRate, bool isSpecialRate, int numSenMils, TableType tableType) {
        QTextStream out(stdout);
        double total = 0.0;
        if (isMemberRate && tableType == TableType::SevenFooter && isAfterSevenPm(start)) {
            out << 1;
            total = Rate::SpecialMemberRate * numPlayers;
        } else if (isBeforeSevenPm(end)) {
            out << 2;
            double hours = CalculateHours(start, end);
            total = priceCalBefore7pm(numPlayers, isSpecialRate, hours);
        } else if (isAfterSevenPm(start)) {
            out << 3;
            double hours = CalculateHours(start, end);
            total = priceCalAfter7pm(numPlayers, hours);
        } else if (isBeforeSevenPm(start) && isAfterSevenPm(end)) {
            double dayHours = CalculateHours(start, QTime(19, 0, 0));
            double nightHours = CalculateHours(QTime(19, 0, 0), end);
            total = priceCalBefore7pm(numPlayers, isSpecialRate, dayHours) + priceCalAfter7pm(numPlayers, nightHours);
            out << dayHours;
            out << "\n";
            out << nightHours;
        } else {
            return 0;
        }
        // Sen/Mil
        double eachPersonBill = total/numPlayers;
        int numSenMil = numSenMils;
        int numNonSenMil = numPlayers-numSenMil;
        total = eachPersonBill*numNonSenMil +
                eachPersonBill/2*numSenMil;
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
}
