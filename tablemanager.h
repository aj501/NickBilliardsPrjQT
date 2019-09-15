#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include <QWidget>
#include <vector>

class Table;
class Control;
class TableTransfer;

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
    void notify(Table*);
    void transferTable(int fromTableIndex, int toTableIndex);
private:
    Ui::TableManager *ui;
    Table* tables[24];
    Control* control;
    TableTransfer* table_transfer;
};

#endif // TABLEMANAGER_H
