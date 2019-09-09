#include "tablemanager.h"
#include "ui_tablemanager.h"
#include <QDialog>
#include <QApplication>
#include "table.h"
#include "control.h"
#include "ui_table.h"

TableManager::TableManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TableManager)
{
    ui->setupUi(this);
    ui->table1->setId(1);
    ui->table2->setId(2);
    ui->table3->setId(3);
    ui->table4->setId(4);
    ui->table5->setId(5);
    ui->table6->setId(6);
    ui->table7->setId(7);
    ui->table8->setId(8);
    ui->table9->setId(9);
    ui->table10->setId(10);
    ui->table11->setId(11);
    ui->table12->setId(12);
    ui->table13->setId(13);
    ui->table14->setId(14);
    ui->table15->setId(15);
    ui->table16->setId(16);
    ui->table17->setId(17);
    ui->table18->setId(18);
    ui->table19->setId(19);
    ui->table20->setId(20);
    ui->table21->setId(21);
    ui->table22->setId(22);
    ui->table23->setId(23);
    ui->table24->setId(24);

    // Set up table type
    ui->table1->setTableType(TableType::NineFooter);
    ui->table2->setTableType(TableType::NineFooter);
    ui->table3->setTableType(TableType::NineFooter);
    ui->table4->setTableType(TableType::NineFooter);
    ui->table5->setTableType(TableType::NineFooter);
    ui->table6->setTableType(TableType::NineFooter);
    ui->table7->setTableType(TableType::NineFooter);
    ui->table8->setTableType(TableType::NineFooter);
    ui->table9->setTableType(TableType::NineFooter);
    ui->table10->setTableType(TableType::NineFooter);
    ui->table11->setTableType(TableType::SevenFooter);
    ui->table12->setTableType(TableType::SevenFooter);
    ui->table13->setTableType(TableType::SevenFooter);
    ui->table14->setTableType(TableType::SevenFooter);
    ui->table15->setTableType(TableType::SevenFooter);
    ui->table16->setTableType(TableType::SevenFooter);
    ui->table17->setTableType(TableType::SevenFooter);
    ui->table18->setTableType(TableType::SevenFooter);
    ui->table19->setTableType(TableType::SevenFooter);
    ui->table20->setTableType(TableType::SevenFooter);
    ui->table21->setTableType(TableType::Snooker);
    ui->table22->setTableType(TableType::Snooker);
    ui->table23->setTableType(TableType::Snooker);
    ui->table24->setTableType(TableType::Snooker);
}

TableManager::~TableManager()
{
    delete ui;
}

void TableManager::changeControl(Table* table){
    ((Control*)ui->control)->setType(table);
    //table->setIsInUse(!table->getIsInUse());
}
