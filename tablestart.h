#ifndef TABLESTART_H
#define TABLESTART_H

#include <QWidget>

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
};

#endif // TABLESTART_H
