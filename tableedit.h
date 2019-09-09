#ifndef TABLEEDIT_H
#define TABLEEDIT_H

#include <QWidget>
#include <QValidator>

namespace Ui {
class TableEdit;
}

class TableEdit : public QWidget
{
    Q_OBJECT

public:
    explicit TableEdit(QWidget *parent = nullptr);
    ~TableEdit();

private slots:
    void on_editTable_CancelButton_clicked();
    void on_editTable_TransferButton_clicked();
    void on_editTable_TabButton_clicked();

    void on_editTable_SaveButton_clicked();

private:
    Ui::TableEdit *ui;
};

#endif // TABLEEDIT_H
