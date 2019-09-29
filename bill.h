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

    int getNumPlayers() const;
    void updateNumPlayers(const int & np);

    int getNumSeniorOrMilitary() const;
    void updateNumSeniorOrMilitary(const int &);

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

    QList<int> getAllSenMils() const {
        return numSenMils;
    }

    void setAllNumPlayers(const QList<QPair<QTime, int>> allPlayers) {
        numPlayers = allPlayers;
    }

    void setAllNumSenMils(const QList<int> allSenMils) {
        numSenMils = allSenMils;
    }

    void reset() {
        setStartTime(QTime::currentTime());
        setFoodAndBeverage(0.0);
        setIsMember(false);
        setIsSpecialRate(false);
        setDiscount(0);
        last_num_players = 0;
        last_num_senior_or_military = 0;
        numPlayers.clear();
        numSenMils.clear();
    }

private:
    QTime start_time;
    int last_num_players;
    int last_num_senior_or_military;
    bool is_member;
    double food_and_beverage;
    bool isSpecialRate;
    int discount;

    double init_bill;
    TableType tableType;
    QList<QPair<QTime, int>> numPlayers;
    QList<int> numSenMils;
};

#endif // BILL_H
