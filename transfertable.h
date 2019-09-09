#ifndef TRANSFERTABLE_H
#define TRANSFERTABLE_H

#include <QDialog>

namespace Ui {
class transfertable;
}

class transfertable : public QDialog
{
    Q_OBJECT

public:
    explicit transfertable(QWidget *parent = nullptr);
    ~transfertable();

private slots:
    void on_cancelButton_inTransfer_clicked();

    void on_TransferConfirm_Button_clicked();

private:
    Ui::transfertable *ui;

};

#endif // TRANSFERTABLE_H
