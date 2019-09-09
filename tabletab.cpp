#include "tabletab.h"
#include "ui_tabletab.h"
#include "tablestart.h"

TableTab::TableTab(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableTab)
{
    ui->setupUi(this);
}

TableTab::~TableTab()
{
    delete ui;
}

void TableTab::on_CloseTable_Button_clicked()
{
    //NEED TO SET THE CURRENT TABLE TO ACTIVE AGAIN BEFORE CLOSING OUT THE TTAB DIALOG. DONT KNOW HOW YET.
    this->close();
}
