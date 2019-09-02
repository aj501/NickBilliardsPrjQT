#ifndef TABLE_H
#define TABLE_H

#include <QGroupBox>
#include "infobox.h"
#include "enums.h"

namespace Ui {
class Table;
}

class Table : public QGroupBox
{
    Q_OBJECT

public:
    explicit Table(QWidget *parent = nullptr);
    ~Table() override;

    int getId() const;
    void setId(const int & id);

    double getBill();

protected:
     void mousePressEvent (QMouseEvent *event) override;

private:
    Ui::Table *ui;
    int id;
    TableType type;
    bool isInUse;
    bool isIdTaken;

    InfoBox *infobox;

};

#endif // TABLE_H
