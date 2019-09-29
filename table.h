#ifndef TABLE_H
#define TABLE_H
#include "ui_table.h"
#include "tabletype.h"
#include "bill.h"
#include "tablemanager.h"
#include <QStyleOption>

namespace Ui {
class Table;
}

class Table : public QWidget
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

    QString getMemo() const;
    void setMemo(const QString & memo);

    double calculateCurrentBill();

    void checkIn(int lastNumPlayers,
                 int lastNumSenMils,
                 bool isIdTaken, bool isMember, bool isSpecialRate,
                 double fab, int discount, QString memo);
    void checkOut();
    void update(int numPlayers, int numSenMil,
                bool isIdTaken,bool isMember, bool isSpecialRate,
                double fnb, int discount, QString memo);

    double getFinalBill();

    Bill* getBill() const;

protected:
     void mousePressEvent (QMouseEvent *event) override;

private:
    Ui::Table *ui;
    int id;
    TableType type;
    bool is_occupied = false;
    bool is_id_taken;
    QString memo;
    Bill* bill;
    QString colormap[3];
    void setBackgroundColor();
    void setBorderColor();

    TableManager* table_manager;
    double finalBill = 0;

    void paintEvent(QPaintEvent *) override;
};

#endif // TABLE_H
