#include "Qcalculate.h"
#include "QMessageBox"
#include "QSystemTrayIcon"


Qcalculate::Qcalculate(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    /**

    int n = ui.lineEdit->text().toInt();
    int a;
    n += a;

    ui.lineEdit->setText( QString::number( n ) );

	**/


	//connect( ui.btnOne, &QPushButton::clicked, this, &Qcalculate::on_btnOne_clicked );

}

Qcalculate::~Qcalculate()
{
}

// 연산자 계산
int* Qcalculate::calculated(QString* sInputText)
{
    if( sInputText->contains( "+" ) )
    {

        QStringList lstInput = sInputText->split( "+" );
        
        if (lstInput.size() == 2)
        {
            int sInputFront = lstInput.at( 0 ).toInt();
            int sInputBack = lstInput.at( 1 ).toInt();

            int sResult = sInputFront + sInputBack;

            return &sResult;
        }
    }
    else if( sInputText->contains("-") )
	{
        QStringList lstInput = sInputText->split( "-" );

        if (lstInput.size() == 2)
        {
            int sInputFront = lstInput.at( 0 ).toInt();
            int sInputBack = lstInput.at( 1 ).toInt();

            int sResult = sInputFront - sInputBack;

            return &sResult;
        }
	}
}

void Qcalculate::on_btnZero_clicked()
{
    QString sInputText = ui.btnZero->text();
    QString sCurrentText = ui.edtInput->text();

    ui.edtInput->setText( sCurrentText + sInputText );
}

void Qcalculate::on_btnOne_clicked()
{
    QString sInputText = ui.btnOne->text();
    QString sCurrentText = ui.edtInput->text();

    ui.edtInput->setText( sCurrentText + sInputText );
}
    

void Qcalculate::on_btnTwo_clicked()
{
    QString sInputText = ui.btnTwo->text();
    QString sCurrentText = ui.edtInput->text();

    ui.edtInput->setText( sCurrentText + sInputText );
}

void Qcalculate::on_btnThree_clicked()
{
    QString sInputText = ui.btnThree->text();
    QString sCurrentText = ui.edtInput->text();

	ui.edtInput->setText( sCurrentText + sInputText );
}

void Qcalculate::on_btnFour_clicked()
{
    QString sInputText = ui.btnFour->text();
    QString sCurrentText = ui.edtInput->text();

    ui.edtInput->setText( sCurrentText + sInputText );
}

void Qcalculate::on_btnFive_clicked()
{
    QString sInputText = ui.btnFive->text();
    QString sCurrentText = ui.edtInput->text();

    ui.edtInput->setText( sCurrentText + sInputText );
}

void Qcalculate::on_btnSix_clicked()
{
    QString sInputText = ui.btnSix->text();
    QString sCurrentText = ui.edtInput->text();

    ui.edtInput->setText( sCurrentText + sInputText );
}

void Qcalculate::on_btnSeven_clicked()
{
    QString sInputText = ui.btnSeven->text();
    QString sCurrentText = ui.edtInput->text();

    ui.edtInput->setText( sCurrentText + sInputText );
}

void Qcalculate::on_btnAte_clicked()
{
    QString sInputText = ui.btnAte->text();
    QString sCurrentText = ui.edtInput->text();

    ui.edtInput->setText( sCurrentText + sInputText );
}

void Qcalculate::on_btnNine_clicked()
{
    QString sInputText = ui.btnNine->text();
    QString sCurrentText = ui.edtInput->text();

    ui.edtInput->setText( sCurrentText + sInputText );
}

void Qcalculate::on_btnAdd_clicked()
{
    QString sCurrentText = ui.edtInput->text();

    if ( sCurrentText.endsWith("+") )
    {
        return;
    }

    if ( !sCurrentText.isEmpty() && !sCurrentText.endsWith(" ") )
    {
        ui.edtInput->setText( sCurrentText + " " );
    }

    QString sInputText = ui.btnAdd->text();

    ui.edtInput->setText( sCurrentText + sInputText );
}

void Qcalculate::on_btnMinus_clicked()
{
    if( ui.edtInput->text().endsWith("-") )
    {
        return;
    }

    QString sCurrentText = ui.edtInput->text();
    QString sInputText = ui.btnMinus->text();

    
    ui.edtInput->setText( sCurrentText + sInputText );
}

void Qcalculate::on_btnEqual_clicked()
{
    QString sEdtInput = ui.edtInput->text();

    int* nResult = calculated( &sEdtInput );
	
    ui.edtCaluated->setText( QString::number( *nResult ) );
}











