#include "testwidget.h"
#include "ui_testwidget.h"
#include <QtWidgets>
#include <QPushButton>

#include <QtGui>
#include <QtCore>

TestWidget::TestWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestWidget)
{
    ui->setupUi(this);



    QPushButton *btn1 = new QPushButton();

    QPushButton *btn2 = new QPushButton();
    QPushButton *btn3 = new QPushButton();
    QPushButton *btn4 = new QPushButton();
    QPushButton *btn5 = new QPushButton();
    QPushButton *btn6 = new QPushButton();
    QPushButton *btn7 = new QPushButton();
    QPushButton *btn8 = new QPushButton();

    QVBoxLayout *layout = new QVBoxLayout();

    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);
    layout->addWidget(btn4);
    layout->addWidget(btn5);
    layout->addWidget(btn6);
    layout->addWidget(btn7);
    layout->addWidget(btn8);
    //setLayout(layout);

    //ui->gridLayout->addWidget(btn1,2,0);

    QScrollBar *scrollBar = new QScrollBar();

    QScrollArea *area = new QScrollArea();
    //area->setVerticalScrollBarPolicy();
    area->setWidget(this);
    area->show();





}

TestWidget::~TestWidget()
{
    delete ui;
}
