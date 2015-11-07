#ifndef LAUNCHER_PAGE_H
#define LAUNCHER_PAGE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>

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
    void cpWallpaper(QString wallpaperPath);

private slots:
    void on_btn_wallpaper_choose_clicked();

    void on_btn_icon_site_clicked();

private:
    Ui::Launcher_page *ui;

    QLabel *lbl_wallpaper;
    QLineEdit *le_wallpaper;
    QPushButton *btn_select_wallper;

    QVBoxLayout *vlayout;
    QHBoxLayout *hlayout_wallpaper;
};

#endif // LAUNCHER_PAGE_H
