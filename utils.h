#ifndef UTILS_H
#define UTILS_H

#include "bill.h"

namespace Utils {
    double priceCal(const Bill * const bill) {
        // if bill->start > 7
        // elif bill->end < 7
        // else priceCal(..)  + priceCal(...)
        return bill->getInitBill();
    }
}

#endif // UTILS_H
