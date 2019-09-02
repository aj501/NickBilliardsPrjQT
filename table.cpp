#include "table.h"
#include "ui_table.h"
#include "util.h"
#include <QtGui>

Table::Table(QWidget *parent) :
    QGroupBox(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    this->infobox = new InfoBox();
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

double Table::getBill() {
    return Util::priceCal(this->infobox);
}

void Table::mousePressEvent(QMouseEvent *event) {
    this->infobox->setModal(true);
    this->infobox->exec();
}
