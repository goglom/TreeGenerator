#pragma once

#include "dialog.hpp"
#include "treebranch.hpp"

#include <vector>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_SceneOptionsButton_clicked();
    void on_RebuildTreeButton_clicked();
    void on_EpochsSpinBox_valueChanged(int arg1);
    void on_RatioDSpinBox_valueChanged(double arg1);
    void on_SpreadDSpinBox_valueChanged(double arg1);
    void on_SplitsizeDSpinBox_valueChanged(double arg1);
    void on_FeedDSpinBox_valueChanged(double arg1);
    void on_LeafsCheckBox_stateChanged(int arg1);
    void on_LeafSizeDSpinBox_valueChanged(double arg1);
    void on_ParamsComboBox_currentIndexChanged(int index);
    void on_ParamsDSpinBox_valueChanged(double arg1);

    void on_ParamsSetComboBox_currentIndexChanged(int index);

private:
    void updateInterface();
    void setTreeParams();
    void addParamSets();

    Ui::MainWindow *ui;
    Dialog* dialog;
    TreeBranch::Parametrs& treeParams();
    float* activeParam;
    size_t curParamIdx = 0;
    std::vector<TreeBranch::Parametrs> treeParamsSet = {
        {.ratio = 0.6, .spread = 0.45, .splitsize = 2.5},
        {.ratio = 0.8, .spread = 0.1, .splitsize = 2.4},
        {.ratio = 0.5, .spread = 0.25, .splitsize = 1.9},
        {.ratio = 0.9, .spread = 0.1, .splitsize = 2.4}
    };


};

