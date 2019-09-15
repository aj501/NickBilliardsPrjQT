#include "tabletransfer.h"
#include "ui_tabletransfer.h"

TableTransfer::TableTransfer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableTransfer)
{
    ui->setupUi(this);

    for(int i = 1; i<=24; i++)
    {
        ui->TransferFrom_comboBox->addItem(QString::number(i));
    }
    QStandardItemModel *modelTableFrom =
          qobject_cast<QStandardItemModel *>(ui->TransferFrom_comboBox->model());
    Q_ASSERT(modelTableFrom != nullptr);

    for(int i = 0; i < 24; i++)
    {
        bool disabledTableFrom = true;
        QStandardItem *itemFrom = modelTableFrom->item(i);
        itemFrom->setFlags(disabledTableFrom ? itemFrom->flags() & ~Qt::ItemIsEnabled
                              : itemFrom->flags() | Qt::ItemIsEnabled);
    }

    for(int i = 1; i<=24; i++)
    {
        ui->TransferTo_comboBox->addItem(QString::number(i));
    }
    this->table_manager = dynamic_cast<TableManager*>(parent);
}

TableTransfer::~TableTransfer()
{
    delete ui;
}

void TableTransfer::UpdateComboBox(Table* table) {
    QStandardItemModel *modelTableFrom =
          qobject_cast<QStandardItemModel *>(ui->TransferFrom_comboBox->model());
    Q_ASSERT(modelTableFrom != nullptr);

    QStandardItemModel *modelTableTo =
          qobject_cast<QStandardItemModel *>(ui->TransferTo_comboBox->model());
    Q_ASSERT(modelTableTo != nullptr);

    if (table->getIsOccupied()) {
        bool disabledTableFrom = false;
        QStandardItem *itemFrom = modelTableFrom->item(table->getId()-1);
        itemFrom->setFlags(disabledTableFrom ? itemFrom->flags() & ~Qt::ItemIsEnabled
                              : itemFrom->flags() | Qt::ItemIsEnabled);
        bool disabledTableTo = true;
        QStandardItem *itemTo = modelTableTo->item(table->getId()-1);
        itemTo->setFlags(disabledTableTo ? itemTo->flags() & ~Qt::ItemIsEnabled
                              : itemTo->flags() | Qt::ItemIsEnabled);
    } else {
        bool disabledTableFrom = true;
        QStandardItem *itemFrom = modelTableFrom->item(table->getId()-1);
        itemFrom->setFlags(disabledTableFrom ? itemFrom->flags() & ~Qt::ItemIsEnabled
                              : itemFrom->flags() | Qt::ItemIsEnabled);
        bool disabledTableTo = false;
        QStandardItem *itemTo = modelTableTo->item(table->getId()-1);
        itemTo->setFlags(disabledTableTo ? itemTo->flags() & ~Qt::ItemIsEnabled
                              : itemTo->flags() | Qt::ItemIsEnabled);
    }
}

void TableTransfer::on_saveButton_pressed() {
    int fromTableIndex = ui->TransferFrom_comboBox->currentText().toInt();
    int toTableIndex = ui->TransferTo_comboBox->currentText().toInt();
    //todo: exception when nothing is selected (no option for choosing table)
    this->table_manager->transferTable(fromTableIndex, toTableIndex);
}
