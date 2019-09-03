#include "tableedit.h"
#include "ui_tableedit.h"

TableEdit::TableEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableEdit)
{
    ui->setupUi(this);
}

TableEdit::~TableEdit()
{
    delete ui;
}
