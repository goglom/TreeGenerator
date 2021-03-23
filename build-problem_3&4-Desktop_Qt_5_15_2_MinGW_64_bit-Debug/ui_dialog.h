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
#include <QtWidgets/QDoubleSpinBox>
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
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *MaterialPropertiesLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
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
    QFrame *line_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *DirLightLabel;
    QSlider *DirLightIntensitySlider;
    QLabel *DirLightIntensityVal;
    QGridLayout *gridLayout_2;
    QDoubleSpinBox *DirLightYSpinBox;
    QDoubleSpinBox *DirLightXSpinBox;
    QLabel *label_3;
    QDoubleSpinBox *DirLightZSpinBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *DirLightColorButton;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *PointLightLabel;
    QSlider *PointLightIntensitySlider;
    QLabel *PointLightIntensityVal;
    QGridLayout *gridLayout_3;
    QLabel *label_6;
    QDoubleSpinBox *PointLightLinSpinBox;
    QDoubleSpinBox *PointLightQuadSpinBox;
    QLabel *label_8;
    QLabel *label_7;
    QDoubleSpinBox *PointLightConstSpinBox;
    QPushButton *PointLightColorButton;
    QFrame *line;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *SpotLightLabel;
    QSlider *SpotLightIntensitySlider;
    QLabel *SpotLightIntensityVal;
    QGridLayout *gridLayout_4;
    QLabel *label_9;
    QLabel *label_11;
    QDoubleSpinBox *SpotLightQuadSpinBox;
    QDoubleSpinBox *SpotLightConstSpinBox;
    QLabel *label_10;
    QDoubleSpinBox *SpotLightLinSpinBox;
    QGridLayout *gridLayout_5;
    QLabel *CutOffVal;
    QLabel *label_4;
    QSlider *CutOffSlider;
    QSlider *OuterCutOffSlider;
    QLabel *label_12;
    QLabel *OuterCutOffVal;
    QPushButton *SpotLightColorButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(422, 678);
        verticalLayout_5 = new QVBoxLayout(Dialog);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
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

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        AmbientVal = new QLabel(Dialog);
        AmbientVal->setObjectName(QString::fromUtf8("AmbientVal"));
        AmbientVal->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(AmbientVal, 0, 2, 1, 1);

        DiffuseVal = new QLabel(Dialog);
        DiffuseVal->setObjectName(QString::fromUtf8("DiffuseVal"));

        gridLayout->addWidget(DiffuseVal, 1, 2, 1, 1);

        SpecularVal = new QLabel(Dialog);
        SpecularVal->setObjectName(QString::fromUtf8("SpecularVal"));

        gridLayout->addWidget(SpecularVal, 2, 2, 1, 1);

        SpecularSlider = new QSlider(Dialog);
        SpecularSlider->setObjectName(QString::fromUtf8("SpecularSlider"));
        SpecularSlider->setMinimum(1);
        SpecularSlider->setMaximum(100);
        SpecularSlider->setValue(100);
        SpecularSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(SpecularSlider, 2, 1, 1, 1);

        SpecularLabel = new QLabel(Dialog);
        SpecularLabel->setObjectName(QString::fromUtf8("SpecularLabel"));

        gridLayout->addWidget(SpecularLabel, 2, 0, 1, 1);

        DiffuseLabel = new QLabel(Dialog);
        DiffuseLabel->setObjectName(QString::fromUtf8("DiffuseLabel"));

        gridLayout->addWidget(DiffuseLabel, 1, 0, 1, 1);

        ShininessLabel = new QLabel(Dialog);
        ShininessLabel->setObjectName(QString::fromUtf8("ShininessLabel"));

        gridLayout->addWidget(ShininessLabel, 3, 0, 1, 1);

        DiffuseSlider = new QSlider(Dialog);
        DiffuseSlider->setObjectName(QString::fromUtf8("DiffuseSlider"));
        DiffuseSlider->setMinimum(1);
        DiffuseSlider->setMaximum(100);
        DiffuseSlider->setValue(100);
        DiffuseSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(DiffuseSlider, 1, 1, 1, 1);

        AmbientLabel = new QLabel(Dialog);
        AmbientLabel->setObjectName(QString::fromUtf8("AmbientLabel"));

        gridLayout->addWidget(AmbientLabel, 0, 0, 1, 1);

        AmbientSlider = new QSlider(Dialog);
        AmbientSlider->setObjectName(QString::fromUtf8("AmbientSlider"));
        AmbientSlider->setMinimum(1);
        AmbientSlider->setMaximum(100);
        AmbientSlider->setValue(100);
        AmbientSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(AmbientSlider, 0, 1, 1, 1);

        ShininessSlider = new QSlider(Dialog);
        ShininessSlider->setObjectName(QString::fromUtf8("ShininessSlider"));
        ShininessSlider->setMinimum(1);
        ShininessSlider->setMaximum(100);
        ShininessSlider->setValue(100);
        ShininessSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(ShininessSlider, 3, 1, 1, 1);

        ShininessVal = new QLabel(Dialog);
        ShininessVal->setObjectName(QString::fromUtf8("ShininessVal"));

        gridLayout->addWidget(ShininessVal, 3, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        verticalLayout_5->addLayout(verticalLayout);

        line_3 = new QFrame(Dialog);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        DirLightLabel = new QLabel(Dialog);
        DirLightLabel->setObjectName(QString::fromUtf8("DirLightLabel"));

        horizontalLayout_2->addWidget(DirLightLabel);

        DirLightIntensitySlider = new QSlider(Dialog);
        DirLightIntensitySlider->setObjectName(QString::fromUtf8("DirLightIntensitySlider"));
        DirLightIntensitySlider->setMinimum(1);
        DirLightIntensitySlider->setMaximum(100);
        DirLightIntensitySlider->setValue(10);
        DirLightIntensitySlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(DirLightIntensitySlider);

        DirLightIntensityVal = new QLabel(Dialog);
        DirLightIntensityVal->setObjectName(QString::fromUtf8("DirLightIntensityVal"));

        horizontalLayout_2->addWidget(DirLightIntensityVal);


        verticalLayout_2->addLayout(horizontalLayout_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        DirLightYSpinBox = new QDoubleSpinBox(Dialog);
        DirLightYSpinBox->setObjectName(QString::fromUtf8("DirLightYSpinBox"));
        DirLightYSpinBox->setDecimals(1);
        DirLightYSpinBox->setMinimum(-1.000000000000000);
        DirLightYSpinBox->setMaximum(1.000000000000000);
        DirLightYSpinBox->setSingleStep(0.100000000000000);
        DirLightYSpinBox->setValue(-1.000000000000000);

        gridLayout_2->addWidget(DirLightYSpinBox, 0, 1, 1, 1);

        DirLightXSpinBox = new QDoubleSpinBox(Dialog);
        DirLightXSpinBox->setObjectName(QString::fromUtf8("DirLightXSpinBox"));
        DirLightXSpinBox->setDecimals(1);
        DirLightXSpinBox->setMinimum(-1.000000000000000);
        DirLightXSpinBox->setMaximum(1.000000000000000);
        DirLightXSpinBox->setSingleStep(0.100000000000000);

        gridLayout_2->addWidget(DirLightXSpinBox, 0, 0, 1, 1);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 2, 1, 1);

        DirLightZSpinBox = new QDoubleSpinBox(Dialog);
        DirLightZSpinBox->setObjectName(QString::fromUtf8("DirLightZSpinBox"));
        DirLightZSpinBox->setDecimals(1);
        DirLightZSpinBox->setMinimum(-1.000000000000000);
        DirLightZSpinBox->setMaximum(1.000000000000000);
        DirLightZSpinBox->setSingleStep(0.100000000000000);

        gridLayout_2->addWidget(DirLightZSpinBox, 0, 2, 1, 1);

        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        DirLightColorButton = new QPushButton(Dialog);
        DirLightColorButton->setObjectName(QString::fromUtf8("DirLightColorButton"));

        verticalLayout_2->addWidget(DirLightColorButton);


        verticalLayout_5->addLayout(verticalLayout_2);

        line_2 = new QFrame(Dialog);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        PointLightLabel = new QLabel(Dialog);
        PointLightLabel->setObjectName(QString::fromUtf8("PointLightLabel"));

        horizontalLayout_3->addWidget(PointLightLabel);

        PointLightIntensitySlider = new QSlider(Dialog);
        PointLightIntensitySlider->setObjectName(QString::fromUtf8("PointLightIntensitySlider"));
        PointLightIntensitySlider->setMinimum(1);
        PointLightIntensitySlider->setMaximum(100);
        PointLightIntensitySlider->setValue(100);
        PointLightIntensitySlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(PointLightIntensitySlider);

        PointLightIntensityVal = new QLabel(Dialog);
        PointLightIntensityVal->setObjectName(QString::fromUtf8("PointLightIntensityVal"));

        horizontalLayout_3->addWidget(PointLightIntensityVal);


        verticalLayout_3->addLayout(horizontalLayout_3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 1, 2, 1, 1);

        PointLightLinSpinBox = new QDoubleSpinBox(Dialog);
        PointLightLinSpinBox->setObjectName(QString::fromUtf8("PointLightLinSpinBox"));
        PointLightLinSpinBox->setDecimals(3);
        PointLightLinSpinBox->setMinimum(0.000000000000000);
        PointLightLinSpinBox->setMaximum(0.100000000000000);
        PointLightLinSpinBox->setSingleStep(0.005000000000000);
        PointLightLinSpinBox->setValue(0.000000000000000);

        gridLayout_3->addWidget(PointLightLinSpinBox, 0, 1, 1, 1);

        PointLightQuadSpinBox = new QDoubleSpinBox(Dialog);
        PointLightQuadSpinBox->setObjectName(QString::fromUtf8("PointLightQuadSpinBox"));
        PointLightQuadSpinBox->setDecimals(3);
        PointLightQuadSpinBox->setMinimum(0.000000000000000);
        PointLightQuadSpinBox->setMaximum(1.000000000000000);
        PointLightQuadSpinBox->setSingleStep(0.005000000000000);
        PointLightQuadSpinBox->setValue(0.015000000000000);

        gridLayout_3->addWidget(PointLightQuadSpinBox, 0, 2, 1, 1);

        label_8 = new QLabel(Dialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 1, 1, 1, 1);

        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 1, 0, 1, 1);

        PointLightConstSpinBox = new QDoubleSpinBox(Dialog);
        PointLightConstSpinBox->setObjectName(QString::fromUtf8("PointLightConstSpinBox"));
        PointLightConstSpinBox->setDecimals(1);
        PointLightConstSpinBox->setMinimum(0.100000000000000);
        PointLightConstSpinBox->setMaximum(1.000000000000000);
        PointLightConstSpinBox->setSingleStep(0.100000000000000);
        PointLightConstSpinBox->setValue(1.000000000000000);

        gridLayout_3->addWidget(PointLightConstSpinBox, 0, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);

        PointLightColorButton = new QPushButton(Dialog);
        PointLightColorButton->setObjectName(QString::fromUtf8("PointLightColorButton"));

        verticalLayout_3->addWidget(PointLightColorButton);


        verticalLayout_5->addLayout(verticalLayout_3);

        line = new QFrame(Dialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        SpotLightLabel = new QLabel(Dialog);
        SpotLightLabel->setObjectName(QString::fromUtf8("SpotLightLabel"));

        horizontalLayout_4->addWidget(SpotLightLabel);

        SpotLightIntensitySlider = new QSlider(Dialog);
        SpotLightIntensitySlider->setObjectName(QString::fromUtf8("SpotLightIntensitySlider"));
        SpotLightIntensitySlider->setMinimum(1);
        SpotLightIntensitySlider->setMaximum(100);
        SpotLightIntensitySlider->setValue(100);
        SpotLightIntensitySlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(SpotLightIntensitySlider);

        SpotLightIntensityVal = new QLabel(Dialog);
        SpotLightIntensityVal->setObjectName(QString::fromUtf8("SpotLightIntensityVal"));

        horizontalLayout_4->addWidget(SpotLightIntensityVal);


        verticalLayout_4->addLayout(horizontalLayout_4);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_9 = new QLabel(Dialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_4->addWidget(label_9, 1, 2, 1, 1);

        label_11 = new QLabel(Dialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 1, 0, 1, 1);

        SpotLightQuadSpinBox = new QDoubleSpinBox(Dialog);
        SpotLightQuadSpinBox->setObjectName(QString::fromUtf8("SpotLightQuadSpinBox"));
        SpotLightQuadSpinBox->setDecimals(3);
        SpotLightQuadSpinBox->setMinimum(0.000000000000000);
        SpotLightQuadSpinBox->setMaximum(1.000000000000000);
        SpotLightQuadSpinBox->setSingleStep(0.005000000000000);
        SpotLightQuadSpinBox->setValue(0.015000000000000);

        gridLayout_4->addWidget(SpotLightQuadSpinBox, 0, 2, 1, 1);

        SpotLightConstSpinBox = new QDoubleSpinBox(Dialog);
        SpotLightConstSpinBox->setObjectName(QString::fromUtf8("SpotLightConstSpinBox"));
        SpotLightConstSpinBox->setDecimals(1);
        SpotLightConstSpinBox->setMinimum(0.100000000000000);
        SpotLightConstSpinBox->setMaximum(1.000000000000000);
        SpotLightConstSpinBox->setSingleStep(0.100000000000000);
        SpotLightConstSpinBox->setValue(1.000000000000000);

        gridLayout_4->addWidget(SpotLightConstSpinBox, 0, 0, 1, 1);

        label_10 = new QLabel(Dialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 1, 1, 1, 1);

        SpotLightLinSpinBox = new QDoubleSpinBox(Dialog);
        SpotLightLinSpinBox->setObjectName(QString::fromUtf8("SpotLightLinSpinBox"));
        SpotLightLinSpinBox->setDecimals(3);
        SpotLightLinSpinBox->setMinimum(0.000000000000000);
        SpotLightLinSpinBox->setMaximum(0.100000000000000);
        SpotLightLinSpinBox->setSingleStep(0.005000000000000);
        SpotLightLinSpinBox->setValue(0.000000000000000);

        gridLayout_4->addWidget(SpotLightLinSpinBox, 0, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_4);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        CutOffVal = new QLabel(Dialog);
        CutOffVal->setObjectName(QString::fromUtf8("CutOffVal"));

        gridLayout_5->addWidget(CutOffVal, 0, 2, 1, 1);

        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_5->addWidget(label_4, 0, 0, 1, 1);

        CutOffSlider = new QSlider(Dialog);
        CutOffSlider->setObjectName(QString::fromUtf8("CutOffSlider"));
        CutOffSlider->setMinimum(1);
        CutOffSlider->setMaximum(90);
        CutOffSlider->setValue(12);
        CutOffSlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(CutOffSlider, 0, 1, 1, 1);

        OuterCutOffSlider = new QSlider(Dialog);
        OuterCutOffSlider->setObjectName(QString::fromUtf8("OuterCutOffSlider"));
        OuterCutOffSlider->setMinimum(0);
        OuterCutOffSlider->setMaximum(90);
        OuterCutOffSlider->setValue(3);
        OuterCutOffSlider->setOrientation(Qt::Horizontal);

        gridLayout_5->addWidget(OuterCutOffSlider, 1, 1, 1, 1);

        label_12 = new QLabel(Dialog);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_5->addWidget(label_12, 1, 0, 1, 1);

        OuterCutOffVal = new QLabel(Dialog);
        OuterCutOffVal->setObjectName(QString::fromUtf8("OuterCutOffVal"));

        gridLayout_5->addWidget(OuterCutOffVal, 1, 2, 1, 1);


        verticalLayout_4->addLayout(gridLayout_5);

        SpotLightColorButton = new QPushButton(Dialog);
        SpotLightColorButton->setObjectName(QString::fromUtf8("SpotLightColorButton"));

        verticalLayout_4->addWidget(SpotLightColorButton);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(Dialog);
        QObject::connect(CutOffSlider, SIGNAL(valueChanged(int)), CutOffVal, SLOT(setNum(int)));
        QObject::connect(OuterCutOffSlider, SIGNAL(valueChanged(int)), OuterCutOffVal, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        MaterialPropertiesLabel->setText(QCoreApplication::translate("Dialog", "Material Properies", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "Material: ", nullptr));
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
        label_3->setText(QCoreApplication::translate("Dialog", "Z", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "X", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Y", nullptr));
        DirLightColorButton->setText(QCoreApplication::translate("Dialog", "Select color", nullptr));
        PointLightLabel->setText(QCoreApplication::translate("Dialog", "Point Light (I)", nullptr));
        PointLightIntensityVal->setText(QCoreApplication::translate("Dialog", "1.00", nullptr));
        label_6->setText(QCoreApplication::translate("Dialog", "Quadric", nullptr));
        label_8->setText(QCoreApplication::translate("Dialog", "Linear", nullptr));
        label_7->setText(QCoreApplication::translate("Dialog", "Const", nullptr));
        PointLightColorButton->setText(QCoreApplication::translate("Dialog", "Select color", nullptr));
        SpotLightLabel->setText(QCoreApplication::translate("Dialog", "Spot Light (I)", nullptr));
        SpotLightIntensityVal->setText(QCoreApplication::translate("Dialog", "1.00", nullptr));
        label_9->setText(QCoreApplication::translate("Dialog", "Quadric", nullptr));
        label_11->setText(QCoreApplication::translate("Dialog", "Const", nullptr));
        label_10->setText(QCoreApplication::translate("Dialog", "Linear", nullptr));
        CutOffVal->setText(QCoreApplication::translate("Dialog", "12", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "Cut off", nullptr));
        label_12->setText(QCoreApplication::translate("Dialog", "Smooth angle", nullptr));
        OuterCutOffVal->setText(QCoreApplication::translate("Dialog", "3", nullptr));
        SpotLightColorButton->setText(QCoreApplication::translate("Dialog", "Select color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
