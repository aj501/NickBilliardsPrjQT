#ifndef TABLETRANSFER_H
#define TABLETRANSFER_H

#include <QWidget>
#include "table.h"

namespace Ui {
class TableTransfer;
}

class TableTransfer : public QWidget
{
    Q_OBJECT

public:
    explicit TableTransfer(QWidget *parent = nullptr);
    ~TableTransfer();

    void FromTableComboBoxRemoveTable(Table* table);
    void FromTableComboBoxAddTable(Table* table);
    void ToTableComboBoxRemoveTable(Table* table);
    void ToTableComboBoxAddTable(Table* table);


private slots:
    void on_SaveTransfer_pushButton_clicked();

private:
    Ui::TableTransfer *ui;
};

#endif // TABLETRANSFER_H
