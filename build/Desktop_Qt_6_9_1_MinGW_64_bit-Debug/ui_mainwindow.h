/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <joystick.h>
#include <myslider.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *imageLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_wd;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLabel *label_sd;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *targetIpEdit;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    Joystick *widget_joystick;
    MySlider *controlSlider;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(670, 917);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        imageLabel = new QLabel(centralwidget);
        imageLabel->setObjectName("imageLabel");
        imageLabel->setGeometry(QRect(9, 9, 381, 240));
        imageLabel->setMinimumSize(QSize(320, 240));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 270, 381, 33));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName("label_4");

        horizontalLayout_5->addWidget(label_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");

        horizontalLayout_5->addLayout(horizontalLayout_8);

        label_wd = new QLabel(layoutWidget);
        label_wd->setObjectName("label_wd");
        QFont font;
        font.setPointSize(17);
        label_wd->setFont(font);

        horizontalLayout_5->addWidget(label_wd);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");

        horizontalLayout_4->addLayout(horizontalLayout_7);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        label_sd = new QLabel(layoutWidget);
        label_sd->setObjectName("label_sd");
        label_sd->setFont(font);
        label_sd->setTextFormat(Qt::TextFormat::RichText);

        horizontalLayout_4->addWidget(label_sd);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(60, 600, 271, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        targetIpEdit = new QLineEdit(layoutWidget1);
        targetIpEdit->setObjectName("targetIpEdit");

        horizontalLayout->addWidget(targetIpEdit);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(70, 310, 252, 273));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_joystick = new Joystick(layoutWidget2);
        widget_joystick->setObjectName("widget_joystick");
        widget_joystick->setMinimumSize(QSize(250, 250));
        widget_joystick->setMaximumSize(QSize(250, 250));

        verticalLayout->addWidget(widget_joystick);

        controlSlider = new MySlider(layoutWidget2);
        controlSlider->setObjectName("controlSlider");
        controlSlider->setMinimum(-150);
        controlSlider->setMaximum(150);
        controlSlider->setValue(0);
        controlSlider->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout->addWidget(controlSlider);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        imageLabel->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\270\251\345\272\246", nullptr));
        label_wd->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\271\277\345\272\246", nullptr));
        label_sd->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "IP\345\234\260\345\235\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
