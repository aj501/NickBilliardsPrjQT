#include "bill.h"


Bill::Bill()
{

}

QDateTime Bill::getStartTime() const {
    return start_time;
}

void Bill::setStartTime(QDateTime time) {
    start_time = time;
}

QDateTime Bill::getEndTime() const {
    return end_time;
}

void Bill::setEndTime(QDateTime time) {
    end_time = time;
}

int Bill::getNumPlayers() const {
    return num_players;
}

void Bill::setNumPlayers(const int &numPlayers) {
    this->num_players = numPlayers;
}

bool Bill::getIsSeniorOrMilitary() const {
    return is_senior_or_military;
}

void Bill::setIsSeniorOrMilitary(const bool & senmil) {
    is_senior_or_military = senmil;
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

void Bill::setInitBill(const double &bill) {
    init_bill = bill;
}

double Bill::getInitBill() const {
    return init_bill;
}

TableType Bill::getTableType() const {
    return tableType;
}

void Bill::setTableType(const TableType & type) {
    tableType = type;
}



