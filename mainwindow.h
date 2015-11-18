#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "commonpage.h"
#include "texthelper.h"
#include "launcher_page.h"
#include "hardwarepage.h"
#include "functionpage.h"
#include "otherspage.h"
#include <QMainWindow>
#include <QListWidget>
#include <QStackedWidget>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QScrollArea>
#include <QComboBox>
#include <QListWidgetItem>
#include <QIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initDir();
    void initMainWindow();



private slots:
    void on_actNew_triggered();


private:
    Ui::MainWindow *ui;

    QWidget *w;

    CommonPage      commonPage;
    Launcher_page   launcher_page;
    HardwarePage    hardwarePage;
    FunctionPage    functionPage;
    OthersPage      othersPage;

    TextHelper textHelper;

    QListWidget     *listWidget;
    QStackedWidget  *stackedWidget;
    QScrollArea     *common_page_scrollArea;
    QListWidgetItem *listItemCommon;
    QListWidgetItem *listItemHardware;
    QListWidgetItem *listItemLauncher;
    QListWidgetItem *listItemFunction;
    QListWidgetItem *listitemOthers;

    QString prj_home_path;
};

#endif // MAINWINDOW_H
