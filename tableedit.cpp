#include "tableedit.h"
#include "ui_tableedit.h"
#include "table.h"
#include "tabletab.h"


TableEdit::TableEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableEdit)
{
    ui->setupUi(this);
    this->table = dynamic_cast<Table*>(parent);


    for (int i=0; i<=6;i++)
    {
        ui->numPlayers->addItem(QString::number(i));
        ui->numSenMil->addItem(QString::number(i));
    }

    ui->tableNumberLabel->setText(QString::number(this->table->getId()));
}

TableEdit::~TableEdit()
{
    delete ui;
}

int TableEdit::getTableNumber() {
    return table->getId();
}

double TableEdit::getTimeInDollars() {
    return table->getBillTotal();
}

QString TableEdit::getTimePlayed() {
    return "";
}

void TableEdit::tab() {
    this->table->checkOut();
    this->close();
}

void TableEdit::on_editTable_CancelButton_clicked()
{
    this->close();
}

void TableEdit::on_editTable_TabButton_clicked()
{
    TableTab* tableTab = new TableTab(this);
    tableTab->setModal(true);
    tableTab->exec();
}



void TableEdit::on_editTable_SaveButton_clicked()
{
    int numPlayers = ui->numPlayers->currentText().toInt();
    bool isIdTaken = ui->idTaken->isChecked();
    int numSenMil = ui->numSenMil->currentText().toInt();
    bool isMember = ui->isMemberRate->isChecked();
    bool isSpecialRate = ui->isSpecialRate->isChecked();
    int discount = ui->discount->currentData().toInt();
    double fnb = ui->fnb->text().toDouble();
    QString memo = ui->memo->toPlainText();
    table->update(numPlayers, isIdTaken, numSenMil, isMember, isSpecialRate, fnb, discount, memo);
    this->close();
}
