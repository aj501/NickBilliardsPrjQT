#include <QHBoxLayout>
#include "control.h"
#include "ui_control.h"

Control::Control(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Control)
{
    ui->setupUi(this);
    QHBoxLayout *layout = new QHBoxLayout();
    setLayout(layout);
}

Control::~Control()
{
    delete ui;
}

void Control::setType(Table* table) {
    if (!table->getIsOccupied()) {
        qDeleteAll(this->children());
        QHBoxLayout *layout = new QHBoxLayout();
        layout->addWidget(new TableStart(table));
        setLayout(layout);
    } else {
        qDeleteAll(this->children());
        QHBoxLayout *layout = new QHBoxLayout();
        layout->addWidget(new TableEdit(table));
        setLayout(layout);
    }
}


void Control::paintEvent(QPaintEvent *){
    QStyleOption opt;
    opt.init(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}
