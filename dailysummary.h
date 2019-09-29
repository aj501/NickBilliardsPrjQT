#ifndef DAILYSUMMARY_H
#define DAILYSUMMARY_H

#include <QDialog>
#include "tablemanager.h"

namespace Ui {
class DailySummary;
}

class DailySummary : public QDialog
{
    Q_OBJECT

public:
    explicit DailySummary(QWidget *parent = nullptr);
    ~DailySummary();

private:
    Ui::DailySummary *ui;
    TableManager* tableManager;
};

#endif // DAILYSUMMARY_H
