#ifndef TABLETAB_H
#define TABLETAB_H

#include <QDialog>

namespace Ui {
class TableTab;
}

class TableTab : public QDialog
{
    Q_OBJECT

public:
    explicit TableTab(QWidget *parent = nullptr);
    ~TableTab();

private slots:
    void on_CloseTable_Button_clicked();

private:
    Ui::TableTab *ui;
};

#endif // TABLETAB_H
