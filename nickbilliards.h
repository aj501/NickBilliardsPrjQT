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

private:
    Ui::NickBilliards *ui;
};

#endif // NICKBILLIARDS_H
