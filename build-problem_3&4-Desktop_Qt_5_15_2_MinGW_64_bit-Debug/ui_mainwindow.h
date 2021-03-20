/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "cubewidget.hpp"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    CubeWidget *cubeWidget;
    QFormLayout *formLayout;
    QRadioButton *radioButton_2;
    QSpinBox *spinBox;
    QRadioButton *radioButton_3;
    QSpinBox *spinBox_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(855, 681);
        MainWindow->setMinimumSize(QSize(640, 640));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("QPushButton{}"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cubeWidget = new CubeWidget(centralwidget);
        cubeWidget->setObjectName(QString::fromUtf8("cubeWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(cubeWidget->sizePolicy().hasHeightForWidth());
        cubeWidget->setSizePolicy(sizePolicy);
        cubeWidget->setMinimumSize(QSize(640, 480));
        cubeWidget->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout->addWidget(cubeWidget);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setFocusPolicy(Qt::ClickFocus);
        radioButton_2->setChecked(false);

        formLayout->setWidget(1, QFormLayout::LabelRole, radioButton_2);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox);

        radioButton_3 = new QRadioButton(centralwidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setFocusPolicy(Qt::ClickFocus);

        formLayout->setWidget(2, QFormLayout::LabelRole, radioButton_3);

        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        formLayout->setLayout(3, QFormLayout::LabelRole, verticalLayout);

        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setFocusPolicy(Qt::WheelFocus);
        radioButton->setChecked(true);

        formLayout->setWidget(0, QFormLayout::LabelRole, radioButton);


        horizontalLayout->addLayout(formLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 855, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(radioButton_2, SIGNAL(clicked()), cubeWidget, SLOT(selectPointLights()));
        QObject::connect(radioButton, SIGNAL(clicked()), cubeWidget, SLOT(selectCamera()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Point lights", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "Spot lights", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Camera", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
