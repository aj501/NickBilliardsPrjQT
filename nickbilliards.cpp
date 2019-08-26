#include "nickbilliards.h"
#include "ui_nickbilliards.h"

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

void NickBilliards::on_Table8_linkActivated(const QString &link)
{

}
