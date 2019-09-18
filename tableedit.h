#ifndef TABLEEDIT_H
#define TABLEEDIT_H

#include <QWidget>
#include <QValidator>
#include  "table.h"

class TableTab;

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
    QString getTimePlayed();
    double getTimeInDollars();
    void tab();

private slots:
    void on_editTable_CancelButton_clicked();
    void on_editTable_TabButton_clicked();
    void on_editTable_SaveButton_clicked();

private:
    Ui::TableEdit *ui;
    Table* table;
};

#endif // TABLEEDIT_H
