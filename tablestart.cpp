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
    for (int i = 0; i<=8;i++)
    {
    ui->comboBox->addItem(QString::number(i));
    }
    for (int i = 0; i<=24;i++)
    {
    ui->comboBox_2->addItem(QString::number(i));
    }


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
