#ifndef INFOBOX_H
#define INFOBOX_H

#include <QDialog>
#include "enums.h"

namespace Ui {
class InfoBox;
}

class InfoBox : public QDialog
{
    Q_OBJECT

public:
    explicit InfoBox(QWidget *parent = nullptr);
    ~InfoBox();

<<<<<<< HEAD
=======
    time_t getStartTime() const;
    time_t getEndTime() const;
    void setStartTime(const time_t & time);
    void setEndTime(const time_t & time);
>>>>>>> d388566ddb65981b428673eb2ece203325c5a20a

private:
    Ui::InfoBox *ui;
    DiscountType discountType;
    time_t startTime;
    time_t endTime;
};

#endif // INFOBOX_H
