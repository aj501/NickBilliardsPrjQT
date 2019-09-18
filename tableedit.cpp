#include "tableedit.h"
#include "ui_tableedit.h"
#include "tabletab.h"
#include "table.h"
#include "tablestart.h"



TableEdit::TableEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableEdit)
{
    ui->setupUi(this);
    this->table = dynamic_cast<Table*>(parent);

    for (int i = 0; i<=8;i++)
    {
        ui->editPlayerNum_comboBox->addItem(QString::number(i));
    }
    ui->tableNumberLabel->setText(QString::number(this->table->getId()));
}

TableEdit::~TableEdit()
{
    delete ui;
}

void TableEdit::on_editTable_CancelButton_clicked()
{
    this->close();
}

void TableEdit::on_editTable_TabButton_clicked()
{
    TableTab tabletab;
    tabletab.setModal(true);
    tabletab.exec();
}


