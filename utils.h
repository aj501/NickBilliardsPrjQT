#ifndef UTILS_H
#define UTILS_H

#include "bill.h"

namespace Utils {
    double priceCal(const Bill * const bill);
    double priceCalBefore7pm(const Bill * const bill);
    double priceCalAfter7pm(const Bill * const bill);
    bool isBeforeSevenPm(QDateTime time);
    bool isAfterSevenPm(QDateTime time);
}

#endif // UTILS_H
