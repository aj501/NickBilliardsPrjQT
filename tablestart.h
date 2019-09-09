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
    void on_startButton_pressed();
    void on_cancelButton_clicked();
};

#endif // TABLESTART_H
