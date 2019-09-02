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

<<<<<<< HEAD

void InfoBox::on_pushButton_2_clicked()
{
=======
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
>>>>>>> d388566ddb65981b428673eb2ece203325c5a20a
}
