#ifndef BILL_H
#define BILL_H

#include <time.h>
#include <QDateTime>

namespace  Utils {

};

class Bill
{
public:
    Bill();

    QDateTime getStartTime ()  const;
    void setStartTime(QDateTime time);

    QDateTime getEndTime() const;
    void setEndTime(QDateTime time);

    int getNumPlayers() const;
    void setNumPlayers(const int & num_players);

    bool getIsSeniorOrMilitary() const;
    void setIsSeniorOrMilitary(const bool &);

    bool getIsMember() const;
    void setIsMember(const bool &);

    double getFoodAndBeverage() const;
    void setFoodAndBeverage(const double &);

    double getInitBill() const;
    void setInitBill(const double & bill);

private:
    QDateTime start_time;
    QDateTime end_time;

    int num_players;
    bool is_senior_or_military;
    bool is_member;
    double food_and_beverage;

    double init_bill;
};

#endif // BILL_H
