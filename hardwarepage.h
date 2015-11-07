#ifndef HARDWAREPAGE_H
#define HARDWAREPAGE_H

#include <QWidget>
#include <QtGui>
#include <QtCore>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QScrollArea>

namespace Ui {
class HardwarePage;
}

class HardwarePage : public QWidget
{
    Q_OBJECT

public:
    explicit HardwarePage(QWidget *parent = 0);
    ~HardwarePage();

    void initWidget();

private:
    Ui::HardwarePage *ui;

    QScrollArea *scrollArea;
    QWidget *common_scrollWidget;

    QLabel *lbl_screen;
    QLabel *lbl_flash;
    QLabel *lbl_back_cam;
    QLabel *lbl_front_cam;

    QComboBox *cb_screen;
    QComboBox *cb_flash;
    QComboBox *cb_back_cam;
    QComboBox *cb_front_cam;

    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;
    QGridLayout *gridLayout;

};

#endif // HARDWAREPAGE_H
