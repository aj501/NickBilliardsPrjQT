#include "tablemanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TableManager w;
    w.showMaximized();
    return a.exec();
}
