#ifndef CLOSEAPPDIALOG_H
#define CLOSEAPPDIALOG_H

#include <QDialog>

namespace Ui {
class CloseAppDialog;
}

class CloseAppDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CloseAppDialog(QWidget *parent = nullptr);
    ~CloseAppDialog();

private slots:
    void on_close_clicked();

private:
    Ui::CloseAppDialog *ui;
};

#endif // CLOSEAPPDIALOG_H
