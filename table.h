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

    int getId() const;
    void setId(const int & id);

private:
    Ui::Table *ui;
    int id;
};

#endif // TABLE_H
