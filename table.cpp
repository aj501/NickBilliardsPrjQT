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

double Table::getCurrentBill() {
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

void Table::checkIn(int lastNumPlayers,
                    int lastNumSenMils, bool isIdTaken,
                    bool isMember, bool isSpecialRate,
                    int discount, QString memo) {
    QTime now = QTime::currentTime();
    setBorderColor();
    ui->startTime->setText(now.toString("hh:mm"));
    is_occupied = true;
    is_id_taken = isIdTaken;
    bill->updateNumPlayers(lastNumPlayers);
    bill->updateNumSeniorOrMilitary(lastNumSenMils);
    bill->setIsMember(isMember);
    bill->setIsSpecialRate(isSpecialRate);
    bill->setDiscount(discount);
    bill->setStartTime(now);
    setMemo(memo);
    table_manager->notify(this);
}

void Table::checkOut() {
    setBackgroundColor();
    ui->startTime->setText("");
    table_manager->UpdateRevenue(this);
    // Reset fields
    bill->reset();
    this->is_occupied = false;
    this->is_id_taken = false;
    table_manager->notify(this);
}

void Table::update(int numPlayers, int numSenMil, bool isIdTaken, bool isMember, bool isSpecialRate,
                   double fnb, int discount, QString memo) {
    bill->updateNumPlayers(bill->getNumPlayers() + numPlayers);
    bill->updateNumSeniorOrMilitary(bill->getNumSeniorOrMilitary() + numSenMil);
    bill->setFoodAndBeverage(this->bill->getFoodAndBeverage() + fnb);
    is_id_taken = isIdTaken;
    bill->setIsMember(isMember);
    bill->setIsSpecialRate(isSpecialRate);
    bill->setDiscount(discount);
    setMemo(memo);
}


void Table::setBackgroundColor() {
    QString color_setting = "";
    if (this->getTableType() == TableType::NineFooter) {
        color_setting = "border-radius:25px;color: rgb(255, 255, 255);"
                        "background-color:" + colormap[0] + ";";
    } else if (this->getTableType() == TableType::SevenFooter) {
        color_setting = "border-radius:25px;color: rgb(255, 255, 255);"
                        "background-color:" + colormap[1] + ";";
    } else {
        color_setting = "border-radius:25px;color: rgb(255, 255, 255);"
                        "background-color:" + colormap[2] + ";";
    }
    this->setStyleSheet(color_setting);
}

void Table::setBorderColor() {
    QString color_setting = "";
    if (this->getTableType() == TableType::NineFooter) {
        color_setting = "border-radius:25px;color: rgb(255, 255, 255);"
                        "background-color:" + colormap[0] + ";" +
                        "padding: 1px; border-width: 5px;" +
                        "border-style: solid; border-color: white;";
    } else if (this->getTableType() == TableType::SevenFooter) {
        color_setting = "border-radius:25px;color: rgb(255, 255, 255);"
                        "background-color:" + colormap[1] + ";" +
                        "padding: 1px; border-width: 5px;" +
                        "border-style: solid; border-color: white;";
    } else {
        color_setting = "border-radius:25px;color: rgb(255, 255, 255);"
                        "background-color:" + colormap[2] + ";" +
                        "padding: 1px; border-width: 5px;" +
                        "border-style: solid; border-color: white;";
    }
    this->setStyleSheet(color_setting);
    ui->label->setStyleSheet("border-style:none;");
    ui->startTime->setStyleSheet("border-style:none;");
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
