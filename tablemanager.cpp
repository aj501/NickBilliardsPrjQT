#include "tablemanager.h"
#include "ui_tablemanager.h"
#include <QDialog>
#include <QApplication>
#include "control.h"
#include "ui_table.h"
#include <QPixmap>
#include "dailysummary.h"
#include "utils.h"


TableManager::TableManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableManager)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: gray;");
    table_transfer = ui->transfer;
    control = ui->control;
    tables[0] = ui->table1;
    tables[1] = ui->table2;
    tables[2] = ui->table3;
    tables[3] = ui->table4;
    tables[4] = ui->table5;
    tables[5] = ui->table6;
    tables[6] = ui->table7;
    tables[7] = ui->table8;
    tables[8] = ui->table9;
    tables[9] = ui->table10;
    tables[10] = ui->table11;
    tables[11] = ui->table12;
    tables[12] = ui->table13;
    tables[13] = ui->table14;
    tables[14] = ui->table15;
    tables[15] = ui->table16;
    tables[16] = ui->table17;
    tables[17] = ui->table18;
    tables[18] = ui->table19;
    tables[19] = ui->table20;
    tables[20] = ui->table21;
    tables[21] = ui->table22;
    tables[22] = ui->table23;
    tables[23] = ui->table24;
    for (int i = 0; i < 24; i++) {
        tables[i]->setId(i+1);
    }
    for (int i = 0; i < 10; i++) {
        tables[i]->setTableType(TableType::NineFooter);
    }

    for (int i = 10; i < 20; i++) {
        tables[i]->setTableType(TableType::SevenFooter);
    }

    for (int i = 20; i < 24; i++) {
        tables[i]->setTableType(TableType::Snooker);
    }

    Utils::LoadRate();
}

TableManager::~TableManager()
{
    delete ui;
}

void TableManager::changeControl(Table* table){
    ((Control*)ui->control)->setType(table);
    //table->setIsInUse(!table->getIsInUse());
}

void TableManager::notify(Table * table) {
    ((TableTransfer*)ui->transfer)->UpdateComboBox(table);
}

void TableManager::transferTable(int fromTableIndex, int toTableIndex) {
    if (fromTableIndex == 0 || toTableIndex == 0) {
        return;
    }
    Table* tableFrom = tables[fromTableIndex-1];
    Table* tableTo = tables[toTableIndex-1];
    tableTo->checkIn(tableFrom->getBill()->getNumPlayers(), tableFrom->getIsIdTaken(),
                     tableFrom->getBill()->getNumSeniorOrMilitary(), tableFrom->getBill()->getIsMember(),
                     tableFrom->getBill()->getIsSpecialRate(),
                     tableFrom->getBill()->getFoodAndBeverage(),
                     tableFrom->getBill()->getDiscount(),
                     tableFrom->getMemo());
}



void TableManager::on_dailySummray_pushButton_clicked()
{
    dailysummary dailysum;
    dailysum.setModal(true);
    dailysum.exec();
}
