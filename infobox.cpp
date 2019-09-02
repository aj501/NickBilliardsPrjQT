#include "infobox.h"
#include "ui_infobox.h"

infobox::infobox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infobox)
{
    ui->setupUi(this);
}

infobox::~infobox()
{
    delete ui;
}


void infobox::on_pushButton_2_clicked()
{
}
