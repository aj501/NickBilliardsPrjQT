#include "tablestart.h"
#include "table.h"
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
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::black);
    this->table->setAutoFillBackground(true);
    this->table->setPalette(pal);
    this->table->setIsOccupied(true);
}

void TableStart::on_pushButton_2_clicked()
{
    this->close();
}
