#include "tableedit.h"
#include "ui_tableedit.h"
#include "transfertable.h"
#include "tabletab.h"


TableEdit::TableEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableEdit)
{
    ui->setupUi(this);
    for (int i = 0; i<=8; i++)
    {
    ui->editPlayerNum_comboBox->addItem(QString::number(i));
    }
}

TableEdit::~TableEdit()
{
    delete ui;
}



void TableEdit::on_editTable_CancelButton_clicked()
{
    this->close();
}




void TableEdit::on_editTable_TransferButton_clicked()
{
    transfertable transfertable;
    transfertable.setModal(true);
    transfertable.exec();
}

void TableEdit::on_editTable_TabButton_clicked()
{
TableTab tabletab;
tabletab.setModal(true);
tabletab.exec();
}

void TableEdit::on_editTable_SaveButton_clicked()
{
    //NEED TO SAVE THE INFORMATION BEFORE CLOSING OUT THE EDITTABLE DIALOG.
    //...
    this->close();
}
