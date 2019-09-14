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

void Bill::setCurrentBill(const double &bill) {
    current_bill = bill;
}

double Bill::getCurrentBill() const {
    return current_bill;
}
