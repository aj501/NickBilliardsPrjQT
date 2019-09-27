#include "tablestart.h"
#include "table.h"
#include "ui_tablestart.h"

TableStart::TableStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableStart)
{
    ui->setupUi(this);
    this->table = dynamic_cast<Table*>(parent);

    for (int i = 1; i<=6;i++)
    {
        ui->numPlayers->addItem(QString::number(i));
    }
    for (int i = 0; i<=6;i++)
    {
         ui->numSenMil->addItem(QString::number(i));
    }
    for (int i = 0; i<=5;i++)
    {
         ui->discount->addItem(QString::number(i*5) + "%", i*5);
    }
    ui->discount->addItem(QString::number(50) + "%", 50);

    ui->tableNumber->setText(QString::number(this->table->getId()));
}

TableStart::~TableStart()
{
    delete ui;
}

void TableStart::on_startButton_pressed() {
    int numPlayers = ui->numPlayers->currentText().toInt();
    bool isIdTaken = ui->idTaken->isChecked();
    int numSenMil = ui->numSenMil->currentText().toInt();
    bool isMember = ui->memberRate->isChecked();
    bool isSpecialRate = ui->specialRate->isChecked();
    int discount = ui->discount->currentData().toInt();
    this->table->checkIn(numPlayers, isIdTaken, numSenMil, isMember, isSpecialRate, 0.0, discount, "");
    this->close();
}

void TableStart::on_cancelButton_clicked()
{
    this->close();
}
