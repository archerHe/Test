#ifndef OTHERSPAGE_H
#define OTHERSPAGE_H

#include <QWidget>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPixmap>
#include <QImage>
#include <QLineEdit>
#include <QSpacerItem>
#include <QDebug>
#include <QFileDialog>
#include <QDir>

namespace Ui {
class OthersPage;
}

class OthersPage : public QWidget
{
    Q_OBJECT

public:
    explicit OthersPage(QWidget *parent = 0);
    ~OthersPage();

    void initWidget();


public slots:
    void selectWallpaper();

private:
    Ui::OthersPage *ui;

    QScrollArea     *scroll;
    QWidget         *w;
    QGridLayout     *gridLayout;
    QVBoxLayout     *vLayout;

    QLabel          *lbl_img;
    QLabel          *lbl_wallpaper;
    QLineEdit       *le_wallpaper;
    QPushButton     *btn_wallper;
    QLabel          *lbl_extFiles;
    QLineEdit       *le_extFiles;
    QPushButton     *btn_extFiles;



};

#endif // OTHERSPAGE_H
