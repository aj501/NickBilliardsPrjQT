#include "idreturnreminder.h"
#include "ui_idreturnreminder.h"

IdReturnReminder::IdReturnReminder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IdReturnReminder)
{
    ui->setupUi(this);
    this->tableEdit = dynamic_cast<TableEdit*>(parent);
}

IdReturnReminder::~IdReturnReminder()
{
    delete ui;
}

void IdReturnReminder::on_close_clicked()
{
    this->close();
    tableEdit->setIdTaken(false);
}
