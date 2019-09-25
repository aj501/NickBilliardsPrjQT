#include "bill.h"


Bill::Bill()
{

}

QTime Bill::getStartTime() const {
    return start_time;
}

void Bill::setStartTime(QTime time) {
    start_time = time;
}

QTime Bill::getEndTime() const {
    return end_time;
}

void Bill::setEndTime(QTime time) {
    end_time = time;
}

int Bill::getNumPlayers() const {
    return last_num_players;
}

void Bill::setNumPlayers(const int &np) {
    this->last_num_players = np;
    QTime now = QTime::currentTime();
    QPair<QTime, int> p;
    p.first = now;
    p.second = np;
    numPlayers.push_back(p);
}

int Bill::getNumSeniorOrMilitary() const {
    return num_senior_or_military;
}

void Bill::setNumSeniorOrMilitary(const int & senmil) {
    num_senior_or_military = senmil;
}

bool Bill::getIsMember() const {
    return is_member;
}

void Bill::setIsMember(const bool & mem) {
    is_member = mem;
}

double Bill::getFoodAndBeverage() const {
    return food_and_beverage;
}

void Bill::setFoodAndBeverage(const double & fb) {
    food_and_beverage = fb;
}

TableType Bill::getTableType() const {
    return tableType;
}

void Bill::setTableType(const TableType & type) {
    tableType = type;
}

int Bill::getDiscount() const {
    return discount;
}

void Bill::setDiscount(const int &d) {
    discount = d;
}

bool Bill::getIsSpecialRate() const {
    return isSpecialRate;
}

void Bill::setIsSpecialRate(const bool &rate) {
    isSpecialRate = rate;
}
