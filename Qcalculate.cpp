#include "Qcalculate.h"
#include "QMessageBox"


Qcalculate::Qcalculate(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

}

Qcalculate::~Qcalculate()
{
}

// 연산자 계산
// const QString& 으로 매개변수로 받는 것과, QString* 으로 받는 것의 차이. 

double dResult;

double* Qcalculate::calculated( const QString& sInputText )
{
    // 스택변수 -> 자기 라이프 사이클이 끝나면 사라짐
    
    if( sInputText.contains( "+" ) == true )
    {

        QStringList lstInput = sInputText.split( "+" );
        
        if( lstInput.size() == 2 )
        {
            double dInputFront = lstInput.at( 0 ).toDouble();
            double dInputBack = lstInput.at( 1 ).toDouble();

            dResult = dInputFront + dInputBack;

            return &dResult;
        }
    }
    else if( sInputText.contains("-") )
	{
        QStringList lstInput = sInputText.split( "-" );

        if (lstInput.size() == 2)
        {
            double dInputFront = lstInput.at( 0 ).toDouble();
            double dInputBack = lstInput.at( 1 ).toDouble();

            dResult = dInputFront - dInputBack;

            return &dResult;
        }
	}
    else if( sInputText.contains( "X" ) )
    {
        QStringList lstInput = sInputText.split( "X" );

        if (lstInput.size() == 2)
        {
            double dInputFront = lstInput.at( 0 ).toDouble();
            double dInputBack = lstInput.at( 1 ).toDouble();

            dResult = dInputFront * dInputBack;

            return &dResult;
        }
    }
    else
    {
        QStringList lstInput = sInputText.split( "÷" );

        if( lstInput.size() == 2 )
        {
            double dInputFront = lstInput.at( 0 ).toDouble();
            double dInputBack = lstInput.at( 1 ).toDouble();

            dResult = dInputFront / dInputBack;
            return &dResult;
        }
    }
}

void Qcalculate::decidePrint( const QString& sBtn, QString& sCurrentText )
{
    QString sInputText = ui.edtInput->text();
    if( sInputText.isEmpty() == false )
    {
        if( sInputText.endsWith( "+" ) == true ||
            sInputText.endsWith( "-" ) == true ||
            sInputText.endsWith( "÷" ) == true ||
            sInputText.endsWith( "X" ) == true )
        {
            if( isOperator == false )
            {
                isOperator = true;
                sCurrentText.clear();
            }
            ui.edtCalculated->setText( sCurrentText + sBtn );
        }
        else
        {
            ui.edtInput->setText( sInputText + sBtn );
            isOperator = false;
        }
    }
    else
    {
        ui.edtCalculated->setText( sCurrentText + sBtn );
    }

    // 중간에 ' , ' 넣기
    QVector<QString> vecText;
    QMap<int, QString> mapCommaPos;
    int nCommaCount = 0;

    // 문자열이 4개 이상이며, 콤마가 nCommaCount 갯수에 맞게 들어있다면 return;
    if( sCurrentText.count() > 3 )
    {
    	QString sCommaText = ",";
    	
    	for( int idx = 0; idx < sCurrentText.count(); idx++ )
		{
            vecText.append( sCurrentText.at( idx ) );

            if( vecText.at( idx ) == sCommaText )
            {
                nCommaCount++;
                mapCommaPos.insert( idx, sCommaText );
            }
		}

        int nTextCount = vecText.count() - nCommaCount;
        int nMustExistCommaCount = nTextCount / 3;

        for( auto it = vecText.end() - 3; it != vecText.begin(); it -= 3 )
        {

            if( nCommaCount == nMustExistCommaCount )
            {
                break;
            }

            // vec에 ,가 들어있는 위치에 ,가 있는지 확인하고 맞으면 skip;
            int nIndex = mapCommaPos.key( sCommaText );

            if( vecText.at( nIndex ) == sCommaText )
            {
                continue;
            }
            vecText.insert( it, sCommaText );
            nCommaCount++;
        }

        QString outputText;
        for( auto it = vecText.begin(); it != vecText.end(); ++it )
        {
            outputText += it;
        }

        ui.edtCalculated->setText( outputText );
	    
    }
}

void Qcalculate::on_btnZero_clicked()
{
    QString sBtnZeroText = ui.btnZero->text();
    QString sCurrentText = ui.edtCalculated->text();

    decidePrint(sBtnZeroText, sCurrentText);

}

void Qcalculate::on_btnOne_clicked()
{
    QString sBtnOneText = ui.btnOne->text();
    QString sCurrentText = ui.edtCalculated->text();

    decidePrint( sBtnOneText, sCurrentText );
}
    

void Qcalculate::on_btnTwo_clicked()
{
    QString sBtnTwoText = ui.btnTwo->text();
    QString sCurrentText = ui.edtCalculated->text();

    decidePrint( sBtnTwoText, sCurrentText );
}

void Qcalculate::on_btnThree_clicked()
{
    QString sBtnThreeText = ui.btnThree->text();
    QString sCurrentText = ui.edtCalculated->text();

    decidePrint( sBtnThreeText, sCurrentText );
}

