#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "common_window.h"
#include "texthelper.h"
#include <QMainWindow>
#include <QListWidget>
#include <QStackedWidget>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QScrollArea>
#include <QComboBox>


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
    void init_common_page();

    static bool wizardAcceptFlag;

public slots:
    void loadCfg();

private slots:
    void on_actNew_triggered();


private:
    Ui::MainWindow *ui;

    TextHelper textHelper;

    QListWidget     *listWidget;
    QStackedWidget  *stackedWidget;
    QScrollArea     *common_page_scrollArea;
    QGridLayout *layout;
    QLabel *lbl_model;
    QLineEdit *le_model;
    QLabel *lbl_bt_name;
    QLineEdit *le_bt_name;
    QLabel *lbl_sleep_time;
    QLineEdit *le_sleep_time;
    QLabel *lbl_homepage;
    QLineEdit *le_homepage;
    QLabel *lbl_bright_level;
    QLineEdit *le_bright_level;
    QLabel *lbl_displayId;
    QLineEdit *le_displayId;
    QLabel *lbl_brand;
    QLineEdit *le_brand;
    QLabel *lbl_language;
    QComboBox *cb_language;
    QLabel *lbl_timezone;
    QComboBox *cb_timezone;
    QLabel *lbl_date_format;
    QComboBox *cb_date_format;
    QLabel *lbl_volume;
    QComboBox *cb_volume;
    QLabel *lbl_wifi_state;
    QComboBox *cb_wifi_state;
    QLabel *lbl_bt_state;
    QComboBox *cb_bt_state;
    QLabel *lbl_install_non_market;
    QComboBox *cb_install_non_market;
    QLabel *lbl_adb_state;
    QComboBox *cb_adb_state;
    QLabel *lbl_screenshot_btn;
    QComboBox *cb_screenshot_btn;


    QWidget *w;
    QWidget *common_page_w;


    common_window *common_page;

    QString prj_home_path;
};

#endif // MAINWINDOW_H
