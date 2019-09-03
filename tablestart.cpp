#include "tablestart.h"
#include "ui_tablestart.h"

TableStart::TableStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableStart)
{
    ui->setupUi(this);
}

TableStart::~TableStart()
{
    delete ui;
}
