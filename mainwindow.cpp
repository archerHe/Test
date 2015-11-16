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

    w = new QWidget();
    setCentralWidget(w);

    prj_home_path = QDir::currentPath();

    listWidget = new QListWidget();
    listWidget->insertItem(0, "常用项");
    //listWidget->insertItem(1, "设置项");
    listWidget->insertItem(2, "Launcher");
    listWidget->insertItem(3, "硬件配置");
    listWidget->insertItem(4, "Patch");
    listWidget->insertItem(5, "其他选项");
    listWidget->setSpacing(15);
    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(&commonPage);
   // stackedWidget->addWidget(new QPushButton("adfafa"));
    stackedWidget->addWidget(&launcher_page);
    stackedWidget->addWidget(&hardwarePage);
    stackedWidget->addWidget(&functionPage);
    stackedWidget->addWidget(&othersPage);
    connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));

    QHBoxLayout *main_layout = new QHBoxLayout();
    main_layout->addWidget(listWidget);
    main_layout->addWidget(stackedWidget);
    main_layout->setStretchFactor(listWidget,1);
    main_layout->setStretchFactor(stackedWidget, 5);
    w->setLayout(main_layout);

 //   QMessageBox::about(this, "error", "dsfgfdgfdgfdgfdg");

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

void MainWindow::init_common_page()
{
    le_model = new QLineEdit();
    le_model->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    le_bt_name = new QLineEdit();
    le_bt_name->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    le_homepage = new QLineEdit();
    le_homepage->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    le_homepage->setMinimumWidth(300);
    le_sleep_time = new QLineEdit();
    le_sleep_time->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    le_bright_level = new QLineEdit();
    le_bright_level->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    le_displayId = new QLineEdit();

    cb_language = new QComboBox();
    QList<QString> language_list;
    language_list << "中文简体" << "英语" << "西班牙语";
    QStringList strList =  QStringList(language_list);
    cb_language->addItems(strList);
    cb_wifi_state = new QComboBox();
    cb_wifi_state->addItem("关");
    cb_wifi_state->addItem("开");
    cb_bt_state = new QComboBox();
    cb_bt_state->addItem("关");
    cb_bt_state->addItem("开");
    cb_timezone = new QComboBox();
    cb_date_format = new QComboBox();
    cb_volume = new QComboBox();
    cb_install_non_market = new QComboBox();
    cb_install_non_market->addItem("关");
    cb_install_non_market->addItem("开");
    cb_adb_state = new QComboBox();
    cb_adb_state->addItem("关");
    cb_adb_state->addItem("开");
    cb_screenshot_btn = new QComboBox();
    cb_screenshot_btn->addItem("关");
    cb_screenshot_btn->addItem("开");

    lbl_model = new QLabel(tr("设备型号:"));
    lbl_bt_name = new QLabel(tr("蓝牙名:"));
    lbl_homepage = new QLabel(tr("浏览器主页:"));
    lbl_sleep_time = new QLabel(tr("屏幕待机:"));
    lbl_bright_level = new QLabel(tr("默认亮度:"));
    lbl_language = new QLabel(tr("默认语言:"));
    lbl_displayId = new QLabel(tr("版本号:"));
    lbl_timezone = new QLabel(tr("时区:"));
    lbl_date_format = new QLabel(tr("时间格式:"));
    lbl_volume = new QLabel(tr("默认音量:"));
    lbl_wifi_state = new QLabel(tr("默认wifi:"));
    lbl_bt_state = new QLabel(tr("默认蓝牙:"));
    lbl_install_non_market = new QLabel(tr("未知来源安装:"));
    lbl_adb_state = new QLabel(tr("adb调试模式:"));
    lbl_screenshot_btn = new QLabel(tr("截图按钮:"));


    common_page_w = new QWidget();
    common_page_scrollArea = new QScrollArea(common_page_w);
    QVBoxLayout *common_page_layout = new QVBoxLayout(common_page_w);
    QWidget *common_scrollWidget = new QWidget(common_page_scrollArea);
    QGridLayout *common_scrollLayout = new QGridLayout(common_scrollWidget);

    common_scrollLayout->addWidget(lbl_model, 0, 0);
    common_scrollLayout->addWidget(le_model, 0, 1);
    common_scrollLayout->addWidget(lbl_bt_name, 1, 0);
    common_scrollLayout->addWidget(le_bt_name, 1, 1);
    common_scrollLayout->addWidget(lbl_homepage, 2, 0);
    common_scrollLayout->addWidget(le_homepage, 2, 1);
    common_scrollLayout->addWidget(lbl_sleep_time, 3, 0);
    common_scrollLayout->addWidget(le_sleep_time, 3, 1);
    common_scrollLayout->addWidget(lbl_displayId, 4, 0);
    common_scrollLayout->addWidget(le_displayId, 4, 1);
    common_scrollLayout->addWidget(lbl_language, 5, 0);
    common_scrollLayout->addWidget(cb_language, 5, 1);
    common_scrollLayout->addWidget(lbl_displayId, 6, 0);
    common_scrollLayout->addWidget(le_displayId, 6, 1);
    common_scrollLayout->addWidget(lbl_wifi_state, 7, 0);
    common_scrollLayout->addWidget(cb_wifi_state, 7, 1);
    common_scrollLayout->addWidget(lbl_bt_state, 8, 0);
    common_scrollLayout->addWidget(cb_bt_state, 8, 1);
    common_scrollLayout->addWidget(lbl_timezone, 9, 0);
    common_scrollLayout->addWidget(cb_timezone, 9, 1);
    common_scrollLayout->addWidget(lbl_date_format, 10, 0);
    common_scrollLayout->addWidget(cb_date_format, 10, 1);
    common_scrollLayout->addWidget(lbl_volume, 11, 0);
    common_scrollLayout->addWidget(cb_volume, 11, 1);
    common_scrollLayout->addWidget(lbl_adb_state, 12, 0);
    common_scrollLayout->addWidget(cb_adb_state, 12, 1);
    common_scrollLayout->addWidget(lbl_screenshot_btn, 13, 0);
    common_scrollLayout->addWidget(cb_screenshot_btn, 13, 1);
    common_scrollLayout->setSpacing(15);

    common_page_scrollArea->setWidget(common_scrollWidget);
    common_page_layout->addWidget(common_page_scrollArea);


}

void MainWindow::on_actNew_triggered()
{
    Wizard *wizard = new Wizard(this);
    connect(wizard, SIGNAL(finished(int)), &commonPage, SLOT(loadCfg()));
    connect(wizard, SIGNAL(finished(int)), &hardwarePage, SLOT(loadCfg()));
    wizard->exec();
}
