#include "utils.h"
#include "rate.h"

namespace Utils {
    double priceCal(const Bill * const bill) {
        double total = 0;
        QTextStream out(stdout);
        QList<QPair<QTime, int>> numPlayers = bill->getAllNumPlayers();
        QTime start = bill->getStartTime();
        // Special cases: hours not taken into account
        int lastNumPlayers = numPlayers[numPlayers.length()-1].second;
        if (bill->getIsMember() && bill->getTableType() == TableType::SevenFooter && isAfterSixPm(start)) {
            total = Rate::SpecialMemberRate * lastNumPlayers;
        } else if (bill->getIsSpecialRate() && isBeforeSixPm(numPlayers[0].first)
                   && isBeforeSixPm(numPlayers[numPlayers.length()-1].first)) {
            total = Rate::DailySpecialRate * lastNumPlayers;
        } else { // regular cases
            for (int i = 0; i < numPlayers.length(); i++) {
                QPair<QTime, int> numPlayer = numPlayers[i];
                total += priceCal(start, numPlayer.first, numPlayer.second,
                                  bill->getIsMember(), bill->getIsSpecialRate(),
                                  bill->getAllSenMils()[i], bill->getTableType());
                if (i == numPlayers.length()-1) {
                    total += priceCal(numPlayer.first, QTime::currentTime(), numPlayer.second,
                                      bill->getIsMember(), bill->getIsSpecialRate(),
                                      bill->getAllSenMils()[i], bill->getTableType());
                }
                start = numPlayer.first;
            }
        }

        if (isBeforeSixPm(start)) {
            total = std::max(3.0, total);
        }
        if (isAfterSixPm(start)) {
            total = std::max(6.0, total);
        }
        // Discount
        total *= static_cast<double>(100-bill->getDiscount())/100;
        return total;
    }

    double priceCal(QTime start, QTime end, int numPlayers, bool isMemberRate, bool isSpecialRate, int numSenMils, TableType tableType) {
        double total = 0.0;
        if (isBeforeSixPm(end)) {
            double hours = CalculateHours(start, end);
            total = priceCalBefore6pm(numPlayers, isSpecialRate, hours);
        } else if (isAfterSixPm(start)) {
            double hours = CalculateHours(start, end);
            total = priceCalAfter6pm(numPlayers, hours);
        } else if (isBeforeSixPm(start) && isAfterSixPm(end)) {
            double dayHours = CalculateHours(start, QTime(19, 0, 0));
            double nightHours = CalculateHours(QTime(19, 0, 0), end);
            total = priceCalBefore6pm(numPlayers, isSpecialRate, dayHours) +
                    priceCalAfter6pm(numPlayers, nightHours);
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

    double priceCalBefore6pm(int numPlayers, bool isSpecialRate, double hours) {
        //Tuan added conditions for number of players and according rates
        double total = 0.0;
        if (numPlayers == 1){
            total = hours*5;
        } else if (numPlayers > 1){
            total = numPlayers*hours*Rate::DailyRate;
        }
        return total;
    }

    double priceCalAfter6pm(int numPlayers, double hours) {
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

    bool isBeforeSixPm(QTime time) {
        if (time.hour() >= 8 && time.hour() < 18) {
            return true;
        }
        return false;
    }

    bool isAfterSixPm(QTime time) {
        if (time.hour() >= 18 || time.hour() < 4) {
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
