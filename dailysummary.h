#ifndef DAILYSUMMARY_H
#define DAILYSUMMARY_H

#include <QDialog>

namespace Ui {
class dailysummary;
}

class dailysummary : public QDialog
{
    Q_OBJECT

public:
    explicit dailysummary(QWidget *parent = nullptr);
    ~dailysummary();

private:
    Ui::dailysummary *ui;
};

#endif // DAILYSUMMARY_H
