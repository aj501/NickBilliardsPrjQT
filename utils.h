#ifndef UTILS_H
#define UTILS_H

// Library needed for processing XML documents
#include <QtXml>
// Library needed for processing files
#include <QFile>
#include "bill.h"
#include <QDomNode>

namespace Utils {
    double priceCal(const Bill * const bill);
    double priceCal(QTime start, QTime end, int numPlayers, bool isMemberRate, bool isSpecialRate, int numSenMils, TableType tableType);
    double priceCalBefore6pm(int numPlayers, bool isSpecialRate, double hours);
    double priceCalAfter6pm(int numPlayers, double hours);
    bool isBeforeSixPm(QTime time);
    bool isAfterSixPm(QTime time);
    double CalculateHours(QTime start, QTime end);

}
#endif // UTILS_H
