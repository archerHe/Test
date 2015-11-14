
#include <QApplication>
#include <QDesktopWidget>
#include "mainwindow.h"
#include "wizard.h"
#include "launcher_page.h"
#include "hardwarepage.h"
#include "commonpage.h"
#include "otherspage.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //Launcher_page h;
   //  CommonPage h;
     //HardwarePage h;

   // OthersPage p;
    //p.show();



    //Wizard *wizard = new Wizard();
    //wizard->show();



    //w.resize(QApplication::desktop()->width() * 0.7 ,QApplication::desktop()->height() * 0.7);
    //w.resize(1024,768);

   w.show();
    //testWidget.resize(1024, 600);
    //testWidget.show();

    return a.exec();
}
