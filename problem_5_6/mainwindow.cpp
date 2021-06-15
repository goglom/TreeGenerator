#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include "dialog.hpp"

QColor getQColor(QVector3D const& glColor){
    QColor result;
    result.setRedF(glColor.x());
    result.setGreenF(glColor.y());
    result.setBlueF(glColor.z());
    return result;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dialog(new Dialog(this))
{
    ui->setupUi(this);

    QObject::connect(dialog, &Dialog::ObjectMaterialChanged,
                     ui->Scene, &SceneWidget::setObjectMaterial);
    QObject::connect(dialog, &Dialog::AmbientColorChanged,
                     ui->Scene, &SceneWidget::setAmbientColor);
    QObject::connect(ui->Scene, &SceneWidget::newMaterial,
                     dialog, &Dialog::addMaterial);
    QObject::connect(dialog, &Dialog::DirLightIntensityChanged,
                     ui->Scene, &SceneWidget::setDirInt);
    QObject::connect(dialog, &Dialog::DirLightColorChanged,
                     ui->Scene, &SceneWidget::setDirColor);
    QObject::connect(dialog, &Dialog::DirLightDirectionChanged,
                     ui->Scene, &SceneWidget::setDirDirection);

    dialog->AmbientColor = getQColor(ui->Scene->ambientColor);
    dialog->DirLightColor = getQColor(ui->Scene->dirLightColor);

    ui->ParamsComboBox->addItem("Pass ratio");
    ui->ParamsComboBox->addItem("Split decay");
    ui->ParamsComboBox->addItem("Feed minimum");
    ui->ParamsComboBox->addItem("Directedness");

    activeParam = &treeParams().ratio;
    addParamSets();
    updateInterface();
    on_RebuildTreeButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SceneOptionsButton_clicked()
{
    dialog->show();
}

void MainWindow::on_RebuildTreeButton_clicked()
{
    setTreeParams();
    ui->Scene->regrowTree();
}


void MainWindow::on_EpochsSpinBox_valueChanged(int arg1)
{
    ui->Scene->treeGrowCycles = arg1;
}

void MainWindow::on_RatioDSpinBox_valueChanged(double arg1)
{
    treeParams().ratio = arg1;
}

void MainWindow::on_SpreadDSpinBox_valueChanged(double arg1)
{
    treeParams().spread = arg1;
}

void MainWindow::on_SplitsizeDSpinBox_valueChanged(double arg1)
{
    treeParams().splitsize = arg1;
}

void MainWindow::on_FeedDSpinBox_valueChanged(double arg1)
{
    ui->Scene->treeFeedPortion = arg1;
}

void MainWindow::setTreeParams()
{
    ui->Scene->treeParams = treeParams();
}

void MainWindow::addParamSets()
{
    for (size_t i = 0; i < treeParamsSet.size(); ++i){
        ui->ParamsSetComboBox->addItem("Set " + QString::number(i + 1));
    }
}

TreeBranch::Parametrs& MainWindow::treeParams()
{
    return treeParamsSet[curParamIdx];
}

void MainWindow::on_LeafsCheckBox_stateChanged(int arg1)
{
    treeParams().drawLeafs = arg1 == Qt::CheckState::Checked;
}

void MainWindow::on_LeafSizeDSpinBox_valueChanged(double arg1)
{
    treeParams().leafSize = arg1;
}

void MainWindow::on_ParamsComboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        activeParam = &treeParams().passRatio;
        break;
    case 1:
        activeParam = &treeParams().splitDecay;
        break;
    case 2:
        activeParam = &treeParams().feedMin;
        break;
    case 3:
        activeParam = &treeParams().directedness;
        break;
    }
    ui->ParamsDSpinBox->setValue(*activeParam);
}

void MainWindow::on_ParamsDSpinBox_valueChanged(double arg1)
{
    *activeParam = arg1;
}

void MainWindow::updateInterface()
{
    ui->RatioDSpinBox->setValue(treeParams().ratio);
    ui->RatioDSpinBox->setValue(treeParams().ratio);
    ui->SplitsizeDSpinBox->setValue(treeParams().splitsize);
    ui->LeafsCheckBox->setChecked(treeParams().drawLeafs);
    ui->LeafSizeDSpinBox->setValue(treeParams().leafSize);
    ui->ParamsDSpinBox->setValue(*activeParam);

    //treeParams().ratio = ui->RatioDSpinBox->value();
    //treeParams().spread = ui->SpreadDSpinBox->value();
    //treeParams().splitsize = ui->SplitsizeDSpinBox->value();
    //treeParams().drawLeafs = ui->LeafsCheckBox->checkState() == Qt::CheckState::Checked;
    //treeParams().leafSize = ui->LeafSizeDSpinBox->value();
}

void MainWindow::on_ParamsSetComboBox_currentIndexChanged(int index)
{
    curParamIdx = index;
    updateInterface();
}
