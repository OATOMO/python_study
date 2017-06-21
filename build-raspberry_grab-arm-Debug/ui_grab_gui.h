/********************************************************************************
** Form generated from reading UI file 'grab_gui.ui'
**
** Created: Tue Jun 20 02:03:52 2017
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAB_GUI_H
#define UI_GRAB_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_grab_gui
{
public:
    QWidget *centralWidget;
    QLabel *imageLabel;
    QPushButton *grabButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *grab_gui)
    {
        if (grab_gui->objectName().isEmpty())
            grab_gui->setObjectName(QString::fromUtf8("grab_gui"));
        grab_gui->resize(600, 480);
        centralWidget = new QWidget(grab_gui);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        imageLabel = new QLabel(centralWidget);
        imageLabel->setObjectName(QString::fromUtf8("imageLabel"));
        imageLabel->setGeometry(QRect(10, 0, 320, 240));
        imageLabel->setMinimumSize(QSize(320, 240));
        imageLabel->setMaximumSize(QSize(320, 240));
        imageLabel->setFrameShape(QFrame::Box);
        imageLabel->setFrameShadow(QFrame::Plain);
        grabButton = new QPushButton(centralWidget);
        grabButton->setObjectName(QString::fromUtf8("grabButton"));
        grabButton->setGeometry(QRect(10, 280, 80, 22));
        grab_gui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(grab_gui);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 19));
        grab_gui->setMenuBar(menuBar);
        mainToolBar = new QToolBar(grab_gui);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        grab_gui->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(grab_gui);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        grab_gui->setStatusBar(statusBar);

        retranslateUi(grab_gui);

        QMetaObject::connectSlotsByName(grab_gui);
    } // setupUi

    void retranslateUi(QMainWindow *grab_gui)
    {
        grab_gui->setWindowTitle(QApplication::translate("grab_gui", "grab_gui", 0, QApplication::UnicodeUTF8));
        imageLabel->setText(QString());
        grabButton->setText(QApplication::translate("grab_gui", "Grab", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class grab_gui: public Ui_grab_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAB_GUI_H
