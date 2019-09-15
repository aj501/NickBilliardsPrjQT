#ifndef TABLETRANSFER_H
#define TABLETRANSFER_H

#include <QWidget>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
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

    void UpdateComboBox(Table* tables);

private:
    Ui::TableTransfer *ui;
    TableManager* table_manager;
    QSortFilterProxyModel *proxyFrom, *proxyTo;


private slots:
    void on_saveButton_pressed();
};

#endif // TABLETRANSFER_H
