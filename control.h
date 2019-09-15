#ifndef CONTROL_H
#define CONTROL_H

#include <QWidget>
#include <QPainter>
#include "table.h"
#include "tableedit.h"
#include "tablestart.h"

namespace Ui {
class Control;
}

class Control : public QWidget
{
    Q_OBJECT

public:
    explicit Control(QWidget *parent = nullptr);
    ~Control();

    void setType(Table* table);

private:
    Ui::Control *ui;
     void paintEvent(QPaintEvent *) override;
};

#endif // CONTROL_H
