#include "tabletransfer.h"
#include "ui_tabletransfer.h"

TableTransfer::TableTransfer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableTransfer)
{
    ui->setupUi(this);

    for(int i = 1; i<=24; i++)
    {
        ui->TransferTo_comboBox->addItem(QString::number(i));
    }
    this->table_manager = dynamic_cast<TableManager*>(parent);

    ui->TransferFrom_comboBox->model()->sort(0);

    proxyTo = new QSortFilterProxyModel();
    proxyTo->setSourceModel(ui->TransferTo_comboBox->model());
    proxyTo->sort(0);
    ui->TransferTo_comboBox->setModel(proxyTo);
}

TableTransfer::~TableTransfer()
{
    delete ui;
}

void TableTransfer::UpdateComboBox(Table* table) {
    if (table->getIsOccupied()) {
        ui->TransferFrom_comboBox->addItem(QString::number(table->getId()));
        //ui->TransferFrom_comboBox->model()->sort(0);
        int index = ui->TransferTo_comboBox->findText(QString::number(table->getId()));
        if ( index != -1 ) { // -1 for not found
           ui->TransferTo_comboBox->removeItem(index);
        }
    } else {
        ui->TransferTo_comboBox->addItem(QString::number(table->getId()));
        //ui->TransferTo_comboBox->model()->sort(0);
        int index = ui->TransferFrom_comboBox->findText(QString::number(table->getId()));
        if ( index != -1 ) { // -1 for not found
           ui->TransferFrom_comboBox->removeItem(index);
        }
    }
}

void TableTransfer::on_saveButton_pressed() {
    int fromTableIndex = ui->TransferFrom_comboBox->currentText().toInt();
    int toTableIndex = ui->TransferTo_comboBox->currentText().toInt();
    //todo: exception when nothing is selected (no option for choosing table)
    this->table_manager->transferTable(fromTableIndex, toTableIndex);
}
