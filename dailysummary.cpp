#include "dailysummary.h"
#include "ui_dailysummary.h"

dailysummary::dailysummary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dailysummary)
{
    ui->setupUi(this);
}

dailysummary::~dailysummary()
{
    delete ui;
}
