#include "hardwarepage.h"
#include "ui_hardwarepage.h"

HardwarePage::HardwarePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HardwarePage)
{
    ui->setupUi(this);

    initWidget();
    disableWidget();




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

    vSpacer = new QSpacerItem(20, 80, QSizePolicy::Expanding, QSizePolicy::Expanding);

    hSpacer = new QSpacerItem(1000, 20, QSizePolicy::Fixed, QSizePolicy::Fixed);

    lbl_screen = new QLabel("LCD类型:");

    lbl_flash = new QLabel("Flash 类型:");
    lbl_back_cam = new QLabel("后置摄像头:");
    lbl_front_cam = new QLabel("前置摄像头:");
    lbl_sim_num  = new QLabel("Sim卡");
    lbl_ddr_fre = new QLabel("DDR频率:");

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
    cb_sim_num = new QComboBox();
    cb_sim_num->addItem("双卡");
    cb_sim_num->addItem("单卡");
    cb_ddr_fre = new QComboBox();
    cb_ddr_fre->addItem("455");
    cb_ddr_fre->addItem("400");

    gridLayout->addWidget(lbl_screen, 0, 0);
    gridLayout->addWidget(cb_screen, 0, 1);
    gridLayout->addItem(hSpacer, 0, 2);
    gridLayout->addWidget(lbl_flash, 1, 0);
    gridLayout->addWidget(cb_flash, 1, 1);
    gridLayout->addWidget(lbl_back_cam, 2, 0);
    gridLayout->addWidget(cb_back_cam, 2, 1);
    gridLayout->addWidget(lbl_front_cam, 3, 0);
    gridLayout->addWidget(cb_front_cam, 3, 1);
    gridLayout->addWidget(lbl_sim_num, 4, 0);
    gridLayout->addWidget(cb_sim_num, 4, 1);
    gridLayout->addItem(vSpacer,  5, 0);
    gridLayout->setSpacing(15);
    vLayout = new QVBoxLayout();

    vLayout->addWidget(scrollArea);

    setLayout(vLayout);


}

void HardwarePage::disableWidget()
{
    QList<QObject *> list = common_scrollWidget->children();

    for(int i = 1; i < list.count(); i++)
    {
        QWidget *w = qobject_cast<QWidget *>(list.at(i));
        w->setDisabled(true);
    }
}

void HardwarePage::enableWidget()
{
    QList<QObject *> list = common_scrollWidget->children();

    for(int i = 1; i < list.count(); i++)
    {
        QWidget *w = qobject_cast<QWidget *>(list.at(i));
        w->setEnabled(true);
    }
}

void HardwarePage::loadCfg()
{
    QString boardCfg = Global::srcPath + "/" + Global::devicePath + "/BoardConfig.mk";
    QString dtsCfg = Global::srcPath + "/" + Global::dtsPath;
    QString kernelCfg = Global::srcPath + "/" + Global::kernelCfgPath;
}
