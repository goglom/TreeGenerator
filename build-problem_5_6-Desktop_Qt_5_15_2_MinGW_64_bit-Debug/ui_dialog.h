/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *MaterialPropertiesLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QComboBox *MaterialComboBox;
    QPushButton *AmbientColorButton;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QSlider *AzimuthSlider;
    QLabel *label;
    QSlider *ZenithSlider;
    QLabel *label_2;
    QPushButton *DirLightColorButton;
    QFrame *line_2;
    QFrame *line;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(272, 255);
        verticalLayout_4 = new QVBoxLayout(Dialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        MaterialPropertiesLabel = new QLabel(Dialog);
        MaterialPropertiesLabel->setObjectName(QString::fromUtf8("MaterialPropertiesLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MaterialPropertiesLabel->sizePolicy().hasHeightForWidth());
        MaterialPropertiesLabel->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(MaterialPropertiesLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        MaterialComboBox = new QComboBox(Dialog);
        MaterialComboBox->setObjectName(QString::fromUtf8("MaterialComboBox"));

        horizontalLayout->addWidget(MaterialComboBox);


        verticalLayout->addLayout(horizontalLayout);

        AmbientColorButton = new QPushButton(Dialog);
        AmbientColorButton->setObjectName(QString::fromUtf8("AmbientColorButton"));

        verticalLayout->addWidget(AmbientColorButton);


        verticalLayout_4->addLayout(verticalLayout);

        line_3 = new QFrame(Dialog);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        AzimuthSlider = new QSlider(Dialog);
        AzimuthSlider->setObjectName(QString::fromUtf8("AzimuthSlider"));
        AzimuthSlider->setValue(0);
        AzimuthSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(AzimuthSlider, 0, 1, 1, 1);

        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        ZenithSlider = new QSlider(Dialog);
        ZenithSlider->setObjectName(QString::fromUtf8("ZenithSlider"));
        ZenithSlider->setValue(60);
        ZenithSlider->setOrientation(Qt::Vertical);

        gridLayout_2->addWidget(ZenithSlider, 0, 0, 1, 1);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        DirLightColorButton = new QPushButton(Dialog);
        DirLightColorButton->setObjectName(QString::fromUtf8("DirLightColorButton"));

        verticalLayout_2->addWidget(DirLightColorButton);


        verticalLayout_4->addLayout(verticalLayout_2);

        line_2 = new QFrame(Dialog);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_2);

        line = new QFrame(Dialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        MaterialPropertiesLabel->setText(QCoreApplication::translate("Dialog", "Material Properies", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "Material: ", nullptr));
        AmbientColorButton->setText(QCoreApplication::translate("Dialog", "Select Ambient Color", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Zenith", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Azimuth", nullptr));
        DirLightColorButton->setText(QCoreApplication::translate("Dialog", "Select color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
