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


    for (int i=0; i<=8;i++)
    {
        ui->editPlayerNum_comboBox->addItem(QString::number(i));
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
    int numPlayers = ui->editPlayerNum_comboBox->currentText().toInt();
    bool isIdTaken = ui->IDcheckBox->isChecked();
    bool isSenMil = ui->MilCheckBox->isChecked();
    bool isMember = ui->MemberCheckBox->isChecked();
    double fab = ui->FBlineEdit->text().toDouble();
    QString memo = ui->MemoTextEdit->toPlainText();
    table->update(isIdTaken, numPlayers, isSenMil, fab, isMember, memo);
    this->close();
}
