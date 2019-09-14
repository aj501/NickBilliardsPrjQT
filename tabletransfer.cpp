#include "tabletransfer.h"
#include "ui_tabletransfer.h"
#include "table.h"

TableTransfer::TableTransfer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableTransfer)
{
    ui->setupUi(this);
    for (int i = 0; i<=24; i++)
    {
        ui->TransferFrom_comboBox->addItem(QString::number(i));
    }
    for(int i = 0; i<=24; i++)
    {
        ui->TransferTo_comboBox->addItem(QString::number(i));
    }
}

TableTransfer::~TableTransfer()
{
    delete ui;
}


void TableTransfer::on_SaveTransfer_pushButton_clicked()
{
    //On clicking save, table needs to transfer to new table, information needs to be saved
    this->close();
}
