#-------------------------------------------------
#
# Project created by QtCreator 2020-11-21T11:07:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = LineChart
TEMPLATE = app

CONFIG+=c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resource.qrc
