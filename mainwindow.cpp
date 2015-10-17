#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolButton>
#include <QMenu>
#include <QSpinBox>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*
    QToolButton *toolBtn = new QToolButton(this);
    toolBtn->setText("Color");
    QMenu *colorMenu = new QMenu(this);
    colorMenu->addAction("red");
    colorMenu->addAction("White");
    toolBtn->setMenu(colorMenu);
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup);
    ui->mainToolBar->addWidget(toolBtn);

    QSpinBox *spinbox = new QSpinBox(this);
    ui->mainToolBar->addWidget(spinbox);
    */
    //QPushButton *toolsBtn01 = new QPushButton(this);
    //ui->mainToolBar->addWidget(toolsBtn01);


}

MainWindow::~MainWindow()
{
    delete ui;
}
