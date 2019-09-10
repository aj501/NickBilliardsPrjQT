#ifndef BILL_H
#define BILL_H

#include <time.h>
#include <QDateTime>

class Bill
{
public:
    Bill();

    void setStartTime(QDateTime time);

private:
    QDateTime start_time;
    QDateTime end_time;
};

#endif // BILL_H