void Qcalculate::on_btnFour_clicked()
{
    QString sBtnFourText = ui.btnFour->text();
    QString sCurrentText = ui.edtCalculated->text();

    decidePrint( sBtnFourText, sCurrentText );
}

void Qcalculate::on_btnFive_clicked()
{
    QString sBtnFiveText = ui.btnFive->text();
    QString sCurrentText = ui.edtCalculated->text();

    decidePrint( sBtnFiveText, sCurrentText );
}

void Qcalculate::on_btnSix_clicked()
{
    QString sBtnSixText = ui.btnSix->text();
    QString sCurrentText = ui.edtCalculated->text();

    decidePrint( sBtnSixText, sCurrentText );
}

void Qcalculate::on_btnSeven_clicked()
{
    QString sBtnSevenText = ui.btnSeven->text();
    QString sCurrentText = ui.edtCalculated->text();

    decidePrint( sBtnSevenText, sCurrentText );
}

void Qcalculate::on_btnAte_clicked()
{
    QString sBtnAteText = ui.btnAte->text();
    QString sCurrentText = ui.edtCalculated->text();

    decidePrint( sBtnAteText, sCurrentText );
}

void Qcalculate::on_btnNine_clicked()
{
    QString sBtnNineText = ui.btnNine->text();
    QString sCurrentText = ui.edtCalculated->text();

    decidePrint( sBtnNineText, sCurrentText );
}

void Qcalculate::decideForOperatorPrint(const QString& sCurrentText, QString& sInputText, const QString& sBtnText)
{
	if( sCurrentText.isEmpty() == true )
	{
        return;
	}

	if( sInputText.endsWith( "+" ) == true ||
		sInputText.endsWith( "-" ) == true ||
		sInputText.endsWith( "*" ) == true ||
		sInputText.endsWith( "/" ) == true )
	{
		sInputText.chop(1);
		ui.edtInput->setText( sInputText + sBtnText );
	}

	ui.edtInput->setText( sCurrentText + sBtnText );
}

void Qcalculate::on_btnMulti_clicked()
{
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();
    QString sBtnMultiText = ui.btnMulti->text();

    decideForOperatorPrint( sCurrentText, sInputText, sBtnMultiText );
}

void Qcalculate::on_btnDivide_clicked()
{
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();
    QString sBtnDivideText = ui.btnDivide->text();

    decideForOperatorPrint( sCurrentText, sInputText, sBtnDivideText );
}

void Qcalculate::on_btnAdd_clicked()
{
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();
    QString sBtnAddText = ui.btnAdd->text();

    decideForOperatorPrint( sCurrentText, sInputText, sBtnAddText );
}

void Qcalculate::on_btnMinus_clicked()
{
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();
    QString sBtnMinus = ui.btnMinus->text();

    decideForOperatorPrint( sCurrentText, sInputText, sBtnMinus );
}

void Qcalculate::on_btnEqual_clicked()
{
    QString sInputText = ui.edtInput->text();

    if( sInputText.isEmpty() == true )
    {
        return;
    }

    double* dResult = calculated( sInputText );

    // 포인터 -> 값이 들어가기도 하고, 주소가 들어가기도 함

	ui.edtInput->setText( QString::number( *dResult ) );
    ui.edtCalculated->setText( QString::number( *dResult ) );
    
}

void Qcalculate::on_btnClear_clicked()
{
    ui.edtInput->clear();
    ui.edtCalculated->setText( QString::number( 0 ) );
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
    ui.edtCalculated->setText( QString::number( dResult ) );
}

void Qcalculate::on_btnSign_clicked()
{
    double sCurrentText = ui.edtInput->text().toDouble();
    
    if ( sCurrentText < 0 )
    {
        ui.edtCalculated->setText( QString::number( abs( sCurrentText ) ) );
        ui.edtInput->setText( QString::number( abs( sCurrentText ) ) );
    }
    else
    {
		ui.edtCalculated->setText( QString::number( sCurrentText * -1 ) );
        ui.edtInput->setText( QString::number( sCurrentText * -1 ) );
    }
}

void Qcalculate::on_btnDivideX_clicked()
{
    QString sCurrentText = ui.edtInput->text();

    ui.edtInput->setText( ( "1/"  "(" + sCurrentText + ")" ) );
    ui.edtCalculated->setText( QString::number( 1 / sCurrentText.toDouble() ) );
}

void Qcalculate::on_btnRoot_clicked()
{
    QString sCurrentText = ui.edtInput->text();

	ui.edtInput->setText( ( "sqrt(" + sCurrentText + ")" ) );
    ui.edtCalculated->setText( QString::number( sqrt( sCurrentText.toDouble() ) ) );
}

