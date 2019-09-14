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

    double getCurrentBill() const;
    void setCurrentBill(const double & current_bill);

private:
    QDateTime start_time;
    QDateTime end_time;
    int num_players;
    double current_bill;
};

#endif // BILL_H
