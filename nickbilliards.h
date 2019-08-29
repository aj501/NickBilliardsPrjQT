#ifndef NICKBILLIARDS_H
#define NICKBILLIARDS_H


#include <QMainWindow>

namespace Ui {
class NickBilliards;
}

class NickBilliards : public QMainWindow
{
    Q_OBJECT

public:
    explicit NickBilliards(QWidget *parent = nullptr);
    ~NickBilliards();

private slots:
    void on_pushButton_clicked();

private slots:
    void on_pushButton_pressed();

private:
    Ui::NickBilliards *ui;

};

#endif // NICKBILLIARDS_H


//




