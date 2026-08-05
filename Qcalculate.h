#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qcalculate.h"

class Qcalculate : public QMainWindow
{
    Q_OBJECT

public:
    Qcalculate(QWidget *parent = nullptr);
    ~Qcalculate();

    double* calculated( const QString& sInputText );

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
    void on_btnDivide_clicked();
    
	void on_btnAdd_clicked();
    void on_btnMinus_clicked();
	void on_btnEqual_clicked();
    void on_btnClear_clicked();
    void on_btnErase_clicked();
    void on_btnDot_clicked();
    

private:
    Ui::QcalculateClass ui;
};
