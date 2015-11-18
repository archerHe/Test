#include "launcher_page.h"
#include "ui_launcher_page.h"
#include "global.h"
#include <QWidget>
#include <QScrollArea>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QDir>
#include <QFileDialog>
#include <QDebug>


Launcher_page::Launcher_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Launcher_page)
{
    ui->setupUi(this);

    initWidget();
   // disableWidget();
}

Launcher_page::~Launcher_page()
{
    delete ui;
}

void Launcher_page::initWidget()
{
    lbl_wallpaper = new QLabel("添加壁纸路径:");
    lbl_wallpaper->setToolTip("asdfdsfdsf");
    le_wallpaper = new QLineEdit();
    le_wallpaper->setFixedWidth(500);
    btn_select_wallper = new QPushButton("...");
    connect(btn_select_wallper, SIGNAL(clicked(bool)), this, SLOT(btn_wallpaper_choose()));
    lbl_icon_site = new QLabel("桌面图标摆放:");
    btn_icon_site = new QPushButton("打开配置文件");
    btn_icon_site->setFixedWidth(100);
    btn_icon_site->setToolTip("333333333333");

    lbl_def_wallpaper   = new QLabel("默认壁纸:");
    lbl_img         = new QLabel();
    le_def_wallpaper    = new QLineEdit();
    btn_def_wallper     = new QPushButton("...");
    btn_def_wallper->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    lbl_extFiles    = new QLabel("额外打包数据:");
    le_extFiles     = new QLineEdit();
    btn_extFiles    = new QPushButton("选择壁纸");

    hSpacer = new QSpacerItem(600, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
    vSpacer = new QSpacerItem(20, 800, QSizePolicy::Expanding, QSizePolicy::Expanding);

    scroll = new QScrollArea();
    scroll->setWidgetResizable(true);
    scrollWidget = new QWidget(scroll);
    scroll->setWidget(scrollWidget);
    gridLayout = new QGridLayout(scrollWidget);
    gridLayout->addWidget(lbl_wallpaper, 0, 0);
    gridLayout->addWidget(le_wallpaper, 0, 1);
    gridLayout->addWidget(btn_select_wallper, 0, 2);
    gridLayout->addItem(hSpacer, 0, 3);
    gridLayout->addWidget(lbl_icon_site, 1, 0);
    gridLayout->addWidget(btn_icon_site, 1, 1);
    gridLayout->addItem(vSpacer, 2, 0);

    vLayout = new QVBoxLayout(this);
    vLayout->addWidget(scroll);


}

void Launcher_page::disableWidget()
{
    QList<QObject *> list = scrollWidget->children();
    QWidget *w;
    for(int i = 1; i < list.count(); i++)
    {
        w = qobject_cast<QWidget *>(list.at(i));
        w->setDisabled(true);
    }
}

void Launcher_page::enableWidget()
{
    QList<QObject *> list = scrollWidget->children();
    QWidget *w;
    for(int i = 1; i < list.count(); i++)
    {
        w = qobject_cast<QWidget *>(list.at(i));
        w->setEnabled(true);
    }
}

void Launcher_page::cpWallpaper(QString extWallpaperPath)
{

    QString wallpaperPath = Global::srcPath + "/packages/apps/Launcher3/res/drawable-sw600dp-nodpi/";
    QString wallpaperXml =  Global::srcPath + "/packages/apps/Launcher3/res/values/wallpapers.xml";
    //QString wallpaperPath02 = Global::srcPath + "/packages/apps/Launcher3/res/drawable-sw600dp-nodpi/";
    QString overlayLauncher = Global::srcPath + "/" + Global::overlayPath + "/packages/apps/Launcher3";

    QDir *overlayWallpaperDir = new QDir(overlayLauncher + "/res/drawable-sw600dp-nodpi");
    QDir *overlayValuesDir  = new QDir(overlayLauncher + "/res/value
    QDir *dir = new QDir(extWallpaperPath);
    QStringList fileList = dir->entryList();
    for(int i = 2; i < fileList.length(); i++)
    {
        QFile::copy(extWallpaperPath + "/" + fileList[i], wallpaperPath + fileList[i]);
        QString fileName = fileList[i];
        QStringList nameList = fileName.split(".");
        textHelper.addWallpaperXml(wallpaperXml, nameList[0]);

    }


    /*
    QDir *dir = new QDir(extWallpaperPath);
    QStringList fileList = dir->entryList();
    QString overlayLauncher = Global::srcPath + "/" + Global::overlayPath + "/packages/apps/Launcher3/res";
    QString wallpaperOverlay = Global::srcPath + "/" + Global::overlayPath + "/packages/apps/Launcher3/res/drawable-sw600dp-nodpi/";
    QDir *overlay = new QDir(overlayLauncher);
    if(overlay->exists())
    {
        overlay->mkpath("drawable-sw600dp-nodpi");
        for(int i = 2; i < fileList.length(); i++)
        {
            QFile::copy(extWallpaperPath + "/" + fileList[i], wallpaperOverlay + fileList[i]);
            QString fileName = fileList[i];
            QStringList nameList = fileName.split(".");
            qDebug() << nameList[0];
            textHelper.addWallpaperXml(wallpaperXml, nameList[0]);
        }
    }else
    {
        qDebug() << overlayLauncher;
        qDebug() << wallpaperOverlay;
        overlay->mkpath("drawable-sw600dp-nodpi");
    }
    */
}

void Launcher_page::btn_wallpaper_choose()
{
    QFileDialog *fileDlg = new QFileDialog();
    QString wallpaperPath = fileDlg->getExistingDirectory(this);
    le_wallpaper->setText(wallpaperPath);
    cpWallpaper(wallpaperPath);
}


