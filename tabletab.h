#ifndef TABLETAB_H
#define TABLETAB_H

#include <QDialog>
#include "tableedit.h"
#include "idreturnreminder.h"


namespace Ui {
class TableTab;
}

class TableTab : public QDialog
{
    Q_OBJECT

public:
    explicit TableTab(QWidget *parent = nullptr);
    ~TableTab();

    void setIdTaken(bool idIdTaken);

private slots:
    void on_CloseTable_Button_clicked();

private:
    Ui::TableTab *ui;
    TableEdit* tableEdit;

};

#endif // TABLETAB_H
