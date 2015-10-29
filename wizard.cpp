#include "wizard.h"
#include "ui_wizard.h"
#include "globaldata.h"
#include <QtCore>
#include <QtGui>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QDir>
#include <QFile>
#include <QFileDialog>



Wizard::Wizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::Wizard)
{
    //ui->setupUi(this);
    prj_home_path = QDir::currentPath();
    initFirstPage();
    addPage(firstPage);



}

Wizard::~Wizard()
{
    delete ui;
}

void Wizard::initFirstPage()
{
    firstPage = new QWizardPage(this);
    text = new QTextBrowser();
    lblPrjName = new QLabel();
    lblPrjPath = new QLabel();
    lePrjName = new QLineEdit();
    lePrjPath = new QLineEdit();
    choosePrjBtn = new QPushButton("...");
    connect(choosePrjBtn,SIGNAL(clicked(bool)),this,SLOT(on_choosePrjBtn_clicked()));
    QHBoxLayout *hBoxLayout = new QHBoxLayout();
    hBoxLayout->addWidget(lePrjPath);
    hBoxLayout->addWidget(choosePrjBtn);

    text->setText(tr("工程文件啊说法是否啊是否撒发是发法人股 共同韩国额外而非玩儿 发是否爱上发发个梵蒂冈的风格地方是个的风格反对公司的分公司的风格方式的根深蒂固的是个是大概发"));
    lblPrjName->setText(tr("工程名"));
    lblPrjPath->setText(tr("Android工程路径"));

    QGridLayout *gridlayout = new QGridLayout();
    gridlayout->addWidget(lblPrjName,0,0);
    gridlayout->addWidget(lePrjName,0,1);
    gridlayout->addWidget(lblPrjPath,1,0);
    gridlayout->addLayout(hBoxLayout,1,1);
    firstPage->setLayout(gridlayout);


}

void Wizard::initSecondPage()
{
    secondPage = new QWizardPage(this);

    QLabel *label = new QLabel("adfafsfddf");
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(label,0,0);
    secondPage->setLayout(layout);
}

void Wizard::createPrj()
{

    QDir *qDir = new QDir();
    if(qDir->exists(lePrjPath->text() + "/wb_project"))
    {
        qDebug() << "this is android root dir";
    }
    else
    {
        qDebug() << "not exist android root dir";
    }

    if(qDir->exists("Project"))
    {
        qDebug() << "Project dir is exist";
    }
    else
    {
        qDir->mkdir("Project");

        qDebug() << "create dir Project";
    }
     qDir->mkdir("Project/" + lePrjName->text());
    QDir::setCurrent("Project/" + lePrjName->text());
    qDebug() << "cur path:"<< QDir::currentPath();
    //bug current path err, next creat prj




}

void Wizard::on_choosePrjBtn_clicked()
{
    QFileDialog *fileDlg = new QFileDialog();
    QString dirName =  fileDlg->getExistingDirectory(this);
    lePrjPath->setText(dirName);
}

void Wizard::accept()
{
      createPrj();



}
