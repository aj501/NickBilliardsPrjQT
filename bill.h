#ifndef BILL_H
#define BILL_H

#include <time.h>
#include <QTime>
#include <QList>
#include <QPair>
#include "tabletype.h"

class Bill
{
public:
    Bill();

    QTime getStartTime ()  const;
    void setStartTime(QTime time);

    QTime getEndTime() const;
    void setEndTime(QTime time);

    int getNumPlayers() const;
    void setNumPlayers(const int & np);

    int getNumSeniorOrMilitary() const;
    void setNumSeniorOrMilitary(const int &);

    bool getIsMember() const;
    void setIsMember(const bool &);

    double getFoodAndBeverage() const;
    void setFoodAndBeverage(const double &);

    double getInitBill() const;
    void setInitBill(const double & bill);

    bool getIsSpecialRate() const;
    void setIsSpecialRate(const bool & rate);

    int getDiscount() const;
    void setDiscount(const int & discount);

    TableType getTableType() const;
    void setTableType(const TableType &);

    QList<QPair<QTime, int>> getAllNumPlayers() const {
        return numPlayers;
    }

private:
    QTime start_time;
    QTime end_time;

    int last_num_players;
    int num_senior_or_military;
    bool is_member;
    double food_and_beverage;
    bool isSpecialRate;
    int discount;

    double init_bill;
    TableType tableType;
    QList<QPair<QTime, int>> numPlayers;
};

#endif // BILL_H
