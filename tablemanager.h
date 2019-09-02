#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include <QWidget>
#include "table.h"

namespace Ui {
class TableManager;
}

class TableManager : public QWidget
{
    Q_OBJECT

public:
    explicit TableManager(QWidget *parent = nullptr);
    ~TableManager();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_pressed();

private:
    Ui::TableManager *ui;
};

#endif // TABLEMANAGER_H
