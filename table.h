#ifndef TABLE_H
#define TABLE_H

#include <QGroupBox>

namespace Ui {
class Table;
}

class Table : public QGroupBox
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);
    ~Table();

private:
    Ui::Table *ui;
};

#endif // TABLE_H
