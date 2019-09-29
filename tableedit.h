#ifndef TABLEEDIT_H
#define TABLEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include  "table.h"
#include "utils.h"

class TableTab;
class IdReturnReminder;

namespace Ui {
class TableEdit;
}

class TableEdit : public QWidget
{
    Q_OBJECT

public:
    explicit TableEdit(QWidget *parent = nullptr);
    ~TableEdit();
    int getTableNumber();
    double getTimePlayed();
    double getTimeInDollars();
    void tab();
    void setIdTaken(bool idTaken);
    double getFnBDollar();

private slots:
    void on_editTable_CancelButton_clicked();
    void on_editTable_TabButton_clicked();


    void on_editTable_SaveButton_clicked();

    void on_numPlayers_activated(int index);

    void on_numSenMil_activated(int index);

private:
    Ui::TableEdit *ui;
    Table* table;
};

#endif // TABLEEDIT_H
