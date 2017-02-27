#include "mainwindow.h"

#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    const int deskW = QApplication::desktop()->width();
    const int deskH = QApplication::desktop()->height();
    w.setFixedSize(1000, 1000*(deskW/deskH));
    w.move((deskW-w.width())/2, (deskH-w.height())/2);
    w.show();

    return a.exec();
}
