#include "closeappdialog.h"
#include "ui_closeappdialog.h"

CloseAppDialog::CloseAppDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CloseAppDialog)
{
    ui->setupUi(this);
}

CloseAppDialog::~CloseAppDialog()
{
    delete ui;
}

void CloseAppDialog::on_close_clicked()
{
    this->close();
}
