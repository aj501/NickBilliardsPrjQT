#ifndef TABLESTART_H
#define TABLESTART_H

#include <QWidget>
#include "table.h"

namespace Ui {
class TableStart;
}

class TableStart : public QWidget
{
    Q_OBJECT

public:
    explicit TableStart(QWidget *parent = nullptr);

    ~TableStart();

private:
    Ui::TableStart *ui;
    Table* table;

private slots:
    void on_pushButton_pressed();
};

#endif // TABLESTART_H
