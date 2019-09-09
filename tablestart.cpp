#include "tablestart.h"
#include "table.h"
#include "infobox.h"
#include "ui_tablestart.h"

TableStart::TableStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableStart)
{
    ui->setupUi(this);
    this->table = dynamic_cast<Table*>(parent);
    ui->comboBox->addItem("1");
    ui->comboBox->addItem("2");
    ui->comboBox->addItem("3");
    ui->comboBox->addItem("4");
    ui->comboBox->addItem("5");
    ui->comboBox->addItem("6");
    ui->comboBox->addItem("7");
    ui->comboBox->addItem("8");

}





TableStart::~TableStart()
{
    delete ui;
}

void TableStart::on_pushButton_pressed() {
    //TODO: Change color here...
   // this->table->setPalette(QPalette::Background green);
    this->table->setIsInUse(1);

}

void TableStart::on_pushButton_2_clicked()
{
    this->close();
}
