#include "tabletransfer.h"
#include "ui_tabletransfer.h"

TableTransfer::TableTransfer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableTransfer)
{
    ui->setupUi(this);
    for (int i = 0; i<= 24; i++) {
        ui->toTableComboBox->addItem(QString::number(i));
    }
}

TableTransfer::~TableTransfer()
{
    delete ui;
}

void TableTransfer::FromTableComboBoxRemoveTable(Table* table) {
    ui->fromTableComboBox->removeItem(table->getId());
}

void TableTransfer::FromTableComboBoxAddTable(Table* table) {
    ui->fromTableComboBox->addItem(QString::number(table->getId()));
}

void TableTransfer::ToTableComboBoxRemoveTable(Table* table) {
    ui->toTableComboBox->removeItem(table->getId());
}

void TableTransfer::ToTableComboBoxAddTable(Table* table) {
    ui->toTableComboBox->addItem(QString::number(table->getId()));
}
