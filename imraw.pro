#-------------------------------------------------
#
# Project created by QtCreator 2014-02-01T12:02:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = imraw
TEMPLATE = app

LIBS += -lMagick++

SOURCES += main.cpp\
        mainwindow.cpp \
    optdialog.cpp

HEADERS  += mainwindow.h \
    optdialog.h

FORMS    += mainwindow.ui \
    optdialog.ui
INCLUDEPATH += . /usr/include/ImageMagick

