#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolButton>
#include <QMenu>
#include <QSpinBox>
#include <QPushButton>
#include <QListWidget>
#include <QStackedWidget>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    w = new QWidget();
    setCentralWidget(w);

    listWidget = new QListWidget();
    listWidget->insertItem(0,"常用项");
    listWidget->insertItem(1,"设置项");
    listWidget->insertItem(2,"Lancher3");

    QLabel *label1 = new QLabel("first page");
    QLabel *label2 = new QLabel("second page");
    QLabel *label3 = new QLabel("third page");
    QTextEdit *te = new QTextEdit();

    stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(label1);
    stackedWidget->addWidget(te);
    stackedWidget->addWidget(label3);
    connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));

    QHBoxLayout *main_layout = new QHBoxLayout();
    main_layout->addWidget(listWidget);
    main_layout->addWidget(stackedWidget);
    main_layout->setStretchFactor(listWidget,1);
    main_layout->setStretchFactor(stackedWidget, 5);
    w->setLayout(main_layout);






}

MainWindow::~MainWindow()
{
    delete ui;
}
