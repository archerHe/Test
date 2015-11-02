#ifndef LOADCFGFROMSRC_H
#define LOADCFGFROMSRC_H

#include <QWidget>

namespace Ui {
class LoadCfgFromSrc;
}

class LoadCfgFromSrc : public QWidget
{
    Q_OBJECT

public:
    explicit LoadCfgFromSrc(QWidget *parent = 0);
    ~LoadCfgFromSrc();


private:
    Ui::LoadCfgFromSrc *ui;
};

#endif // LOADCFGFROMSRC_H
