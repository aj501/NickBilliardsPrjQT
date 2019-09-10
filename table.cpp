#include "utils.h"
#include "tablemanager.h"
#include "table.h"
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

bool Table::getIsOccupied () const
{
    return is_occupied;
}

void Table::setIsOccupied ( const bool & is_occupied )
{
    this->is_occupied = is_occupied;
}

double Table::getBillTotal() {
    return Utils::priceCal(&bill);
}

TableType Table::getTableType() const{
    return type;
}

void Table::setTableType(const TableType & table_type) {
    this->type = table_type;
}

void Table::checkIn(int numPlayers, bool isIdTaken)  {
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->setIsOccupied(true);
    QDateTime now = QDateTime::currentDateTime();
    QString as = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    this->is_id_taken = isIdTaken;
    this->bill.setStartTime(now);
}

void Table::checkOut() {

}

void Table::mousePressEvent(QMouseEvent *event) {
    ((TableManager*) this->parent())->changeControl(this);
    //this->infobox->exec();
}
