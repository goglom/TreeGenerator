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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "scenewidget.hpp"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *CameraButton;
    QRadioButton *radioButton_2;
    SceneWidget *Scene;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QLabel *label;
    QFrame *line;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *SceneOptionsButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(911, 641);
        MainWindow->setMinimumSize(QSize(640, 640));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("QPushButton{}"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        CameraButton = new QRadioButton(centralwidget);
        CameraButton->setObjectName(QString::fromUtf8("CameraButton"));
        CameraButton->setChecked(true);

        horizontalLayout_3->addWidget(CameraButton);

        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        horizontalLayout_3->addWidget(radioButton_2);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);

        Scene = new SceneWidget(centralwidget);
        Scene->setObjectName(QString::fromUtf8("Scene"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Scene->sizePolicy().hasHeightForWidth());
        Scene->setSizePolicy(sizePolicy);
        Scene->setMinimumSize(QSize(640, 480));
        Scene->setFocusPolicy(Qt::StrongFocus);

        verticalLayout->addWidget(Scene);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(4);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        doubleSpinBox = new QDoubleSpinBox(centralwidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMinimum(1.000000000000000);
        doubleSpinBox->setMaximum(100.000000000000000);
        doubleSpinBox->setSingleStep(1.000000000000000);
        doubleSpinBox->setValue(1.000000000000000);

        horizontalLayout->addWidget(doubleSpinBox);

        SceneOptionsButton = new QPushButton(centralwidget);
        SceneOptionsButton->setObjectName(QString::fromUtf8("SceneOptionsButton"));

        horizontalLayout->addWidget(SceneOptionsButton);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(CameraButton, SIGNAL(clicked()), Scene, SLOT(selectCamera()));
        QObject::connect(radioButton_2, SIGNAL(clicked()), Scene, SLOT(selectPointLight()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), Scene, SLOT(setGridSteps(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Driven object:", nullptr));
        CameraButton->setText(QCoreApplication::translate("MainWindow", "Camera", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Point Light", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Object number", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Grid step", nullptr));
        SceneOptionsButton->setText(QCoreApplication::translate("MainWindow", "Scene options", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
