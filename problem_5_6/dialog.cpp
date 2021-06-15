#include "dialog.hpp"
#include "ui_dialog.h"

#include <QtMath>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    colorDialog(new QColorDialog(this))
{
    ui->setupUi(this);

    QObject::connect(colorDialog, &QColorDialog::currentColorChanged,
                     this, &Dialog::setLightColor);

    auto range = ui->ZenithSlider->maximum() * ui->ZenithSlider->minimum();
    zenith = ui->ZenithSlider->value() * M_PI / range;
    range = ui->AzimuthSlider->maximum() * ui->AzimuthSlider->minimum();
    azimuth =  ui->AzimuthSlider->value() * M_PI * 2.f / range;
    updateDirLightDir();
    emit DirLightDirectionChanged(dirLightDirection);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::addMaterial(const QString& name)
{
    ui->MaterialComboBox->addItem(name);
}

void Dialog::setLightColor(const QColor& color)
{
    switch (lightSource) {
    case LightSources::Ambient :
        AmbientColor = color;
        emit AmbientColorChanged(color);
        break;
    case LightSources::Direct :
        DirLightColor = color;
        emit DirLightColorChanged(color);
        break;
    }
}

void Dialog::on_MaterialComboBox_currentIndexChanged(int index)
{
    emit ObjectMaterialChanged(index);
}


void Dialog::on_DirLightColorButton_clicked()
{
    lightSource = LightSources::Direct;
    colorDialog->setCurrentColor(DirLightColor);
    colorDialog->show();
}

void Dialog::on_AmbientColorButton_clicked()
{
    lightSource = LightSources::Ambient;
    colorDialog->setCurrentColor(AmbientColor);
    colorDialog->show();
}

void Dialog::updateDirLightDir()
{
    dirLightDirection = QVector3D(qSin(azimuth) * qSin(zenith),
                                  qCos(zenith), qCos(azimuth) * qSin(zenith));
}

void Dialog::on_AzimuthSlider_valueChanged(int value)
{
    auto range = ui->AzimuthSlider->maximum() - ui->AzimuthSlider->minimum();
    azimuth = value * M_PI * 2.f / range;
    updateDirLightDir();
    emit DirLightDirectionChanged(dirLightDirection);
}

void Dialog::on_ZenithSlider_valueChanged(int value)
{
    auto range = ui->ZenithSlider->maximum() - ui->ZenithSlider->minimum();
    zenith = value * M_PI / range;
    updateDirLightDir();
    emit DirLightDirectionChanged(dirLightDirection);
}
