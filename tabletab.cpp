#include "tabletab.h"
#include "ui_tabletab.h"
#include "tablestart.h"
#include "tableedit.h"

TableTab::TableTab(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableTab)
{
    ui->setupUi(this);
    tableEdit = dynamic_cast<TableEdit*>(parent);
    ui->TableId->setText(QString::number(tableEdit->getTableNumber()));
    ui->TimePlayed->setText(tableEdit->getTimePlayed());
    ui->TimeInDollars->setText(QString::number(tableEdit->getTimeInDollars()));

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
