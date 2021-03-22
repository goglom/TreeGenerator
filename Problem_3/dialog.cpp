#include "dialog.hpp"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    colorDialog(new QColorDialog(this))
{
    ui->setupUi(this);



    QObject::connect(colorDialog, &QColorDialog::currentColorChanged,
                     this, &Dialog::setLightColor);




    dirLightDirection.setX(ui->DirLightXSpinBox->value());
    dirLightDirection.setY(ui->DirLightYSpinBox->value());
    dirLightDirection.setZ(ui->DirLightZSpinBox->value());
    emit DirLightDirectionChanged(dirLightDirection);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setShininessVal(float val)
{
    ui->ShininessVal->setText(QString::number(val, 'f', 0));
    ui->ShininessSlider->setValue(val);

}

void Dialog::addMaterial(const QString& name)
{
    ui->MaterialComboBox->addItem(name);
}

void Dialog::setLightColor(const QColor& color)
{
    switch (lightSource) {
    case LightSources::Direct :
        emit DirLightColorChanged(color);
        break;
    case LightSources::Point:
        emit PointLightColorChanged(color);
        break;
    case LightSources::Spot:
        emit SpotLightColorChanged(color);
        break;
    }
}

void Dialog::on_AmbientSlider_valueChanged(int value)
{
    float range = ui->AmbientSlider->maximum() - ui->AmbientSlider->minimum();
    float res = value / range;
    ui->AmbientVal->setText(QString::number(res, 'f', 2));
    emit AmbientChanged(res);
}

void Dialog::on_DiffuseSlider_valueChanged(int value)
{
    float range = ui->DiffuseSlider->maximum() - ui->DiffuseSlider->minimum();
    float res = value / range;
    ui->DiffuseVal->setText(QString::number(res, 'f', 2));

    emit DiffuseChanged(res);
}

void Dialog::on_SpecularSlider_valueChanged(int value)
{
    float range = ui->SpecularSlider->maximum() - ui->SpecularSlider->minimum();
    float res = value / range;
    ui->SpecularVal->setText(QString::number(res, 'f', 2));

    emit SpecularChanged(res);
}

void Dialog::on_ShininessSlider_valueChanged(int value)
{
    setShininessVal(value);

    emit ShininessChanged(value);
}

void Dialog::on_MaterialComboBox_currentIndexChanged(int index)
{
    emit ObjectMaterialChanged(index);
}

void Dialog::on_DirLightIntensitySlider_valueChanged(int value)
{
    float range = ui->DirLightIntensitySlider->maximum() - ui->DirLightIntensitySlider->minimum();
    float res = value / range;
    ui->DirLightIntensityVal->setText(QString::number(res, 'f', 2));

    emit DirLightIntensityChanged(res);
}


void Dialog::on_DirLightXSpinBox_valueChanged(double arg1)
{
    dirLightDirection.setX(arg1);
    emit DirLightDirectionChanged(dirLightDirection);
}

void Dialog::on_DirLightYSpinBox_valueChanged(double arg1)
{
    dirLightDirection.setY(arg1);
    emit DirLightDirectionChanged(dirLightDirection);
}

void Dialog::on_DirLightZSpinBox_valueChanged(double arg1)
{
    dirLightDirection.setZ(arg1);
    emit DirLightDirectionChanged(dirLightDirection);
}

void Dialog::on_DirLightColorButton_clicked()
{
    lightSource = LightSources::Direct;
    colorDialog->show();
}

void Dialog::on_PointLightColorButton_clicked()
{
    lightSource = LightSources::Point;
    colorDialog->show();
}

void Dialog::on_PointLightConstSpinBox_valueChanged(double arg1)
{
    emit PointLightConstChanged(arg1);
}

void Dialog::on_PointLightLinSpinBox_valueChanged(double arg1)
{
    emit PointLightLinChanged(arg1);
}

void Dialog::on_PointLightQuadSpinBox_valueChanged(double arg1)
{
    emit PointLightQuadChanged(arg1);
}

void Dialog::on_PointLightIntensitySlider_valueChanged(int value)
{
    float range = ui->PointLightIntensitySlider->maximum() - ui->PointLightIntensitySlider->minimum();
    float res = value / range;
    ui->PointLightIntensityVal->setText(QString::number(res, 'f', 2));

    emit PointLightIntensityChanged(res);
}
