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
    common_window.cpp \
    wizard.cpp \
    global.cpp \
    texthelper.cpp \
    loadcfgfromsrc.cpp

HEADERS  += mainwindow.h \
    common_window.h \
    wizard.h \
    global.h \
    texthelper.h \
    loadcfgfromsrc.h

FORMS    += mainwindow.ui \
    common_window.ui \
    testwidget.ui \
    wizard.ui \
    loadcfgfromsrc.ui



DISTFILES +=

RESOURCES += \
    img.qrc


