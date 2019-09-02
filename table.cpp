#include "table.h"
#include "ui_table.h"
#include "infobox.h"
#include <QtGui>

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

void Table::setId ( const int & id )
{
    this->id = id;
    ui->label->setText ("Table " + QString::number(id));
}

int Table::getId () const
{
    return id;
}

void Table::mousePressEvent(QMouseEvent *event) {
    InfoBox infobox;
    infobox.setModal(true);
    infobox.exec();
}
