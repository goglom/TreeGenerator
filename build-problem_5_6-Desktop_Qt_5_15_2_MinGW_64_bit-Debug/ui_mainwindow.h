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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
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
    QLabel *label_5;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer;
    QComboBox *ParamsSetComboBox;
    QFrame *line_7;
    QPushButton *SceneOptionsButton;
    QHBoxLayout *horizontalLayout_3;
    SceneWidget *Scene;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_9;
    QComboBox *ParamsComboBox;
    QDoubleSpinBox *ParamsDSpinBox;
    QFrame *line_6;
    QCheckBox *LeafsCheckBox;
    QLabel *label_8;
    QDoubleSpinBox *LeafSizeDSpinBox;
    QFrame *line_5;
    QLabel *label_7;
    QDoubleSpinBox *FeedDSpinBox;
    QFrame *line;
    QLabel *label_4;
    QSpinBox *EpochsSpinBox;
    QFrame *line_2;
    QLabel *label;
    QDoubleSpinBox *RatioDSpinBox;
    QFrame *line_3;
    QLabel *label_2;
    QDoubleSpinBox *SpreadDSpinBox;
    QFrame *line_4;
    QLabel *label_3;
    QDoubleSpinBox *SplitsizeDSpinBox;
    QPushButton *RebuildTreeButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1009, 641);
        MainWindow->setMinimumSize(QSize(640, 640));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("QPushButton{}"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color : rgb(85, 255, 0);\n"
"	font-weight : bold;\n"
"}"));

        horizontalLayout_4->addWidget(label_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        ParamsSetComboBox = new QComboBox(centralwidget);
        ParamsSetComboBox->setObjectName(QString::fromUtf8("ParamsSetComboBox"));

        horizontalLayout_4->addWidget(ParamsSetComboBox);

        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_7);

        SceneOptionsButton = new QPushButton(centralwidget);
        SceneOptionsButton->setObjectName(QString::fromUtf8("SceneOptionsButton"));

        horizontalLayout_4->addWidget(SceneOptionsButton);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

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
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout->addWidget(label_9);

        ParamsComboBox = new QComboBox(centralwidget);
        ParamsComboBox->setObjectName(QString::fromUtf8("ParamsComboBox"));

        horizontalLayout->addWidget(ParamsComboBox);

        ParamsDSpinBox = new QDoubleSpinBox(centralwidget);
        ParamsDSpinBox->setObjectName(QString::fromUtf8("ParamsDSpinBox"));
        ParamsDSpinBox->setDecimals(6);
        ParamsDSpinBox->setSingleStep(0.001000000000000);
        ParamsDSpinBox->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);

        horizontalLayout->addWidget(ParamsDSpinBox);

        line_6 = new QFrame(centralwidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_6);

        LeafsCheckBox = new QCheckBox(centralwidget);
        LeafsCheckBox->setObjectName(QString::fromUtf8("LeafsCheckBox"));
        LeafsCheckBox->setChecked(true);

        horizontalLayout->addWidget(LeafsCheckBox);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        LeafSizeDSpinBox = new QDoubleSpinBox(centralwidget);
        LeafSizeDSpinBox->setObjectName(QString::fromUtf8("LeafSizeDSpinBox"));
        LeafSizeDSpinBox->setMaximum(10.000000000000000);
        LeafSizeDSpinBox->setSingleStep(0.100000000000000);
        LeafSizeDSpinBox->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        LeafSizeDSpinBox->setValue(0.500000000000000);

        horizontalLayout->addWidget(LeafSizeDSpinBox);

        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_5);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);

        FeedDSpinBox = new QDoubleSpinBox(centralwidget);
        FeedDSpinBox->setObjectName(QString::fromUtf8("FeedDSpinBox"));
        FeedDSpinBox->setMinimum(0.000000000000000);
        FeedDSpinBox->setSingleStep(0.100000000000000);
        FeedDSpinBox->setValue(1.000000000000000);

        horizontalLayout->addWidget(FeedDSpinBox);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        EpochsSpinBox = new QSpinBox(centralwidget);
        EpochsSpinBox->setObjectName(QString::fromUtf8("EpochsSpinBox"));
        EpochsSpinBox->setMinimum(1);
        EpochsSpinBox->setMaximum(2000);
        EpochsSpinBox->setSingleStep(10);
        EpochsSpinBox->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        EpochsSpinBox->setValue(200);

        horizontalLayout->addWidget(EpochsSpinBox);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        RatioDSpinBox = new QDoubleSpinBox(centralwidget);
        RatioDSpinBox->setObjectName(QString::fromUtf8("RatioDSpinBox"));
        RatioDSpinBox->setSingleStep(0.100000000000000);
        RatioDSpinBox->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        RatioDSpinBox->setValue(0.600000000000000);

        horizontalLayout->addWidget(RatioDSpinBox);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        SpreadDSpinBox = new QDoubleSpinBox(centralwidget);
        SpreadDSpinBox->setObjectName(QString::fromUtf8("SpreadDSpinBox"));
        SpreadDSpinBox->setSingleStep(0.100000000000000);
        SpreadDSpinBox->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        SpreadDSpinBox->setValue(0.450000000000000);

        horizontalLayout->addWidget(SpreadDSpinBox);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_4);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        SplitsizeDSpinBox = new QDoubleSpinBox(centralwidget);
        SplitsizeDSpinBox->setObjectName(QString::fromUtf8("SplitsizeDSpinBox"));
        SplitsizeDSpinBox->setSingleStep(0.100000000000000);
        SplitsizeDSpinBox->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        SplitsizeDSpinBox->setValue(2.500000000000000);

        horizontalLayout->addWidget(SplitsizeDSpinBox);

        RebuildTreeButton = new QPushButton(centralwidget);
        RebuildTreeButton->setObjectName(QString::fromUtf8("RebuildTreeButton"));

        horizontalLayout->addWidget(RebuildTreeButton);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(Scene, SIGNAL(fpsChanged(int)), label_6, SLOT(setNum(int)));
        QObject::connect(Scene, SIGNAL(widgetClosed()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "FPS: ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        SceneOptionsButton->setText(QCoreApplication::translate("MainWindow", "Scene options", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Parameter:", nullptr));
        LeafsCheckBox->setText(QCoreApplication::translate("MainWindow", "Leafs", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Leaf size", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Feed", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Epochs", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Ratio", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Spread", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Splitsize", nullptr));
        RebuildTreeButton->setText(QCoreApplication::translate("MainWindow", "Rebuid tree", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
