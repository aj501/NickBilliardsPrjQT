#include "utils.h"

namespace Utils {
    double Utils::priceCal(const Bill * const bill) {
        double total = 0;
        if (bill->getIsMember() && bill->getTableType() == TableType::SevenFooter) {
            if (isBeforeSevenPm(bill->getStartTime())) {

            } else {

            }
        } else if (isBeforeSevenPm(bill->getEndTime())) {
            //total = priceCalBefore7pm(bill->getNumPlayers(), );
        } else if (isAfterSevenPm(bill->getStartTime())) {
            //total = priceCalBefore7pm(bill);
        } else {

        }
        // Apply discount rate
        return total;
    }

    double priceCalBefore7pm(int numPlayers, bool isSpecialRate, int numSenMil, double hours) {

    }

    double priceCalAfter7pm(int numPlayers, int numSenMil, double hours) {

    }

    bool isBeforeSevenPm(QDateTime time) {
        return true;
    }

    bool isAfterSevenPm(QDateTime time) {
        return true;
    }

    double CalculateHours(QDateTime start, QDateTime end) {

    }
}
