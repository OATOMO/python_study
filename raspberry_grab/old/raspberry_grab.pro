#-------------------------------------------------
#
# Project created by QtCreator 2017-06-17T22:40:54
#
#-------------------------------------------------

#QT       += core gui

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = raspberry_grab
#TEMPLATE = app


#SOURCES += main.cpp\
#        grab_gui.cpp\
#        v4l2_sdk/atom_bmp.cpp \
#    v4l2_sdk/grab_v4l2.cpp

#HEADERS  += grab_gui.h\
#        v4l2_sdk/atom_bmp.hpp \
#    v4l2_sdk/grab_v4l2.hpp

#FORMS    += grab_gui.ui

#INCLUDEPATH +=  /usr/local/include

#LIBS += -L /usr/local/lib \
#-lopencv_core -lopencv_imgproc \
#-lopencv_highgui \
#-lopencv_imgcodecs

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gaussianTest
TEMPLATE = app


SOURCES += main.cpp\
        grab_gui.cpp\
        v4l2_sdk/atom_bmp.cpp \
    v4l2_sdk/grab_v4l2.cpp

HEADERS  += grab_gui.h\
        v4l2_sdk/atom_bmp.hpp \
    v4l2_sdk/grab_v4l2.hpp




FORMS    += grab_gui.ui

INCLUDEPATH +=  /opt/CodeSourcery/opencv-2.4.8/include
INCLUDEPATH += /opt/opencv-3.0/include
INCLUDEPATH += /opt/CodeSourcery//arm-xilinx-linux-gnueabi/include/c++/4.6.1/

LIBS += -L /opt/CodeSourcery/opencv-2.4.8/lib \
-lopencv_core -lopencv_imgproc \
-lopencv_highgui

target.path += /root
INSTALLS += target

