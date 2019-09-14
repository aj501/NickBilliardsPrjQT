#ifndef TABLE_H
#define TABLE_H

#include <QGroupBox>
#include "ui_table.h"
#include "tabletype.h"
#include "bill.h"

namespace Ui {
class Table;
}

class Table : public QGroupBox
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);
    ~Table() override;

    int getId() const;
    void setId(const int & id);

    bool getIsOccupied() const;
    void setIsOccupied(const bool & isIdTaken);

    bool getIsIdTaken() const;
    void setIsIdTaken(const bool & isIdTaken);

    TableType getTableType() const;
    void setTableType(const TableType & table_type);

    double getBillTotal();

    void checkIn(int numPlayers, bool isIdTaken, double currentBill);
    double checkOut();

    int getNumPlayers();

protected:
     void mousePressEvent (QMouseEvent *event) override;

private:
    Ui::Table *ui;
    int id;
    TableType type;
    bool is_occupied = false;
    bool is_id_taken;
    Bill bill;
};

#endif // TABLE_H
