#include "tablestart.h"
#include "table.h"
#include "ui_tablestart.h"

TableStart::TableStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableStart)
{
    ui->setupUi(this);
    this->table = dynamic_cast<Table*>(parent);

    for (int i = 0; i<=8;i++)
    {
    ui->PlayerNum_ComboBox->addItem(QString::number(i));
    }
}

TableStart::~TableStart()
{
    delete ui;
}

void TableStart::on_startButton_pressed() {
    //Color change using Qpallete
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::black);
    this->table->setAutoFillBackground(true);
    this->table->setPalette(pal);
    this->table->setIsOccupied(true);

    //After start is clicked, it starts timing the table, save the info and also close out the current window
    this->close();
}

void TableStart::on_cancelButton_clicked()
{
    this->close();
}
