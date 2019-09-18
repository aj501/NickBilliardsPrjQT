#ifndef TABLEEDIT_H
#define TABLEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include  "table.h"

namespace Ui {
class TableEdit;
}

class TableEdit : public QWidget
{
    Q_OBJECT

public:
    explicit TableEdit(QWidget *parent = nullptr);
    ~TableEdit();


private slots:
    void on_editTable_CancelButton_clicked();
    void on_editTable_TabButton_clicked();


private:
    Ui::TableEdit *ui;
    Table* table;
};

#endif // TABLEEDIT_H
