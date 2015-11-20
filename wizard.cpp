#include "wizard.h"
#include "ui_wizard.h"
#include "mainwindow.h"
#include "global.h"
#include <QtCore>
#include <QtGui>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>


Wizard::Wizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::Wizard)
{
    //ui->setupUi(this);
    prj_home_path = QDir::currentPath();
    initFirstPage();
    addPage(firstPage);


}

Wizard::~Wizard()
{
    delete ui;
}

void Wizard::initFirstPage()
{
    firstPage = new QWizardPage(this);
    lblPrjName = new QLabel();
    lblPrjPath = new QLabel();
    lePrjName = new QLineEdit();
    lePrjPath = new QLineEdit();
    choosePrjBtn = new QPushButton("...");
    connect(choosePrjBtn,SIGNAL(clicked(bool)),this,SLOT(on_choosePrjBtn_clicked()));
    QHBoxLayout *hBoxLayout = new QHBoxLayout();
    hBoxLayout->addWidget(lePrjPath);
    hBoxLayout->addWidget(choosePrjBtn);


    lblPrjName->setText(tr("工程名"));
    lblPrjPath->setText(tr("Android工程路径"));

    QGridLayout *gridlayout = new QGridLayout();
    gridlayout->addWidget(lblPrjName,0,0);
    gridlayout->addWidget(lePrjName,0,1);
    gridlayout->addWidget(lblPrjPath,1,0);
    gridlayout->addLayout(hBoxLayout,1,1);
    firstPage->setLayout(gridlayout);
}

/*
 *暂没用第二页导航
 *
*/
void Wizard::initSecondPage()
{
    secondPage = new QWizardPage(this);

    QLabel *label = new QLabel("adfafsfddf");
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(label,0,0);
    secondPage->setLayout(layout);
}

void Wizard::createPrj()
{


    QDir *qDir = new QDir();
    if(qDir->exists(lePrjPath->text() + "/wb_project"))
    {
        Global::srcPath = lePrjPath->text();
        qDebug() << "this is android root dir : " << Global::srcPath;
    }
    else
    {
        qDebug() << "not exist android root dir";
    }

    if(qDir->exists("Project"))
    {
        qDebug() << "Project dir is exist";
    }
    else
    {
        qDir->mkdir("Project");

        qDebug() << "create dir Project";
    }
     qDir->mkdir("Project/" + lePrjName->text());
    QDir::setCurrent("Project/" + lePrjName->text());

    Global::prj_name = lePrjName->text();

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "custom");
    db.setDatabaseName(lePrjName->text() + ".db");
    if(db.open())
    {
        qDebug()<<" Wizard : create database success";
    }
    else
    {
        qDebug()<<" Wizard: create fail database";
    }

    QSqlQuery query = QSqlQuery(db);
    if(db.tables().contains("common_page"))
    {
        qDebug()<< "table common_page is exist,delete";
        if(query.exec("drop table common_page"))
        {
            qDebug()<<"drop table common_page";
        }
    }
    QString str_exec1 = "create table commonpage("
                       "prj_name varchar,"
                       "model varchar,"
                       "bt_name varchar,"
                        "homepage varchar,"
                        "sleep_time varchar,"
                        "def_language varchar,"
                        "def_country, varchar"
                        "display_id varchar,"
                        "wifi_state integer,"
                        "bt_state integer,"
                        "timezone varchar,"
                        "adb_state integer,"
                        "screenshot_btn integer"
                        ")";

    QString str_exec2 = "create table hardware("
                        "lcd_type integer"
                        "flash_type integer"
                        "back_cam varchar"
                        "front_cam varchar"
                        "simCard integer"
                        ")";

    if(query.exec(str_exec1))
    {
        qDebug() << "create table commonpage success";
    }
    else
    {
        qDebug() << "fail create commonpage table";
    }
    if(query.exec(str_exec2))
    {
        qDebug() << "create table hardware success";
    }
    else
    {
        qDebug() << "fail create hardware table";
    }


    QFile cfg(lePrjName->text() + "." + "prj");
    QTextStream out(&cfg);
    if(!cfg.open(QFile::WriteOnly))
    {

    }
    out << "ProjectName=" << lePrjName->text() << endl;
    out << "ProjectPath=" << lePrjPath->text() << endl;
    cfg.close();
    QDir::setCurrent(Global::prj_home_path);
}

void Wizard::on_choosePrjBtn_clicked()
{
    QFileDialog *fileDlg = new QFileDialog();
    QString dirName =  fileDlg->getExistingDirectory(this);
    lePrjPath->setText(dirName);
}

void Wizard::accept()
{
      createPrj();
      close();

}
