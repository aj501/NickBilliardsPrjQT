#include "table.h"
#include "utils.h"
#include <QtGui>

Table::Table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Table)
{
    ui->setupUi(this);
    colormap[0] = "rgb(223, 167, 40)";
    colormap[1] = "rgb(45, 120, 92)";
    colormap[2] = "rgb(224, 59, 62)";
    this->table_manager = dynamic_cast<TableManager*>(parent);
    this->bill = new Bill();
    bill->setTableType(this->type);
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

double Table::getBillTotal() {
    return Utils::priceCal(bill);
}

TableType Table::getTableType() const{
    return type;
}

Bill* Table::getBill() const {
    return  bill;
}

void Table::setTableType(const TableType & table_type) {
    this->type = table_type;
    this->setBackgroundColor();
}

QString Table::getMemo() const {
    return memo;
}

void Table::setMemo(const QString & m){
    memo = m;
}

void Table::checkIn(int numPlayers, bool isIdTaken, int numSenMil, bool isMember, bool isSpecialRate,
                                 double fnb, int discount, QString memo) {
    setBorderColor();
    setIsOccupied(true);
    QDateTime now = QDateTime::currentDateTime();
    bill->setNumPlayers(numPlayers);
    is_id_taken = isIdTaken;
    bill->setNumSeniorOrMilitary(numSenMil);
    bill->setIsMember(isMember);
    bill->setIsSpecialRate(isSpecialRate);
    bill->setFoodAndBeverage(fnb);
    bill->setDiscount(discount);
    bill->setStartTime(now);
    bill->setEndTime(now);
    setMemo(memo);
    table_manager->notify(this);
}


double Table::checkOut() {
    setBackgroundColor();
    this->bill->setEndTime(QDateTime::currentDateTime());
    double total = getBillTotal();
    // Reset fields
    this->is_occupied = false;
    this->is_id_taken = false;
    this->bill->setStartTime(QDateTime::currentDateTime());
    this->bill->setNumPlayers(0);
    this->bill->setFoodAndBeverage(0.0);
    this->bill->setIsMember(false);
    table_manager->notify(this);
    return total;
}

void Table::update(int numPlayers, bool isIdTaken, int numSenMil, bool isMember, bool isSpecialRate,
                   double fnb, int discount, QString memo) {
    bill->setNumPlayers(this->bill->getNumPlayers() + numPlayers);
    bill->setFoodAndBeverage(this->bill->getFoodAndBeverage() + fnb);
    is_id_taken = isIdTaken;
    bill->setNumSeniorOrMilitary(numSenMil);
    bill->setIsMember(isMember);
    bill->setIsSpecialRate(isSpecialRate);
    bill->setFoodAndBeverage(fnb);
    bill->setDiscount(discount);
    setMemo(memo);
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

void Table::mousePressEvent(QMouseEvent *) {
    table_manager->changeControl(this);
}

void Table::paintEvent(QPaintEvent *){
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}
