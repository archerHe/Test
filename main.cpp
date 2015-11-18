
#include <QApplication>
#include <QDesktopWidget>
#include "mainwindow.h"
#include "wizard.h"
#include "launcher_page.h"
#include "hardwarepage.h"
#include "commonpage.h"
#include "otherspage.h"
#include <QMessageBox>
#include <qstyle.h>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //a.setStyle("Fusion");
    qDebug() << QStyleFactory::keys();
    MainWindow w;

    w.resize(1024, 768);
    w.show();



    return a.exec();
}
