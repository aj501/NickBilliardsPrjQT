#ifndef TABLE_H
#define TABLE_H

#include <QGroupBox>
#include "infobox.h"
#include "enums.h"
#include "ui_table.h"

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

    bool getIsInUse() const;
    void setIsInUse(const bool & isInUse);

    double getBill();

protected:
     void mousePressEvent (QMouseEvent *event) override;

private:
    Ui::Table *ui;
    int id;
    TableType type;
    bool isInUse = false;
    bool isIdTaken;

    InfoBox *infobox;

};

#endif // TABLE_H
