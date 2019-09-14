#include "utils.h"
#include "tablemanager.h"
#include <QtGui>

Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    colormap[0] = "rgb(223, 167, 40)";
    colormap[1] = "rgb(45, 120, 92)";
    colormap[2] = "rgb(224, 59, 62)";
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

bool Table::getIsIdTaken() const
{
    return is_id_taken;
}

void Table::setIsIdTaken(const bool &isIdTaken)
{
    this->is_id_taken = isIdTaken;
}


int Table::getNumPlayers() {
    return this->bill.getNumPlayers();
}

double Table::getBillTotal() {
    return Utils::priceCal(&bill);
}

TableType Table::getTableType() const{
    return type;
}

void Table::setTableType(const TableType & table_type) {
    this->type = table_type;
    this->setBackgroundColor();
}

void Table::checkIn(int numPlayers, bool isIdTaken, double initBill)  {
    this->setBorderColor();
    this->setIsOccupied(true);
    QDateTime now = QDateTime::currentDateTime();
    QString as = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    this->is_id_taken = isIdTaken;
    this->bill.setStartTime(now);
    this->bill.setNumPlayers(numPlayers);
    ((TableManager*) this->parent())->notifyTableOccupied(this);
}

void Table::setBackgroundColor() {
    QString color_setting = "";
    if (this->getTableType() == TableType::NineFooter) {
        color_setting = "border-radius:25px;background-color:" +
                                    colormap[0] + ";";
    } else if (this->getTableType() == TableType::SevenFooter) {
        color_setting = "border-radius:25px;background-color:" +
                                    colormap[1] + ";";
    } else {
        color_setting = "border-radius:25px;background-color:" +
                                    colormap[2] + ";";
    }
    this->setStyleSheet(color_setting);
}

void Table::setBorderColor() {
    QString color_setting = "";
    if (this->getTableType() == TableType::NineFooter) {
        color_setting = "border-radius:25px;background-color:" +
                                    colormap[0] + ";" +
                                    "padding: 1px; border-width: 5px;" +
                                    "border-style: solid; border-color: white;";
    } else if (this->getTableType() == TableType::SevenFooter) {
        color_setting = "border-radius:25px;background-color:" +
                                    colormap[1] + ";" +
                                    "padding: 1px; border-width: 5px;" +
                                    "border-style: solid; border-color: white;";
    } else {
        color_setting = "border-radius:25px;background-color:" +
                                    colormap[2] + ";" +
                                    "padding: 1px; border-width: 5px;" +
                                    "border-style: solid; border-color: white;";
    }
    this->setStyleSheet(color_setting);
    ui->label->setStyleSheet("border-style:none; border-color: blue;");
}



double Table::checkOut() {
    return 0.0;
}

void Table::mousePressEvent(QMouseEvent *event) {
    ((TableManager*) this->parent())->changeControl(this);
    //this->infobox->exec();
}

void Table::paintEvent(QPaintEvent *){
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}
