#ifndef BILL_H
#define BILL_H

#include <time.h>
#include <QDateTime>

class Bill
{
public:
    Bill();

    void setStartTime(QDateTime time);

    int getNumPlayers() const;
    void setNumPlayers(const int & num_players);

    double getInitBill() const;
    void setInitBill(const double & bill);

private:
    QDateTime start_time;
    QDateTime end_time;

    int num_players;
    double init_bill;
};

#endif // BILL_H
