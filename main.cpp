#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.resize(QApplication::desktop()->width() * 0.8 ,QApplication::desktop()->height() * 0.8);

    w.show();

    return a.exec();
}
