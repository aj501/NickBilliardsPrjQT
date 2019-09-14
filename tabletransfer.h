#ifndef TABLETRANSFER_H
#define TABLETRANSFER_H

#include <QWidget>

namespace Ui {
class TableTransfer;
}

class TableTransfer : public QWidget
{
    Q_OBJECT

public:
    explicit TableTransfer(QWidget *parent = nullptr);
    ~TableTransfer();

private slots:
    void on_SaveTransfer_pushButton_clicked();

private:
    Ui::TableTransfer *ui;
};

#endif // TABLETRANSFER_H
