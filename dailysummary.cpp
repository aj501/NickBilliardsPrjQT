#include "dailysummary.h"
#include "ui_dailysummary.h"

dailysummary::dailysummary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dailysummary)
{
    ui->setupUi(this);
}

dailysummary::~dailysummary()
{
    delete ui;
}
