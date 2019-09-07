#include "nickbilliards.h"
#include "ui_nickbilliards.h"
#include "dialog.h"
#include "infobox.h"
NickBilliards::NickBilliards(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NickBilliards)
{
    ui->setupUi(this);
}

NickBilliards::~NickBilliards()
{
    delete ui;
}

void NickBilliards::on_pushButton_clicked()
{

    Dialog Dialog;
    Dialog.setModal(true);
    Dialog.exec();
}

void NickBilliards::on_pushButton_pressed()
{
    infobox infobox;
    infobox.setModal(true);
    infobox.exec();
}
