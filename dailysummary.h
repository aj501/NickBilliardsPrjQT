#ifndef DAILYSUMMARY_H
#define DAILYSUMMARY_H

#include <QWidget>

namespace Ui {
class dailysummary;
}

class dailysummary : public QWidget
{
    Q_OBJECT

public:
    explicit dailysummary(QWidget *parent = nullptr);
    ~dailysummary();

private:
    Ui::dailysummary *ui;
};

#endif // DAILYSUMMARY_H
