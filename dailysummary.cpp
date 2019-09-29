#include "dailysummary.h"
#include "ui_dailysummary.h"

DailySummary::DailySummary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DailySummary)
{
    ui->setupUi(this);
    this->tableManager = dynamic_cast<TableManager*>(parent);

    double hoursInDollars = tableManager->getTotalHoursInDollars();
    double fnb = tableManager->getTotalFnB();

    ui->hours->setText(QString::number(tableManager->getTotalHours(), 'f', 2));
    ui->hoursInDollars->setText(QString::number(tableManager->getTotalHoursInDollars(), 'f', 2));
    ui->fnb->setText(QString::number(tableManager->getTotalFnB(), 'f', 2));

    ui->revenue->setText(QString::number(hoursInDollars + fnb, 'f', 2));
}

DailySummary::~DailySummary()
{
    delete ui;
}
