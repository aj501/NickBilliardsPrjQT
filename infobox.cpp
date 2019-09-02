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

time_t InfoBox::getStartTime() const
{
    return startTime;
}

time_t InfoBox::getEndTime() const
{
    return endTime;
}

void InfoBox::setStartTime(const time_t & time)
{
    this->startTime = time;
}

void InfoBox::setEndTime(const time_t & time)
{
    this->startTime = time;
}
