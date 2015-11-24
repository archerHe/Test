#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wizard.h"
#include "global.h"
#include "texthelper.h"
#include "otherspage.h"
#include <QToolButton>
#include <QMenu>
#include <QSpinBox>
#include <QPushButton>
#include <QListWidget>
#include <QStackedWidget>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QScrollArea>
#include <QDir>
#include <QComboBox>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initMainWindow();

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initDir()
{
    QDir *qDir = new QDir();

    if(qDir->exists("Project"))
    {
        qDebug() <<  "Project is exist.";
    }
    else
    {
        qDir->mkdir("Project");
    }
}

void MainWindow::initMainWindow()
{

    w = new QWidget();
    setCentralWidget(w);

    prj_home_path = QDir::currentPath();
    textEditorPath = "";

#ifdef Q_OS_LINUX
    textEditorPath = Global::geditTE;
#endif

    listItemCommon = new QListWidgetItem();
    QIcon  icon(":/new/img/img/common.png");
    listItemCommon->setIcon(icon);
    listItemCommon->setText("常用修改项");
    listItemCommon->setTextAlignment(Qt::AlignHCenter);

    listItemHardware = new QListWidgetItem();
    listItemHardware->setIcon(QIcon(":/new/img/img/hardware.png"));
    listItemHardware->setText("硬件配置项");
    listItemHardware->setTextAlignment(Qt::AlignHCenter);

    listItemLauncher = new QListWidgetItem();
    listItemLauncher->setIcon(QIcon(":/new/img/img/launcher.png"));
    listItemLauncher->setText("Launcher");
    listItemLauncher->setTextAlignment(Qt::AlignHCenter);

    listitemOthers = new QListWidgetItem();
    listitemOthers->setIcon(QIcon(":/new/img/img/others.png"));
    listitemOthers->setText(tr("其他项"));
    listitemOthers->setTextAlignment(Qt::AlignHCenter);

    listItemFunction = new QListWidgetItem();
    listItemFunction->setIcon(QIcon(":/new/img/img/function.png"));
    listItemFunction->setText(tr("功能补丁"));
    listItemFunction->setTextAlignment(Qt::AlignHCenter);

    listWidget = new QListWidget();
    listWidget->setFlow(QListView::TopToBottom);
    listWidget->setViewMode(QListView::IconMode);
    listWidget->setWrapping(false);
    listWidget->setResizeMode(QListView::Adjust);
    listWidget->setMovement(QListView::Static);
    listWidget->setIconSize(QSize(100, 100));



    listWidget->addItem(listItemCommon);
    listWidget->addItem(listItemHardware);
    listWidget->addItem(listItemLauncher);
    listWidget->addItem(listitemOthers);
    listWidget->addItem(listItemFunction);
    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(&commonPage);
    stackedWidget->addWidget(&hardwarePage);
    stackedWidget->addWidget(&launcher_page);
    stackedWidget->addWidget(&othersPage);
    stackedWidget->addWidget(&functionPage);

    connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));

    QHBoxLayout *main_layout = new QHBoxLayout();
    main_layout->addWidget(listWidget);
    main_layout->addWidget(stackedWidget);
    main_layout->setStretchFactor(listWidget,1);
    main_layout->setStretchFactor(stackedWidget, 7);
    w->setLayout(main_layout);



}

void MainWindow::settingTEOK()
{
    QLineEdit *le_te = wSettingTE->findChild<QLineEdit *>("le_TE");
    qDebug() << "TE:" << le_te->text();
    if(le_te->text() == "")
    {
        return;
    }else
    {
        qDebug() << "TE:" << le_te->text();
        Global::textEditorPath = le_te->text();
    }
}

void MainWindow::settingTECancel()
{
    return;
}


void MainWindow::on_actNew_triggered()
{
    Wizard *wizard = new Wizard(this);
    connect(wizard, SIGNAL(finished(int)), &commonPage, SLOT(loadCfg()));
    connect(wizard, SIGNAL(finished(int)), &hardwarePage, SLOT(loadCfg()));
    connect(wizard, SIGNAL(finished(int)), &othersPage,  SLOT(loadCfg()));

    wizard->exec();
}

void MainWindow::on_actOpen_triggered()
{
    QString prj_open_path = QFileDialog::getOpenFileName(this, "导入现有工程", Global::prj_home_path, "*.prj");
    Global::srcPath = textHelper.readTextStr(prj_open_path, "ProjectPath", "");
    Global::prj_name = textHelper.readTextStr(prj_open_path, "ProjectName", "");
    qDebug() << Global::srcPath << "...." << Global::prj_name;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "custom");
    db.setDatabaseName("Project/" + Global::prj_name + "/" + Global::prj_name + ".db");
    qDebug() << "prj_home :" << "Project/" + Global::prj_name + "/" + Global::prj_name + ".db";
    if(db.open())
    {
        qDebug()<<" mainwindow : create database success";
    }
    else
    {
        qDebug()<<" mainwindow: create fail database";
    }
    commonPage.loadCfg();
    hardwarePage.loadCfg();
    othersPage.loadCfg();
}



void MainWindow::on_actSetingTE_triggered()
{
    /*
    QUiLoader uiLoader;
    QFile file("settingtexteditor.ui");

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "settingtexteditor.ui load fail!";
    }
    wSettingTE = uiLoader.load(&file,this);
    file.close();
    QPushButton *btn_ok = wSettingTE->findChild<QPushButton *>("btn_ok");
    QPushButton *btn_cancel = wSettingTE->findChild<QPushButton *>("btn_cancel");
    connect(btn_ok, SIGNAL(clicked(bool)), this, SLOT(settingTEOK()));

    QUiLoader uiLoader;
    QFile file("settingtexteditor.ui");

    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "settingtexteditor.ui load fail!";
    }
    wSettingTE = uiLoader.load(&file,this);
*/


//    QLineEdit *le_te = wSettingTE->findChild<QLineEdit *>("le_TE");
  //  if(Global::textEditorPath == "")
  //  {
 //       le_te->setText(Global::geditTE);
    //}
    //file.close();
    //wSettingTE->showNormal();
}

void MainWindow::on_actSave_triggered()
{
    commonPage.saveCfg();
    hardwarePage.saveCfg();
    launcher_page.saveCfg();
    othersPage.saveCfg();
}

void MainWindow::on_actClose_triggered()
{
    int ret = QMessageBox::information(this, tr("关闭工程"), tr("是否要关闭当前工程，当前修改选项不会保存"), QMessageBox::Yes, QMessageBox::No);
    if(ret == QMessageBox::Yes)
    {
        commonPage.disableWidget();
        hardwarePage.disableWidget();
        Global::srcPath = "";
        Global::prj_name = "";
    }
    else if(ret == QMessageBox::No)
    {
        return;
    }

}

void MainWindow::on_actExit_triggered()
{
    int ret = QMessageBox::information(this, tr("退出程序"), tr("退出当前程序～～～"), QMessageBox::Yes, QMessageBox::No);
    if(ret == QMessageBox::Yes)
    {
        this->close();
    }
    else if(ret == QMessageBox::No)
    {
        return;
    }
}

void MainWindow::on_actAbout_triggered()
{

}

void MainWindow::on_actDoc_triggered()
{
    QStringList strList;
    strList << Global::prj_home_path + "/doc/help.pdf";
    QProcess::startDetached(Global::evincePdf, strList);
}
