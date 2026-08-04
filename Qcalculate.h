#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qcalculate.h"

class Qcalculate : public QMainWindow
{
    Q_OBJECT

public:
    Qcalculate(QWidget *parent = nullptr);
    ~Qcalculate();

private:
    Ui::QcalculateClass ui;
};
