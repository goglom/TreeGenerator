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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *PointLightLabel;
    QSlider *PointLightIntensitySlider;
    QLabel *PointLightIntensityVal;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QCheckBox *PointLightSwitch;
    QDoubleSpinBox *PointLightLinSpinBox;
    QDoubleSpinBox *PointLightConstSpinBox;
    QLabel *label_6;
    QDoubleSpinBox *PointLightQuadSpinBox;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *PointLightColorButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *MaterialPropertiesLabel;
    QSpacerItem *horizontalSpacer;
    QComboBox *MaterialComboBox;
    QGridLayout *gridLayout;
    QLabel *AmbientVal;
    QLabel *DiffuseVal;
    QLabel *SpecularVal;
    QSlider *SpecularSlider;
    QLabel *SpecularLabel;
    QLabel *DiffuseLabel;
    QLabel *ShininessLabel;
    QSlider *DiffuseSlider;
    QLabel *AmbientLabel;
    QSlider *AmbientSlider;
    QSlider *ShininessSlider;
    QLabel *ShininessVal;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *DirLightLabel;
    QSlider *DirLightIntensitySlider;
    QLabel *DirLightIntensityVal;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QCheckBox *DirLightSwitch;
    QDoubleSpinBox *DirLightYSpinBox;
    QDoubleSpinBox *DirLightXSpinBox;
    QLabel *label_3;
    QDoubleSpinBox *DirLightZSpinBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *DirLightColorButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(422, 678);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 330, 231, 141));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        PointLightLabel = new QLabel(layoutWidget);
        PointLightLabel->setObjectName(QString::fromUtf8("PointLightLabel"));

        horizontalLayout_3->addWidget(PointLightLabel);

        PointLightIntensitySlider = new QSlider(layoutWidget);
        PointLightIntensitySlider->setObjectName(QString::fromUtf8("PointLightIntensitySlider"));
        PointLightIntensitySlider->setMinimum(1);
        PointLightIntensitySlider->setMaximum(100);
        PointLightIntensitySlider->setValue(10);
        PointLightIntensitySlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(PointLightIntensitySlider);

        PointLightIntensityVal = new QLabel(layoutWidget);
        PointLightIntensityVal->setObjectName(QString::fromUtf8("PointLightIntensityVal"));

        horizontalLayout_3->addWidget(PointLightIntensityVal);


        verticalLayout_3->addLayout(horizontalLayout_3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        PointLightSwitch = new QCheckBox(layoutWidget);
        PointLightSwitch->setObjectName(QString::fromUtf8("PointLightSwitch"));
        PointLightSwitch->setText(QString::fromUtf8(""));
        PointLightSwitch->setChecked(true);

        gridLayout_3->addWidget(PointLightSwitch, 0, 0, 1, 1);

        PointLightLinSpinBox = new QDoubleSpinBox(layoutWidget);
        PointLightLinSpinBox->setObjectName(QString::fromUtf8("PointLightLinSpinBox"));
        PointLightLinSpinBox->setDecimals(1);
        PointLightLinSpinBox->setMinimum(-1.000000000000000);
        PointLightLinSpinBox->setMaximum(1.000000000000000);
        PointLightLinSpinBox->setSingleStep(0.100000000000000);
        PointLightLinSpinBox->setValue(-1.000000000000000);

        gridLayout_3->addWidget(PointLightLinSpinBox, 0, 2, 1, 1);

        PointLightConstSpinBox = new QDoubleSpinBox(layoutWidget);
        PointLightConstSpinBox->setObjectName(QString::fromUtf8("PointLightConstSpinBox"));
        PointLightConstSpinBox->setDecimals(1);
        PointLightConstSpinBox->setMinimum(-1.000000000000000);
        PointLightConstSpinBox->setMaximum(1.000000000000000);
        PointLightConstSpinBox->setSingleStep(0.100000000000000);

        gridLayout_3->addWidget(PointLightConstSpinBox, 0, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 1, 3, 1, 1);

        PointLightQuadSpinBox = new QDoubleSpinBox(layoutWidget);
        PointLightQuadSpinBox->setObjectName(QString::fromUtf8("PointLightQuadSpinBox"));
        PointLightQuadSpinBox->setDecimals(1);
        PointLightQuadSpinBox->setMinimum(-1.000000000000000);
        PointLightQuadSpinBox->setMaximum(1.000000000000000);
        PointLightQuadSpinBox->setSingleStep(0.100000000000000);

        gridLayout_3->addWidget(PointLightQuadSpinBox, 0, 3, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 1, 1, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 1, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);

        PointLightColorButton = new QPushButton(layoutWidget);
        PointLightColorButton->setObjectName(QString::fromUtf8("PointLightColorButton"));

        verticalLayout_3->addWidget(PointLightColorButton);

        widget = new QWidget(Dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 20, 251, 151));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        MaterialPropertiesLabel = new QLabel(widget);
        MaterialPropertiesLabel->setObjectName(QString::fromUtf8("MaterialPropertiesLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MaterialPropertiesLabel->sizePolicy().hasHeightForWidth());
        MaterialPropertiesLabel->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(MaterialPropertiesLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        MaterialComboBox = new QComboBox(widget);
        MaterialComboBox->setObjectName(QString::fromUtf8("MaterialComboBox"));

        horizontalLayout->addWidget(MaterialComboBox);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        AmbientVal = new QLabel(widget);
        AmbientVal->setObjectName(QString::fromUtf8("AmbientVal"));
        AmbientVal->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(AmbientVal, 0, 2, 1, 1);

        DiffuseVal = new QLabel(widget);
        DiffuseVal->setObjectName(QString::fromUtf8("DiffuseVal"));

        gridLayout->addWidget(DiffuseVal, 1, 2, 1, 1);

        SpecularVal = new QLabel(widget);
        SpecularVal->setObjectName(QString::fromUtf8("SpecularVal"));

        gridLayout->addWidget(SpecularVal, 2, 2, 1, 1);

        SpecularSlider = new QSlider(widget);
        SpecularSlider->setObjectName(QString::fromUtf8("SpecularSlider"));
        SpecularSlider->setMinimum(1);
        SpecularSlider->setMaximum(100);
        SpecularSlider->setValue(100);
        SpecularSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(SpecularSlider, 2, 1, 1, 1);

        SpecularLabel = new QLabel(widget);
        SpecularLabel->setObjectName(QString::fromUtf8("SpecularLabel"));

        gridLayout->addWidget(SpecularLabel, 2, 0, 1, 1);

        DiffuseLabel = new QLabel(widget);
        DiffuseLabel->setObjectName(QString::fromUtf8("DiffuseLabel"));

        gridLayout->addWidget(DiffuseLabel, 1, 0, 1, 1);

        ShininessLabel = new QLabel(widget);
        ShininessLabel->setObjectName(QString::fromUtf8("ShininessLabel"));

        gridLayout->addWidget(ShininessLabel, 3, 0, 1, 1);

        DiffuseSlider = new QSlider(widget);
        DiffuseSlider->setObjectName(QString::fromUtf8("DiffuseSlider"));
        DiffuseSlider->setMinimum(1);
        DiffuseSlider->setMaximum(100);
        DiffuseSlider->setValue(100);
        DiffuseSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(DiffuseSlider, 1, 1, 1, 1);

        AmbientLabel = new QLabel(widget);
        AmbientLabel->setObjectName(QString::fromUtf8("AmbientLabel"));

        gridLayout->addWidget(AmbientLabel, 0, 0, 1, 1);

        AmbientSlider = new QSlider(widget);
        AmbientSlider->setObjectName(QString::fromUtf8("AmbientSlider"));
        AmbientSlider->setMinimum(1);
        AmbientSlider->setMaximum(100);
        AmbientSlider->setValue(100);
        AmbientSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(AmbientSlider, 0, 1, 1, 1);

        ShininessSlider = new QSlider(widget);
        ShininessSlider->setObjectName(QString::fromUtf8("ShininessSlider"));
        ShininessSlider->setMinimum(1);
        ShininessSlider->setMaximum(100);
        ShininessSlider->setValue(100);
        ShininessSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(ShininessSlider, 3, 1, 1, 1);

        ShininessVal = new QLabel(widget);
        ShininessVal->setObjectName(QString::fromUtf8("ShininessVal"));

        gridLayout->addWidget(ShininessVal, 3, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        widget1 = new QWidget(Dialog);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(50, 180, 231, 141));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        DirLightLabel = new QLabel(widget1);
        DirLightLabel->setObjectName(QString::fromUtf8("DirLightLabel"));

        horizontalLayout_2->addWidget(DirLightLabel);

        DirLightIntensitySlider = new QSlider(widget1);
        DirLightIntensitySlider->setObjectName(QString::fromUtf8("DirLightIntensitySlider"));
        DirLightIntensitySlider->setMinimum(1);
        DirLightIntensitySlider->setMaximum(100);
        DirLightIntensitySlider->setValue(10);
        DirLightIntensitySlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(DirLightIntensitySlider);

        DirLightIntensityVal = new QLabel(widget1);
        DirLightIntensityVal->setObjectName(QString::fromUtf8("DirLightIntensityVal"));

        horizontalLayout_2->addWidget(DirLightIntensityVal);


        verticalLayout_2->addLayout(horizontalLayout_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(widget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        DirLightSwitch = new QCheckBox(widget1);
        DirLightSwitch->setObjectName(QString::fromUtf8("DirLightSwitch"));
        DirLightSwitch->setText(QString::fromUtf8(""));
        DirLightSwitch->setChecked(true);

        gridLayout_2->addWidget(DirLightSwitch, 0, 0, 1, 1);

        DirLightYSpinBox = new QDoubleSpinBox(widget1);
        DirLightYSpinBox->setObjectName(QString::fromUtf8("DirLightYSpinBox"));
        DirLightYSpinBox->setDecimals(1);
        DirLightYSpinBox->setMinimum(-1.000000000000000);
        DirLightYSpinBox->setMaximum(1.000000000000000);
        DirLightYSpinBox->setSingleStep(0.100000000000000);
        DirLightYSpinBox->setValue(-1.000000000000000);

        gridLayout_2->addWidget(DirLightYSpinBox, 0, 2, 1, 1);

        DirLightXSpinBox = new QDoubleSpinBox(widget1);
        DirLightXSpinBox->setObjectName(QString::fromUtf8("DirLightXSpinBox"));
        DirLightXSpinBox->setDecimals(1);
        DirLightXSpinBox->setMinimum(-1.000000000000000);
        DirLightXSpinBox->setMaximum(1.000000000000000);
        DirLightXSpinBox->setSingleStep(0.100000000000000);

        gridLayout_2->addWidget(DirLightXSpinBox, 0, 1, 1, 1);

        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 3, 1, 1);

        DirLightZSpinBox = new QDoubleSpinBox(widget1);
        DirLightZSpinBox->setObjectName(QString::fromUtf8("DirLightZSpinBox"));
        DirLightZSpinBox->setDecimals(1);
        DirLightZSpinBox->setMinimum(-1.000000000000000);
        DirLightZSpinBox->setMaximum(1.000000000000000);
        DirLightZSpinBox->setSingleStep(0.100000000000000);

        gridLayout_2->addWidget(DirLightZSpinBox, 0, 3, 1, 1);

        label = new QLabel(widget1);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 1, 1, 1);

        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        DirLightColorButton = new QPushButton(widget1);
        DirLightColorButton->setObjectName(QString::fromUtf8("DirLightColorButton"));

        verticalLayout_2->addWidget(DirLightColorButton);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        PointLightLabel->setText(QCoreApplication::translate("Dialog", "Point Light (I)", nullptr));
        PointLightIntensityVal->setText(QCoreApplication::translate("Dialog", "0.10", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "On/Off", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog", "Quadric", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog", "Const", nullptr));
        label_8->setText(QCoreApplication::translate("Dialog", "Linear", nullptr));
        PointLightColorButton->setText(QCoreApplication::translate("Dialog", "Select color", nullptr));
        MaterialPropertiesLabel->setText(QCoreApplication::translate("Dialog", "Material Properies", nullptr));
        AmbientVal->setText(QCoreApplication::translate("Dialog", "1.00", nullptr));
        DiffuseVal->setText(QCoreApplication::translate("Dialog", "1.00", nullptr));
        SpecularVal->setText(QCoreApplication::translate("Dialog", "1.00", nullptr));
        SpecularLabel->setText(QCoreApplication::translate("Dialog", "Specular", nullptr));
        DiffuseLabel->setText(QCoreApplication::translate("Dialog", "Diffuse", nullptr));
        ShininessLabel->setText(QCoreApplication::translate("Dialog", "Shininess", nullptr));
        AmbientLabel->setText(QCoreApplication::translate("Dialog", "Ambient", nullptr));
        ShininessVal->setText(QCoreApplication::translate("Dialog", "0", nullptr));
        DirLightLabel->setText(QCoreApplication::translate("Dialog", "Direct Light (I)", nullptr));
        DirLightIntensityVal->setText(QCoreApplication::translate("Dialog", "0.10", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "On/Off", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Z", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "X", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Y", nullptr));
        DirLightColorButton->setText(QCoreApplication::translate("Dialog", "Select color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
