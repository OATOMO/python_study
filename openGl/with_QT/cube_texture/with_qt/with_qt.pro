#-------------------------------------------------
#
# Project created by QtCreator 2017-08-30T19:32:05
#
#-------------------------------------------------

QT       += core gui
QT 		 += opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = with_qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mycube.cpp

HEADERS  += mainwindow.h \
    mycube.h

FORMS    += mainwindow.ui
