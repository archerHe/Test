#ifndef COMMON_WINDOW_H
#define COMMON_WINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class common_window;
}

class common_window : public QWidget
{
    Q_OBJECT

public:
    explicit common_window(QWidget *parent = 0);
    ~common_window();

private:
    Ui::common_window *ui;

    QGridLayout *layout;
    QLabel *lbl_model;
    QLineEdit *le_model;
    QLabel *lbl_bt_name;
    QLineEdit *le_bt_name;
    QLabel *lbl_sleep_time;
    QLineEdit *le_sleep_time;
    QLabel *lbl_homepage;
    QLineEdit *le_homepage;


};

#endif // COMMON_WINDOW_H
