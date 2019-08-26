#include "nickbilliards.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NickBilliards w;
    w.show();

    return a.exec();

    //added this to main
}
