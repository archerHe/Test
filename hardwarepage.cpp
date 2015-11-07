#include "hardwarepage.h"
#include "ui_hardwarepage.h"

HardwarePage::HardwarePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HardwarePage)
{
    ui->setupUi(this);

    initWidget();
}

HardwarePage::~HardwarePage()
{
    delete ui;
}

void HardwarePage::initWidget()
{
    scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    common_scrollWidget = new QWidget(scrollArea);
    scrollArea->setWidget(common_scrollWidget);
    gridLayout = new QGridLayout(common_scrollWidget);

    lbl_screen = new QLabel("LCD类型:");
    lbl_flash = new QLabel("Flash 类型:");
    lbl_back_cam = new QLabel("后置摄像头:");
    lbl_front_cam = new QLabel("前置摄像头:");

    cb_screen = new QComboBox();
    cb_screen->addItem("TN");
    cb_screen->addItem("IPS");
    cb_flash = new QComboBox();
    cb_flash->addItem("Nand");
    cb_flash->addItem("Emmc");
    cb_back_cam = new QComboBox();
    cb_back_cam->addItem("OV2680");
    cb_back_cam->addItem("GC2035");
    cb_front_cam = new QComboBox();
    cb_front_cam->addItem("SP0310");
    cb_front_cam->addItem("GC0305");

    gridLayout->addWidget(lbl_screen, 0, 0);
    gridLayout->addWidget(cb_screen, 0, 1);
    gridLayout->addWidget(lbl_flash, 1, 0);
    gridLayout->addWidget(cb_flash, 1, 1);
    gridLayout->addWidget(lbl_back_cam, 2, 0);
    gridLayout->addWidget(cb_back_cam, 2, 1);
    gridLayout->addWidget(lbl_front_cam, 3, 0);
    gridLayout->addWidget(cb_front_cam, 3, 1);
    gridLayout->setSpacing(15);
    vLayout = new QVBoxLayout();

    vLayout->addWidget(scrollArea);
    setLayout(vLayout);




}
