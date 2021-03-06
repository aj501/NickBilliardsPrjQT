#include "tableedit.h"
#include "ui_tableedit.h"
#include "table.h"
#include "tabletab.h"
#include "idreturnreminder.h"


TableEdit::TableEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableEdit)
{
    ui->setupUi(this);
    this->table = dynamic_cast<Table*>(parent);
    ui->tableNumber->setText(QString::number(table->getId()));
    ui->idTaken->setChecked(table->getIsIdTaken());
    ui->isMemberRate->setChecked(table->getBill()->getIsMember());
    ui->isSpecialRate->setChecked(table->getBill()->getIsSpecialRate());
    for (int i=0; i<=6-table->getBill()->getNumPlayers();i++)
    {
        ui->numPlayersAdd->addItem(QString::number(i));
    }
    for (int i=0; i<=table->getBill()->getNumPlayers();i++)
    {
        ui->numPlayersSubtract->addItem(QString::number(i));
    }
    ui->numSenMil->addItem(QString::number(0));
    ui->memo->setPlainText(table->getMemo());
    ui->memo->setFocus();
    for (int i = 0; i<=5;i++)
    {
         ui->discount->addItem(QString::number(i*5) + "%", i*5);
    }
    ui->discount->addItem(QString::number(50) + "%", 50);
    int index = ui->discount->findData(QString::number(table->getBill()->getDiscount()));
    if ( index != -1 ) { // -1 for not found
       ui->discount->setCurrentIndex(index);
    }

    ui->fnb->setValidator(new QDoubleValidator(0, 1000, 2, this));
}

TableEdit::~TableEdit()
{
    delete ui;
}

Table* TableEdit::getTable() const {
    return table;
}

int TableEdit::getTableNumber() {
    return table->getId();
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
    if (table->getIsOccupied()) {
        UpdateTable();
        TableTab* tableTab = new TableTab(this);
        tableTab->setModal(true);
        tableTab->exec();
    } else {
        this->close();
    }
}

void TableEdit::on_editTable_SaveButton_clicked()
{
    if (table->getIsOccupied()) {
        UpdateTable();
    }
    this->close();
}

void TableEdit::UpdateTable() {
    int numPlayers = ui->numPlayersAdd->currentText().toInt() - ui->numPlayersSubtract->currentText().toInt();
    bool isIdTaken = ui->idTaken->isChecked();
    int numSenMil = ui->numSenMil->currentText().toInt();
    bool isMember = ui->isMemberRate->isChecked();
    bool isSpecialRate = ui->isSpecialRate->isChecked();
    int discount = ui->discount->currentData().toInt();
    double fnb = std::max(ui->fnb->text().toDouble(), 0.0);
    QString memo = ui->memo->toPlainText();
    table->update(numPlayers, numSenMil, isIdTaken, isMember, isSpecialRate, fnb, discount, memo);
}

void TableEdit::on_numPlayersAdd_activated(int index)
{
    ui->numSenMil->clear();
    for (int i=0; i<=index; i++)
    {
        ui->numSenMil->addItem(QString::number(i));
    }
}

void TableEdit::on_numSenMil_activated(int index)
{
    if (index != 0) {
        ui->idTaken->setChecked(true);
    } else {
        ui->idTaken->setChecked(false);
    }
}
