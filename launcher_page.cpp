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



}

Launcher_page::~Launcher_page()
{
    delete ui;
}

void Launcher_page::initWidget()
{
    lbl_wallpaper = new QLabel("WallpaperPath:");
    le_wallpaper = new QLineEdit();
    btn_select_wallper = new QPushButton("...");


}

void Launcher_page::cpWallpaper(QString extWallpaperPath)
{
    QString wallpaperPath = Global::srcPath + "/packages/apps/Launcher3/res/drawable-sw600dp-nodpi/";
    QDir *dir = new QDir(extWallpaperPath);
    QStringList fileList = dir->entryList();
    for(int i = 2; i < fileList.length(); i++)
    {
        QFile::copy(extWallpaperPath + "/" + fileList[i], wallpaperPath + fileList[i]);
        // qDebug() << extWallpaperPath + "/" + fileList[i] << endl << wallpaperPath + fileList[i];
    }
   // qDebug() << fileList;
}

void Launcher_page::on_btn_wallpaper_choose_clicked()
{
    QFileDialog *fileDlg = new QFileDialog();
    QString wallpaperPath = fileDlg->getExistingDirectory(this);
    ui->le_wallpaperPath->setText(wallpaperPath);
   // cpWallpaper(wallpaperPath);
}

void Launcher_page::on_btn_icon_site_clicked()
{

}
