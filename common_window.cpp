#include "common_window.h"
#include "ui_common_window.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QScrollArea>
#include <QtGui>
#include <QPushButton>

common_window::common_window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::common_window)
{
    //ui->setupUi(this);

    le_model = new QLineEdit();
    le_bt_name = new QLineEdit();
    le_homepage = new QLineEdit();
    le_sleep_time = new QLineEdit();
    lbl_model = new QLabel(tr("设备型号"));
    lbl_bt_name = new QLabel(tr("蓝牙名"));
    lbl_homepage = new QLabel(tr("浏览器主页"));
    lbl_sleep_time = new QLabel(tr("屏幕待机"));


    //setLayout(layout);
    QVBoxLayout *vLayout = new QVBoxLayout(this);
    QScrollArea *scrollArea = new QScrollArea(this);
    QWidget *scrollWidget = new QWidget(scrollArea);
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollWidget);
    scrollArea->setWidget(scrollWidget);
    setLayout(vLayout);

    scrollLayout->addWidget(new QPushButton());
    //scrollLayout->addWidget(lbl_model, 0, 0);
    //scrollLayout->addWidget(le_model,  0, 1);
   // scrollLayout->addWidget(lbl_bt_name, 1, 0, 1, 1);
   // scrollLayout->addWidget(le_bt_name,  1, 1, 1, 1);

    vLayout->addWidget(scrollArea);




}

common_window::~common_window()
{
    delete ui;
}
