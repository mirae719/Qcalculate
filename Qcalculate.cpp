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
// const QString& 으로 매개변수로 받는 것과, QString* 으로 받는 것의 차이. 

double nResult;

double* Qcalculate::calculated( const QString& sInputText )
{
    // 스택변수 -> 자기 라이프 사이클이 끝나면 사라짐
    
    if( sInputText.contains( "+" ) == true )
    {

        QStringList lstInput = sInputText.split( "+" );
        
        if( lstInput.size() == 2 )
        {
            double nInputFront = lstInput.at( 0 ).toDouble();
            double nInputBack = lstInput.at( 1 ).toDouble();

            nResult = nInputFront + nInputBack;

            return &nResult;
        }
    }
    else if( sInputText.contains("-") )
	{
        QStringList lstInput = sInputText.split( "-" );

        if (lstInput.size() == 2)
        {
            double nInputFront = lstInput.at( 0 ).toDouble();
            double nInputBack = lstInput.at( 1 ).toDouble();

            nResult = nInputFront - nInputBack;

            return &nResult;
        }
	}
    else if( sInputText.contains( "*" ) )
    {
        QStringList lstInput = sInputText.split( "*" );

        if (lstInput.size() == 2)
        {
            double nInputFront = lstInput.at( 0 ).toDouble();
            double nInputBack = lstInput.at( 1 ).toDouble();

            nResult = nInputFront * nInputBack;

            return &nResult;
        }
    }
    else
    {
        QStringList lstInput = sInputText.split( "/" );

        if( lstInput.size() == 2 )
        {
            double nInputFront = lstInput.at( 0 ).toDouble();
            double nInputBack = lstInput.at( 1 ).toDouble();

            nResult = nInputFront / nInputBack;
            return &nResult;
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

void Qcalculate::on_btnMulti_clicked()
{
    QString sCurrentText = ui.edtInput->text();

    if( sCurrentText.isEmpty() == true )
    {
        return;
    }

    if( sCurrentText.endsWith( "+" ) == true ||
        sCurrentText.endsWith( "-" ) == true ||
        sCurrentText.endsWith( "*" ) == true ||
        sCurrentText.endsWith( "/" ) == true )
    {
        return;
    }

    QString sInputText = ui.btnMulti->text();

    ui.edtInput->setText(sCurrentText + sInputText);
}

void Qcalculate::on_btnDivide_clicked()
{
    QString sCurrentText = ui.edtInput->text();

    if( sCurrentText.isEmpty() == true )
    {
        return;
    }

    

    if( sCurrentText.endsWith( "+" ) == true ||
        sCurrentText.endsWith( "-" ) == true ||
        sCurrentText.endsWith( "*" ) == true ||
        sCurrentText.endsWith( "/" ) == true )
    {
        return;
    }

	QString sInputText = ui.btnDivide->text();
    ui.edtInput->setText( sCurrentText + sInputText );
}

void Qcalculate::on_btnAdd_clicked()
{
    QString sCurrentText = ui.edtInput->text();

    if ( sCurrentText.isEmpty() == true)
    {
        return;
    }

    if( sCurrentText.endsWith( "+" ) == true ||
        sCurrentText.endsWith( "-" ) == true ||
        sCurrentText.endsWith( "*" ) == true ||
        sCurrentText.endsWith( "/" ) == true )
    {
        return;
    }

    if( sCurrentText.isEmpty() == false && sCurrentText.endsWith( " " ) == false )
    {
        ui.edtInput->setText( sCurrentText + " " );
    }

    QString sInputText = ui.btnAdd->text();

    ui.edtInput->setText( sCurrentText + sInputText );
}

void Qcalculate::on_btnMinus_clicked()
{
    QString sCurrentText = ui.edtInput->text();

    if( sCurrentText.isEmpty() == true )
    {
        return;
    }
    

    if( sCurrentText.endsWith( "+" ) == true ||
        sCurrentText.endsWith( "-" ) == true ||
        sCurrentText.endsWith( "*" ) == true ||
        sCurrentText.endsWith( "/" ) == true )
    {
        return;
    }

    QString sInputText = ui.btnMinus->text();

    ui.edtInput->setText( sCurrentText + sInputText );
}

void Qcalculate::on_btnEqual_clicked()
{
    QString sCurrentText = ui.edtInput->text();
    /*
    if( sEdtInput.endsWith( "+" ) == false ||
        sEdtInput.endsWith( "-" ) == false ||
        sEdtInput.endsWith( "*" ) == false ||
        sEdtInput.endsWith( "/" ) == false ||
        sEdtInput.contains( "+" ) == true ||
        sEdtInput.contains( "-" ) == true ||
        sEdtInput.contains( "*" ) == true ||
        sEdtInput.contains( "/" ) == true )
    {
        return;
    }
	*/
    if( sCurrentText.isEmpty() == true )
    {
        return;
    }

    double* nResult = calculated( sCurrentText );

    // 포인터 -> 값이 들어가기도 하고, 주소가 들어가기도 함

	ui.edtInput->setText( QString::number( *nResult ) );
    ui.edtCaluated->setText( QString::number( *nResult ) );
    
}

void Qcalculate::on_btnClear_clicked()
{
    ui.edtInput->clear();
    ui.edtCaluated->setText( QString::number( 0 ) );
}

void Qcalculate::on_btnErase_clicked()
{
    QString sInputText = ui.edtInput->text();

    if (sInputText.isEmpty() == false)
    {
        sInputText.chop( 1 );
        ui.edtInput->setText( sInputText );
    }
}

void Qcalculate::on_btnDot_clicked()
{
    QString sCurrentText = ui.edtInput->text();
    QString sInputText = ui.btnDot->text();

    if ( sCurrentText.isEmpty() == true )
    {
        return;
    }

    if ( sCurrentText.contains( "." ) == true )
    {
        return;
    }

    ui.edtInput->setText( sCurrentText + sInputText );
}

void Qcalculate::on_btnSquare_clicked()
{
    QString sCurrentText = ui.edtInput->text();

    double dCurrent = sCurrentText.toDouble();

    double dResult = pow( dCurrent, 2 );

    ui.edtInput->setText( ( "sqr(" + sCurrentText + ")" ) );
    ui.edtCaluated->setText( QString::number( dResult ) );
}

void Qcalculate::on_btnSign_clicked()
{

}











