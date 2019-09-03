#ifndef TABLEEDIT_H
#define TABLEEDIT_H

#include <QWidget>

namespace Ui {
class TableEdit;
}

class TableEdit : public QWidget
{
    Q_OBJECT

public:
    explicit TableEdit(QWidget *parent = nullptr);
    ~TableEdit();

private:
    Ui::TableEdit *ui;
};

#endif // TABLEEDIT_H
