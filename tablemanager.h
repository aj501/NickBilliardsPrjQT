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
    void changeControl(Table*);


private:
    Ui::TableManager *ui;
};

#endif // TABLEMANAGER_H
