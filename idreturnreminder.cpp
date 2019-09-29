#include "idreturnreminder.h"
#include "ui_idreturnreminder.h"

IdReturnReminder::IdReturnReminder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IdReturnReminder)
{
    ui->setupUi(this);
    this->tableTab = dynamic_cast<TableTab*>(parent);
}

IdReturnReminder::~IdReturnReminder()
{
    delete ui;
}

void IdReturnReminder::on_close_clicked()
{
    tableTab->setIdTaken(false);
    this->close();
}
