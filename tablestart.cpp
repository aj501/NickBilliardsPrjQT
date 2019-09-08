#include "tablestart.h"
#include "table.h"
#include "infobox.h"
#include "ui_tablestart.h"

TableStart::TableStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableStart)
{
    ui->setupUi(this);
    this->table = dynamic_cast<Table*>(parent);
}

TableStart::~TableStart()
{
    delete ui;
}

void TableStart::on_pushButton_pressed() {
    // Change color here...
    this->table->setId(31);
}
