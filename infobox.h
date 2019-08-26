#ifndef INFOBOX_H
#define INFOBOX_H

#include <QGroupBox>

namespace Ui {
class InfoBox;
}

class InfoBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit InfoBox(QWidget *parent = nullptr);
    ~InfoBox();

private:
    Ui::InfoBox *ui;
};

#endif // INFOBOX_H
