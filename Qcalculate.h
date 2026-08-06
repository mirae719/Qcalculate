#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qcalculate.h"
#include <QFrame>
#include <QLabel>
#include <QVBoxLayout>


class Qcalculate : public QMainWindow
{
    Q_OBJECT

public:
    Qcalculate(QWidget *parent = nullptr);
    ~Qcalculate();

    double* calculated( const QString& sInputText );
    void decidePrint(const QString& sBtnText, const QString& sCurrentText);

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
    void on_btnSquare_clicked();
    void on_btnSign_clicked();
    void on_btnDivideX_clicked();
    void on_btnRoot_clicked();
    void on_btnPersent_clicked();
    void on_btnMs_clicked();
    void on_btnMP_clicked();
    void on_btnMM_clicked();
    void on_btnMc_clicked();
    void on_btnMr_clicked();
    void on_btnRegister_clicked();
    void on_btnMemory_clicked();

    void addDataFrame( const QString& dataValue );
    void updateLayoutMemory( const QString& dataValue );
    void deleteLayoutMemory();

private:
    Ui::QcalculateClass ui;
    QVector<QString> vecData;
};
