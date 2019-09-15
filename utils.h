#ifndef UTILS_H
#define UTILS_H

#include "bill.h"

namespace Utils {
    double priceCal(const Bill * const bill) {
        return bill->getInitBill();
    }
}
#endif // UTILS_H
