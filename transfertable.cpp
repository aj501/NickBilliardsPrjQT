#include "transfertable.h"
#include "ui_transfertable.h"
#include "tablestart.h"

transfertable::transfertable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transfertable)
{
    ui->setupUi(this);

    for (int i = 0; i<=24;i++)
    {

    ui->transferTable_comboBox->addItem(QString::number(i));
    }
}

transfertable::~transfertable()
{
    delete ui;
}

void transfertable::on_cancelButton_inTransfer_clicked()
{
    this->close();
}


void transfertable::on_TransferConfirm_Button_clicked()
{
    //on confirming transfer -> take the following actions:
    //1- total tab of the old table then move the total to the new table;
    //2- set the new table to active
    //3- start timing the new table base on the infromation(i.e, number of players) from the previous table
    //Save the information before closing out the transferTable dialog
    this->close();
}

