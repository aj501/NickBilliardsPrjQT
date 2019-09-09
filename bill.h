#ifndef BILL_H
#define BILL_H

#include <time.h>

class Bill
{
public:
    Bill();

private:
    time_t start_time;
    time_t end_time;
};

#endif // BILL_H
