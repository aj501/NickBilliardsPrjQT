#include "bill.h"


Bill::Bill()
{

}

void Bill::setStartTime(QDateTime time) {
    start_time = time;
}

int Bill::getNumPlayers() const {
    return num_players;
}

void Bill::setNumPlayers(const int &numPlayers) {
    this->num_players = numPlayers;
}

void Bill::setInitBill(const double &bill) {
    init_bill = bill;
}

double Bill::getInitBill() const {
    return init_bill;
}

