#include "table.h"
#include "ui_table.h"

Table::Table(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
}

Table::~Table()
{
    delete ui;
}
