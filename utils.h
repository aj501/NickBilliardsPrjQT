#ifndef UTILS_H
#define UTILS_H

#include "bill.h"

namespace Utils {
    double priceCal(const Bill * const bill);
    double priceCalBefore7pm(int numPlayers, bool isSpecialRate, int numSenMil, double hours,double food, bool isBeforeSevenPm);
    double priceCalAfter7pm(int numPlayers, int numSenMil, double hours,double food);
    bool isBeforeSevenPm(QDateTime time);
    bool isAfterSevenPm(QDateTime time);
    double CalculateHours(QDateTime start, QDateTime end);
}

#endif // UTILS_H
