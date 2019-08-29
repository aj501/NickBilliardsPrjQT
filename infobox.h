#ifndef INFOBOX_H
#define INFOBOX_H

#include <QDialog>

namespace Ui {
class infobox;
}

class infobox : public QDialog
{
    Q_OBJECT

public:
    explicit infobox(QWidget *parent = nullptr);
    ~infobox();

private:
    Ui::infobox *ui;
};

#endif // INFOBOX_H
