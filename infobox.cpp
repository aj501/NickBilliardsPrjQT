#include "infobox.h"
#include "ui_infobox.h"

InfoBox::InfoBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InfoBox)
{
    ui->setupUi(this);
}

InfoBox::~InfoBox()
{
    delete ui;
}

