#ifndef LAUNCHER_PAGE_H
#define LAUNCHER_PAGE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QScrollArea>
#include <QSpacerItem>
#include "global.h"
#include "texthelper.h"

namespace Ui {
class Launcher_page;
}

class Launcher_page : public QWidget
{
    Q_OBJECT

public:
    explicit Launcher_page(QWidget *parent = 0);
    ~Launcher_page();

    void initWidget();
    void disableWidget();
    void enableWidget();
    void cpWallpaper(QString wallpaperPath);


private slots:
    void btn_wallpaper_choose();


private:
    Ui::Launcher_page *ui;

    TextHelper  textHelper;

    QSpacerItem *vSpacer;
    QSpacerItem *hSpacer;

    QLabel *lbl_wallpaper;
    QLineEdit *le_wallpaper;
    QPushButton *btn_select_wallper;
    QLabel *lbl_icon_site;
    QPushButton *btn_icon_site;

    QLabel          *lbl_img;
    QLabel          *lbl_def_wallpaper;
    QLineEdit       *le_def_wallpaper;
    QPushButton     *btn_def_wallper;
    QLabel          *lbl_extFiles;
    QLineEdit       *le_extFiles;
    QPushButton     *btn_extFiles;

    QScrollArea *scroll;
    QWidget *scrollWidget;
    QGridLayout *gridLayout;

    QVBoxLayout *vLayout;
};

#endif // LAUNCHER_PAGE_H
