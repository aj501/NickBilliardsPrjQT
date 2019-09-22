#include "utils.h"

namespace Utils {
    double Utils::priceCal(const Bill * const bill) {
        double total = 0;
        if (bill->getIsMember() && bill->getTableType() == TableType::SevenFooter) {
            if (isBeforeSevenPm(bill->getStartTime())) {

            } else {
                bill->getStartTime();
            }
        } else if (isBeforeSevenPm(bill->getEndTime())) {
            //total = priceCalBefore7pm(bill->getNumPlayers(), );
        } else if (isAfterSevenPm(bill->getStartTime())) {
            //total = priceCalBefore7pm(bill);
        } else {

        }
        // Apply discount rate
        return total;
    }

    double priceCalBefore7pm(int numPlayers, bool isSpecialRate, int numSenMil, double hours,double food, bool isBeforeSevenPm) {
        double total;
        if(isBeforeSevenPm == true &&  isSpecialRate==true)
        {
            total = (numPlayers*9) + food;
        }
        else if(isSpecialRate==false && isBeforeSevenPm ==true)
        {
            total  = (numPlayers*3)+food;
        }


    }

    double priceCalAfter7pm(int numPlayers, int numSenMil, double hours, double food) {
    double total;
        if(numPlayers<=2 && numSenMil==0)
    {
        total = numPlayers*6*hours;
    }
        else if(numPlayers<=2 && numSenMil==1)
        {
            total = (numPlayers*(6*hours))-((6*hours)/2);
        }
        else if(numPlayers <=2 && numSenMil==2)
        {
            total = (numPlayers*(6*hours))/2;
        }
        if(numPlayers>2 && numPlayers<=4 && numSenMil==0)
        {
            total = numPlayers*5*hours;
        }
        else if (numPlayers>2 && numPlayers<=4 && numSenMil>0)
        {
            for(numSenMil = 1; numSenMil<=4; numSenMil++)
            {
                total = (numPlayers*5*hours)-((numSenMil*hours)/2);
            }

        }
        if(numPlayers>4 && numSenMil==0){
            total = (4*(hours*5))+((numPlayers-4)*(2*hours));
        }
        else if(numPlayers>4 && numSenMil>0)
        {
            for(numSenMil = 1; numSenMil<= numPlayers;numSenMil++)
            {
                double billPerPersonBeforeDiscount =  (4*(hours*5))+((numPlayers-4)*(2*hours))/numPlayers;
                total = (4*(hours*5))+((numPlayers-4)*(2*hours))-((numSenMil*billPerPersonBeforeDiscount)/2);
            }

        }

    }



    bool isBeforeSevenPm(QDateTime time) {
        return true;
    }

    bool isAfterSevenPm(QDateTime time) {
        return true;
    }

    double CalculateHours(QDateTime start, QDateTime end) {

    }
}