void Qcalculate::on_btnPersent_clicked()
{
    QString sCurrentText = ui.edtInput->text();
    double dFirst;
    double dSecond;
    double dResult;
    
    if( sCurrentText.contains( "+" ) == true )
    {

        QStringList sLstText = sCurrentText.split( "+" );

        if( sLstText.size() == 2 )
        {
            dFirst = sLstText.at( 0 ).toDouble();
            dSecond = sLstText.at( 1 ).toDouble();

            dResult = dFirst / dSecond;
        }

        ui.edtInput->setText( QString::number( dFirst ) + "+" + QString::number( dResult ) );
        ui.edtCalculated->setText( QString::number( dResult ) );
    }
    else if( sCurrentText.contains( "-" ) == true )
    {
        QStringList sLstText = sCurrentText.split( "-" );
        
        if ( sLstText.size() == 2)
        {
            dFirst = sLstText.at( 0 ).toDouble();
            dSecond = sLstText.at( 1 ).toDouble();

            dResult = dFirst / dSecond;
        }

        ui.edtInput->setText( QString::number( dFirst ) + "-" + QString::number( dResult ) );
        ui.edtCalculated->setText( QString::number( dResult ) );
    }
    else if ( sCurrentText.contains( "*" ) == true )
    {
        QStringList sLstText = sCurrentText.split( "*" );

        if (sLstText.size() == 2)
        {
            dFirst = sLstText.at( 0 ).toDouble();
            dSecond = sLstText.at( 1 ).toDouble();

            dResult = dFirst / dSecond;
        }

        ui.edtInput->setText( QString::number( dFirst ) + "*" + QString::number( dResult ) );
        ui.edtCalculated->setText( QString::number( dResult ) );
	}
    else
    {
        QStringList sLstText = sCurrentText.split( "/" );

        if (sLstText.size() == 2)
        {
            dFirst = sLstText.at( 0 ).toDouble();
            dSecond = sLstText.at( 1 ).toDouble();

            dResult = dFirst / dSecond;
        }
        ui.edtInput->setText( QString::number( dFirst ) + "/" + QString::number( dResult ) );
        ui.edtCalculated->setText( QString::number( dResult ) );
    }

}

//vec
void Qcalculate::on_btnMs_clicked()
{
    QString sCurrentText = ui.edtInput->text();

    // 첫번째 데이터 삽입.
    vecData.insert( 0, sCurrentText );

    addDataFrame( sCurrentText );
}

void Qcalculate::on_btnMP_clicked()
{
    double dEndData = vecData.begin()->toDouble();
	double dCurrentText = ui.edtInput->text().toDouble();

    ui.edtInput->setText( QString::number( dCurrentText ));

    updateLayoutMemory(QString::number( dEndData + dCurrentText ));
}

void Qcalculate::on_btnMM_clicked()
{
	double dEndData = vecData.begin()->toDouble();
    double dCurrentText = ui.edtInput->text().toDouble();

    ui.edtInput->setText( QString::number( dCurrentText ) );

    updateLayoutMemory( QString::number( dEndData - dCurrentText ) );
    
}

void Qcalculate::on_btnMc_clicked()
{
    deleteLayoutMemory();
}

void Qcalculate::on_btnMr_clicked()
{
    double dEndData = vecData.begin()->toDouble();
    ui.edtInput->setText( QString::number( dEndData ) );
}

void Qcalculate::on_btnRegister_clicked()
{
    ui.stackedWidget->setCurrentIndex( 0 );
}

void Qcalculate::on_btnMemory_clicked()
{
    ui.stackedWidget->setCurrentIndex( 1 );
}

void Qcalculate::addDataFrame( const QString& dataValue )
{
    QFrame* frame = new QFrame();
    frame->setFrameShape( QFrame::StyledPanel );
    frame->setStyleSheet( "border: none;" );

    QVBoxLayout* frameLayout = new QVBoxLayout( frame );
    QLabel* label = new QLabel( dataValue, frame );
	label->setObjectName( "labelMemory");
    frameLayout->addWidget( label );

	QLayout* layout = ui.scrollAreaWidgetContents->layout();
    if (layout == nullptr)
    {
        layout = new QVBoxLayout( ui.scrollAreaWidgetContents );
    }

    QVBoxLayout* vLayout = qobject_cast< QVBoxLayout* >( layout );

    // 맨 첫번째로 삽입
    vLayout->insertWidget( 0, frame );
}

void Qcalculate::updateLayoutMemory( const QString& dataValue )
{
    vecData.insert( 0, dataValue );
    QLayout* layout = ui.scrollAreaWidgetContents->layout();
    QLayoutItem* item = layout->itemAt( 0 );

    if( item == nullptr )
    {
        return;
    }

    QWidget* widget = item->widget();

    if( widget == nullptr)
    {
        return;
    }
	
	QLabel* label = widget->findChild<QLabel*>( "labelMemory" );
        
	if( label == nullptr )
	{
        return;
    }

    label->setText( dataValue );

}

void Qcalculate::deleteLayoutMemory()
{
    QLayout* layout = ui.scrollAreaWidgetContents->layout();

    if( layout->count() == 0 )
    {
        return;
    }

	QLayoutItem* item = layout->takeAt( 0 );
    QWidget* widget = item->widget();

    delete widget;
    widget = nullptr;
}
















