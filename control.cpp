#include <QHBoxLayout>
#include "control.h"
#include "tableedit.h"
#include "tablestart.h"
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

void Control::setType(bool isInUse) {
    if (!isInUse) {
        qDeleteAll(this->children());
        QHBoxLayout *layout = new QHBoxLayout();
        layout->addWidget(new TableStart);
        setLayout(layout);
    } else {
        qDeleteAll(this->children());
        QHBoxLayout *layout = new QHBoxLayout();
        layout->addWidget(new TableEdit);
        setLayout(layout);
    }
}
