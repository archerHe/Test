#-------------------------------------------------
#
# Project created by QtCreator 2015-10-17T10:40:29
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wizard.cpp \
    global.cpp \
    texthelper.cpp \
    launcher_page.cpp \
    hardwarepage.cpp \
    commonpage.cpp

HEADERS  += mainwindow.h \
    wizard.h \
    global.h \
    texthelper.h \
    launcher_page.h \
    hardwarepage.h \
    commonpage.h

FORMS    += mainwindow.ui \
    testwidget.ui \
    wizard.ui \
    launcher_page.ui \
    hardwarepage.ui \
    commonpage.ui



DISTFILES +=

RESOURCES += \
    img.qrc


