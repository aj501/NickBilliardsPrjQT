#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include <QWidget>
#include "table.h"

namespace Ui {
class TableManager;
}

class TableManager : public QWidget
{
    Q_OBJECT

public:
    explicit TableManager(QWidget *parent = nullptr);
    ~TableManager();
    void changeControl(Table*);
    void notifyTableOccupied(Table*);
    void transferTable(int fromTableIndex, int toTableIndex);

private:
    Ui::TableManager *ui;
    Table* tables[24];
};

#endif // TABLEMANAGER_H
