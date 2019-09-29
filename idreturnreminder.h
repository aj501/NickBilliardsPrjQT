#ifndef IDRETURNREMINDER_H
#define IDRETURNREMINDER_H

#include <QDialog>
#include "tableedit.h"

namespace Ui {
class IdReturnReminder;
}

class IdReturnReminder : public QDialog
{
    Q_OBJECT

public:
    explicit IdReturnReminder(QWidget *parent = nullptr);
    ~IdReturnReminder();

private slots:
    void on_close_clicked();

private:
    Ui::IdReturnReminder *ui;
    TableEdit* tableEdit;

};

#endif // IDRETURNREMINDER_H
