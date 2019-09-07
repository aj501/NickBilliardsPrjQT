#include "util.h"
#include "tablemanager.h"
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

bool Table::getIsInUse () const
{
    return isInUse;
}

void Table::setIsInUse ( const bool & isInUse )
{
    this->isInUse = isInUse;
}


double Table::getBill() {
    return Util::priceCal(this->infobox);
}

void Table::mousePressEvent(QMouseEvent *event) {
    ((TableManager*) this->parent())->changeControl(this);
    //this->infobox->exec();
}
