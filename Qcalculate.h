#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qcalculate.h"

class Qcalculate : public QMainWindow
{
    Q_OBJECT

public:
    Qcalculate(QWidget *parent = nullptr);
    ~Qcalculate();

    int* calculated(QString* sInputText);

public slots:
    void on_btnZero_clicked();
    void on_btnOne_clicked();
    void on_btnTwo_clicked();
    void on_btnThree_clicked();
    void on_btnFour_clicked();
    void on_btnFive_clicked();
    void on_btnSix_clicked();
    void on_btnSeven_clicked();
    void on_btnAte_clicked();
    void on_btnNine_clicked();
    void on_btnMulti_clicked();
    
	void on_btnAdd_clicked();
    void on_btnMinus_clicked();
	void on_btnEqual_clicked();
    

private:
    Ui::QcalculateClass ui;
};
