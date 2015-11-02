#include "loadcfgfromsrc.h"
#include "ui_loadcfgfromsrc.h"

LoadCfgFromSrc::LoadCfgFromSrc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadCfgFromSrc)
{
    ui->setupUi(this);
}

LoadCfgFromSrc::~LoadCfgFromSrc()
{
    delete ui;
}
