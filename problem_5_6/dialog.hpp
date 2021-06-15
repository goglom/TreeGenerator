#pragma once

#include <QDialog>
#include <QColorDialog>
#include <QVector3D>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    void AmbientColorChanged(QColor);
    void ObjectMaterialChanged(int);
    void DirLightIntensityChanged(float);
    void DirLightDirectionChanged(QVector3D const&);
    void DirLightColorChanged(QColor const&);

public slots:
    void addMaterial(QString const& name);
    void setLightColor(QColor const& color);
    void on_MaterialComboBox_currentIndexChanged(int index);
    void on_DirLightColorButton_clicked();
    void on_AmbientColorButton_clicked();

public:

    enum class LightSources{
        Direct,
        Ambient,
    };
    LightSources lightSource = LightSources::Direct;
    QVector3D dirLightDirection{0, -1, 0};
    Ui::Dialog *ui;
    QColorDialog* colorDialog;
    QColor AmbientColor;
    QColor DirLightColor;
    float azimuth = 0;
    float zenith = 0;

    void updateDirLightDir();

private slots:
    void on_AzimuthSlider_valueChanged(int value);
    void on_ZenithSlider_valueChanged(int value);
};

