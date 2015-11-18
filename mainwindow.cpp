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
bool Wizard::wizardAcceptFlag = false;

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


void MainWindow::on_actNew_triggered()
{
    Wizard *wizard = new Wizard(this);
    connect(wizard, SIGNAL(finished(int)), &commonPage, SLOT(loadCfg()));
    connect(wizard, SIGNAL(finished(int)), &hardwarePage, SLOT(loadCfg()));
    wizard->exec();
}
