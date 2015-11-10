#include "functionpage.h"
#include "ui_functionpage.h"
#include <QDebug>

FunctionPage::FunctionPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FunctionPage)
{
    ui->setupUi(this);


}

FunctionPage::~FunctionPage()
{
    delete ui;
}
