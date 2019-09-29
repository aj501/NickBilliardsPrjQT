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
    ui->TimePlayed->setText(QString::number(tableEdit->getTimePlayed(), 'f', 2));

    double timeInDollars = tableEdit->getTimeInDollars();
    ui->TimeInDollars->setText(QString::number(timeInDollars, 'f', 2));
    ui->FoodNBeverage->setText(QString::number(tableEdit->getFnBDollar(), 'f', 2));

    ui->Total->setText(QString::number(timeInDollars + tableEdit->getFnBDollar(), 'f', 2));

}

TableTab::~TableTab()
{
    delete ui;
}

void TableTab::on_CloseTable_Button_clicked()
{
    tableEdit->tab();
    this->close();
}
