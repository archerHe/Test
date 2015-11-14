#include "otherspage.h"
#include "ui_otherspage.h"

OthersPage::OthersPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OthersPage)
{
    ui->setupUi(this);

    initWidget();
    connect(btn_wallper, SIGNAL(clicked(bool)), this, SLOT(selectWallpaper()));
}

OthersPage::~OthersPage()
{
    delete ui;
}

void OthersPage::initWidget()
{
    scroll          = new QScrollArea();
    scroll->setWidgetResizable(true);
    w               = new QWidget(scroll);
    scroll->setWidget(w);
    gridLayout      = new QGridLayout(w);

    QSpacerItem *hSpace = new QSpacerItem(30,20, QSizePolicy::Fixed, QSizePolicy::Fixed);
    lbl_wallpaper   = new QLabel("默认壁纸:");
    lbl_img         = new QLabel();
    le_wallpaper    = new QLineEdit();
    btn_wallper     = new QPushButton("...");
    btn_wallper->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    lbl_extFiles    = new QLabel("额外打包数据:");
    le_extFiles     = new QLineEdit();
    btn_extFiles    = new QPushButton("选择壁纸");

    QImage img;
    img.load("/home/heyuan/Pic/sky01.jpg");
    QImage result = img.scaled(200,200);
    lbl_img->setPixmap(QPixmap::fromImage(result));
    gridLayout->setColumnStretch(1,3);
    gridLayout->addWidget(lbl_wallpaper, 0, 0, 1, 1);
    gridLayout->addWidget(lbl_img, 0, 1, 1, 2);
    gridLayout->addItem(new QSpacerItem(300,20), 0, 2);
    gridLayout->addWidget(le_wallpaper, 1, 0, 1, 3);
    gridLayout->addWidget(btn_wallper, 1, 3, 1, 1);
   // gridLayout->addWidget(lbl_extFiles,2, 0);
   // gridLayout->addWidget(le_extFiles, 2, 1, 1, 3);
    //gridLayout->addWidget(btn_extFiles, 2,3);
    gridLayout->addItem(new QSpacerItem(20,20, QSizePolicy::Expanding, QSizePolicy::Expanding), 3, 0);
    gridLayout->setSpacing(50);
    vLayout         = new QVBoxLayout(this);
    vLayout->addWidget(scroll);
}

void OthersPage::selectWallpaper()
{
    QString def_wallpaper_path = QFileDialog::getOpenFileName(this, "选择默认壁纸", "/home/heyuan", "图片文件(*png *jpg)");
    if(def_wallpaper_path == "")
        return;
    le_wallpaper->setText(def_wallpaper_path);
    QImage img(def_wallpaper_path);
    QImage res = img.scaled(200,200);
    lbl_img->setPixmap(QPixmap::fromImage(res));
}
