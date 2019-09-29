#include "tabletab.h"
#include "ui_tabletab.h"
#include "table.h"
#include "tableedit.h"
#include <QWidget>

TableTab::TableTab(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableTab)
{
    ui->setupUi(this);
    tableEdit = dynamic_cast<TableEdit*>(parent);
    ui->TableId->setText(QString::number(tableEdit->getTableNumber()));

    double timePlayed = Utils::CalculateHours(tableEdit->getTable()->getBill()->getStartTime(),
                          QTime::currentTime());
    ui->TimePlayed->setText(QString::number(timePlayed, 'f', 2));
    double timeInDollars = tableEdit->getTable()->getCurrentBill();
    ui->TimeInDollars->setText(QString::number(timeInDollars, 'f', 2));
    double fnb = tableEdit->getTable()->getBill()->getFoodAndBeverage();
    ui->FoodNBeverage->setText(QString::number(fnb, 'f', 2));

    ui->Total->setText(QString::number(timeInDollars + fnb, 'f', 2));
}

TableTab::~TableTab()
{
    delete ui;
}

void TableTab::on_CloseTable_Button_clicked()
{
    if (tableEdit->getTable()->getIsIdTaken()) {
        IdReturnReminder* reminder = new IdReturnReminder(this);
        reminder->setModal(true);
        reminder->exec();
    } else {
        tableEdit->tab();
        this->close();
    }
}

void TableTab::setIdTaken(bool idTaken) {
    tableEdit->getTable()->setIsIdTaken(idTaken);
}
