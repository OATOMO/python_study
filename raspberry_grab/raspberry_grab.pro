#-------------------------------------------------
#
# Project created by QtCreator 2017-06-17T22:40:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = raspberry_grab
TEMPLATE = app


SOURCES += main.cpp\
        grab_gui.cpp\
        v4l2_sdk/atom_bmp.cpp \
    v4l2_sdk/grab_v4l2.cpp

HEADERS  += grab_gui.h\
        v4l2_sdk/atom_bmp.hpp \
    v4l2_sdk/grab_v4l2.hpp

FORMS    += grab_gui.ui

INCLUDEPATH +=  /usr/local/include

LIBS += -L /usr/local/lib \
-lopencv_core -lopencv_imgproc \
-lopencv_highgui \
-lopencv_imgcodecs
