#include "tabletransfer.h"
#include "ui_tabletransfer.h"

TableTransfer::TableTransfer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableTransfer)
{
    ui->setupUi(this);
}

TableTransfer::~TableTransfer()
{
    delete ui;
}
