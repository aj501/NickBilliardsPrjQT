#include "tablestart.h"
#include "table.h"
#include "ui_tablestart.h"

TableStart::TableStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableStart)
{
    ui->setupUi(this);
    this->table = dynamic_cast<Table*>(parent);

    for (int i = 1; i<=8;i++)
    {
        ui->numPlayersComboBox->addItem(QString::number(i));  
    }
    for (int i = 0; i<=8;i++)
    {
         ui->SenMilitary_comboBox->addItem(QString::number(i));
    }

    ui->tableNumberLabel->setText(QString::number(this->table->getId()));
}

TableStart::~TableStart()
{
    delete ui;
}

void TableStart::on_startButton_pressed() {
    int numPlayers = ui->numPlayersComboBox->currentText().toInt();
    bool isIdTaken = ui->idTakenCheckBox->isChecked();
    this->table->checkIn(numPlayers, isIdTaken, 0.0);
    this->close();
}

void TableStart::on_cancelButton_clicked()
{
    this->close();
}
