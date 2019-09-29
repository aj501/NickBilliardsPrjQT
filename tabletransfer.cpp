#include "tabletransfer.h"
#include "ui_tabletransfer.h"

TableTransfer::TableTransfer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableTransfer)
{
    ui->setupUi(this);

    for(int i = 1; i<=24; i++)
    {
        ui->TransferTo_comboBox->addItem(convertToIDString(i));
    }
    this->table_manager = dynamic_cast<TableManager*>(parent);
}

TableTransfer::~TableTransfer()
{
    delete ui;
}

void TableTransfer::UpdateComboBox(Table* table) {
    QString id = convertToIDString(table->getId());
    if (table->getIsOccupied()) {
        ui->TransferFrom_comboBox->addItem(id);
        ui->TransferFrom_comboBox->model()->sort(0);
        int index = ui->TransferTo_comboBox->findText(id);
        if ( index != -1 ) { // -1 for not found
           ui->TransferTo_comboBox->removeItem(index);
        }
    } else {
        ui->TransferTo_comboBox->addItem(id);
        ui->TransferTo_comboBox->model()->sort(0);
        int index = ui->TransferFrom_comboBox->findText(id);
        if ( index != -1 ) { // -1 for not found
           ui->TransferFrom_comboBox->removeItem(index);
        }
    }
}

QString TableTransfer::convertToIDString(int id) {
    // This function helps store id in order by filling zeros before
    // id numbers that are less than 10
    // This won't work if number of tables > 99
    QString idStr = "";
    if (id < 10) {
        idStr = " " + QString::number(id);
    } else {
        idStr = QString::number(id);
    }
    return idStr;
}

void TableTransfer::on_saveButton_pressed() {
    int fromTableIndex = ui->TransferFrom_comboBox->currentText().toInt();
    int toTableIndex = ui->TransferTo_comboBox->currentText().toInt();
    this->table_manager->transferTable(fromTableIndex, toTableIndex);
}
