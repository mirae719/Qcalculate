#include "Qcalculate.h"
#include "QMessageBox"


Qcalculate::Qcalculate(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.edtCalculated->setAlignment( Qt::AlignRight );
    ui.edtInput->setAlignment( Qt::AlignRight );
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

void Qcalculate::insertComma(QString& sCurrentText)
{
	// 중간에 ' , ' 넣기
	QVector<QString> vecText;
	QMap<int, QString> mapCommaPos;
	int nCommaCount = 0;

	// 문자열이 4개 이상이며, 콤마가 nCommaCount 갯수에 맞게 들어있다면 return;
	if( sCurrentText.count() >= 4 )
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

		int nTextCount = vecText.count() - nCommaCount; // 현재 출력된 문자열에서 콤마만 뺀 갯수;
		int nMustExistCommaCount = nTextCount / 3; // 반드시 있어야 할 콤마 갯수
		QList<int> liCommaIdx = mapCommaPos.keys();  // comma 위치가 들어있는 인덱스 추출;

		for( auto it = vecText.end() - 3; it != vecText.begin(); it -= 3 )
		{

			if( nCommaCount == nMustExistCommaCount )
			{
				break;
			}

			// vec에 ,가 들어있는 위치에 ,가 있는지 확인하고 맞으면 skip;
			for( int idx = 0; 0 < liCommaIdx.count(); idx++ )
				if( vecText.at( liCommaIdx.at( idx ) ) == sCommaText )
				{
					continue;
				}

			vecText.insert( it, sCommaText );
			nCommaCount++;
		}

		QString sOutputText;
		for( auto it = vecText.begin(); it != vecText.end(); ++it )
		{
			sOutputText += it;
			ui.edtCalculated->setText( sOutputText );
		}

	}
}

void Qcalculate::decidePrint( const QString& sBtn, QString& sCurrentText )
{
    if( sCurrentText.count() == 1 && sCurrentText.contains( "0" ) )
    {

        sCurrentText.clear();

    }

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
}

void Qcalculate::ifCalculatedThanClearText(const QString& sBtnText, const QString& sInputText)
{
	if( sInputText.isEmpty() == false && sInputText.endsWith( "=" ) )
	{
		ui.edtInput->clear();
        ui.edtCalculated->clear();
		ui.edtCalculated->setText( sBtnText );
	}
}

void Qcalculate::on_btnZero_clicked()
{
    QString sBtnZeroText = ui.btnZero->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    ifCalculatedThanClearText(sBtnZeroText, sInputText);

    decidePrint(sBtnZeroText, sCurrentText);
    insertComma( sCurrentText );

}

void Qcalculate::on_btnOne_clicked()
{
    QString sBtnOneText = ui.btnOne->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    ifCalculatedThanClearText( sBtnOneText, sInputText );

    decidePrint( sBtnOneText, sCurrentText );
    insertComma( sCurrentText );
}
    

void Qcalculate::on_btnTwo_clicked()
{
    QString sBtnTwoText = ui.btnTwo->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    ifCalculatedThanClearText( sBtnTwoText, sInputText );

    decidePrint( sBtnTwoText, sCurrentText );
    insertComma( sCurrentText );
}

void Qcalculate::on_btnThree_clicked()
{
    QString sBtnThreeText = ui.btnThree->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    ifCalculatedThanClearText( sBtnThreeText, sInputText );

    decidePrint( sBtnThreeText, sCurrentText );
    insertComma( sCurrentText );
}

void Qcalculate::on_btnFour_clicked()
{
    QString sBtnFourText = ui.btnFour->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    ifCalculatedThanClearText( sBtnFourText, sInputText );

    decidePrint( sBtnFourText, sCurrentText );
    insertComma( sCurrentText );
}

void Qcalculate::on_btnFive_clicked()
{
    QString sBtnFiveText = ui.btnFive->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    ifCalculatedThanClearText( sBtnFiveText, sInputText );

    decidePrint( sBtnFiveText, sCurrentText );
    insertComma( sCurrentText );
}

void Qcalculate::on_btnSix_clicked()
{
    QString sBtnSixText = ui.btnSix->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    ifCalculatedThanClearText( sBtnSixText, sInputText );

    decidePrint( sBtnSixText, sCurrentText );
    insertComma( sCurrentText );
}

void Qcalculate::on_btnSeven_clicked()
{
    QString sBtnSevenText = ui.btnSeven->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    ifCalculatedThanClearText( sBtnSevenText, sInputText );

    decidePrint( sBtnSevenText, sCurrentText );
    insertComma( sCurrentText );
}

void Qcalculate::on_btnAte_clicked()
{
    QString sBtnAteText = ui.btnAte->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    ifCalculatedThanClearText( sBtnAteText, sInputText );

    decidePrint( sBtnAteText, sCurrentText );
    insertComma( sCurrentText );
}

void Qcalculate::on_btnNine_clicked()
{
    QString sBtnNineText = ui.btnNine->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    ifCalculatedThanClearText( sBtnNineText, sInputText );

    decidePrint( sBtnNineText, sCurrentText );
    insertComma( sCurrentText );
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

void Qcalculate::removeComma(QString& sCurrentText)
{
	if( sCurrentText.contains( "," ) && isRemove == false )
	{
		sCurrentText.remove( "," );
		ui.edtInput->setText( sCurrentText ); 
		isRemove = true;
	} else
	{
		isRemove = false;
	}
}

void Qcalculate::on_btnMulti_clicked()
{
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();
    QString sBtnMultiText = ui.btnMulti->text();

    removeComma(sCurrentText);
	decideForOperatorPrint( sCurrentText, sInputText, sBtnMultiText );

}

void Qcalculate::on_btnDivide_clicked()
{
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();
    QString sBtnDivideText = ui.btnDivide->text();

    removeComma( sCurrentText );
    decideForOperatorPrint( sCurrentText, sInputText, sBtnDivideText );
}

void Qcalculate::on_btnAdd_clicked()
{
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();
    QString sBtnAddText = ui.btnAdd->text();

    removeComma( sCurrentText );
    decideForOperatorPrint( sCurrentText, sInputText, sBtnAddText );
}

void Qcalculate::on_btnMinus_clicked()
{
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();
    QString sBtnMinus = ui.btnMinus->text();

    removeComma( sCurrentText );
    decideForOperatorPrint( sCurrentText, sInputText, sBtnMinus );
}

void Qcalculate::on_btnEqual_clicked()
{
    QString sInputText = ui.edtInput->text();
    QString sCurrentText = ui.edtCalculated->text();
    sCurrentText.remove( "," );

    if( sCurrentText.endsWith( "." ) )
    {
        sInputText = sCurrentText.remove( "." );

        ui.edtInput->setText( sInputText += "=" );
        ui.edtCalculated->setText( sCurrentText );

        isPageOne = true;
        addDataFrame( isPageOne, sInputText + sCurrentText );
        return;
    }

			
    if( sInputText.isEmpty() == true )
    {
        if( sCurrentText.isEmpty() == false )
        {
            ui.edtInput->setText( sCurrentText + "=" );
        }
    	return;
    }

    // = 연사자 계속 계산
    if( sInputText.contains( "=" ) )
    {
        if( sInputText.contains( "+" ) == true )
        {
			QStringList sLiText = sInputText.split( "+" );
            QString sTextSecond = sLiText.at( 1 );
            sTextSecond.remove( "=" );

            sInputText = sCurrentText + "+";
            sCurrentText = sTextSecond;
        }
        else if( sInputText.contains( "-" ) == true )
        {
            QStringList sLiText = sInputText.split( "-" );
            QString sTextSecond = sLiText.at( 1 );
            sTextSecond.remove( "=" );

            sInputText = sCurrentText + "-";
            sCurrentText = sTextSecond;
        }
        else if( sInputText.contains( "X" ) == true )
        {
            QStringList sLiText = sInputText.split( "X" );
            QString sTextSecond = sLiText.at( 1 );
            sTextSecond.remove( "=" );

            sInputText = sCurrentText + "X";
            sCurrentText = sTextSecond;
        }
        else if( sInputText.contains( "÷" ) == true )
        {
            QStringList sLiText = sInputText.split( "÷" );
            QString sTextSecond = sLiText.at( 1 );
            sTextSecond.remove( "=" );

            sInputText = sCurrentText + "÷";
            sCurrentText = sTextSecond;
        }
        else
        {
            isPageOne = true;
            addDataFrame( isPageOne, sInputText + sCurrentText );
            return;
        }
    }

    double* dResult = calculated( sInputText += sCurrentText );

    // 포인터 -> 값이 들어가기도 하고, 주소가 들어가기도 함

    ui.edtInput->setText( sInputText += "=" );
    ui.edtCalculated->setText( QString::number( *dResult, 'g', 16 ) );

    // 기록 하기.
    isPageOne = true;
	addDataFrame( isPageOne, sInputText + QString::number( *dResult, 'g', 16 ) );

}

void Qcalculate::on_btnClear_clicked()
{
    ui.edtInput->clear();
    ui.edtCalculated->setText( QString::number( 0 ) );
}

void Qcalculate::on_btnErase_clicked()
{
    QString sCurrentText = ui.edtCalculated->text();

    if ( sCurrentText.isEmpty() == false)
    {
        sCurrentText.chop( 1 );
        ui.edtCalculated->setText( sCurrentText );
    }
}

void Qcalculate::on_btnDot_clicked()
{
    QString sCurrentText = ui.edtCalculated->text();
    QString sBtnDotText = ui.btnDot->text();

    if ( sCurrentText.contains( "." ) == true )
    {
        return;
    }

    ui.edtCalculated->setText( sCurrentText + sBtnDotText );
}

void Qcalculate::on_btnSquare_clicked()
{
    QString sCurrentText = ui.edtCalculated->text();

    double dCurrent = sCurrentText.toDouble();

    double dResult = pow( dCurrent, 2 );

    ui.edtInput->setText( ( "sqr(" + sCurrentText + ")" ) );
    ui.edtCalculated->setText( QString::number( dResult, 'g', 16 ) );
}

void Qcalculate::on_btnSign_clicked()
{
    double sCurrentText = ui.edtCalculated->text().toDouble();
    
    if ( sCurrentText < 0 )
    {
        ui.edtCalculated->setText( QString::number( abs( sCurrentText ), 'g', 16 ) );
    }
    else
    {
		ui.edtCalculated->setText( QString::number( sCurrentText * -1, 'g', 16 ) );
    }
}

void Qcalculate::on_btnDivideX_clicked()
{
    QString sCurrentText = ui.edtCalculated->text();

    ui.edtInput->setText( ( "1/"  "(" + sCurrentText + ")" ) );
    ui.edtCalculated->setText( QString::number( 1 / sCurrentText.toDouble(), 'g', 16 ) );
}

void Qcalculate::on_btnRoot_clicked()
{
    QString sCurrentText = ui.edtCalculated->text();

	ui.edtInput->setText( ( "√(" + sCurrentText + ")" ) );
    ui.edtCalculated->setText( QString::number( sqrt( sCurrentText.toDouble() ), 'g', 16 ) );
}

void Qcalculate::on_btnPersent_clicked()
{
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();
    
    if( sCurrentText.endsWith( "+" ) == true )
    {
        sInputText.chop(1);

        dResult = sInputText.toDouble() / sCurrentText.toDouble();

        ui.edtInput->setText( sInputText + "+" + QString::number( dResult, 'g', 16 ) );
        ui.edtCalculated->setText( QString::number( dResult, 'g', 16 ) );
    }
    else if( sCurrentText.endsWith( "-" ) == true )
    {
        sInputText.chop( 1 );

        dResult = sInputText.toDouble() / sCurrentText.toDouble();

        ui.edtInput->setText( sInputText + "-" + QString::number( dResult, 'g', 16 ) );
        ui.edtCalculated->setText( QString::number( dResult, 'g', 16 ) );
    }
    else if ( sCurrentText.endsWith( "X" ) == true )
    {
        sInputText.chop( 1 );

        dResult = sInputText.toDouble() / sCurrentText.toDouble();

        ui.edtInput->setText( sInputText + "X" + QString::number( dResult, 'g', 16 ) );
        ui.edtCalculated->setText( QString::number( dResult, 'g', 16 ) );
	}
    else
    {
        sInputText.chop( 1 );

        dResult = sInputText.toDouble() / sCurrentText.toDouble();

        ui.edtInput->setText( sInputText + "÷" + QString::number( dResult, 'g', 16 ) );
        ui.edtCalculated->setText( QString::number( dResult, 'g', 16 ) );
    }

}

//vec
void Qcalculate::on_btnMs_clicked()
{
    QString sCurrentText = ui.edtCalculated->text();

    // 첫번째 데이터 삽입.
    vecMemoryData.insert( 0, sCurrentText );

    isPageOne = false;
    addDataFrame( isPageOne, sCurrentText );
}

void Qcalculate::on_btnMP_clicked()
{
    double dEndData = vecMemoryData.begin()->toDouble();
	double dCurrentText = ui.edtCalculated->text().toDouble();

    updateLayoutMemory(QString::number( dEndData + dCurrentText, 'g', 16 ));
}

void Qcalculate::on_btnMM_clicked()
{
	double dEndData = vecMemoryData.begin()->toDouble();
    double dCurrentText = ui.edtCalculated->text().toDouble();

    updateLayoutMemory( QString::number( dEndData - dCurrentText, 'g', 16 ) );
}

void Qcalculate::on_btnMc_clicked()
{
    deleteLayoutMemory();
}

void Qcalculate::on_btnMr_clicked()
{
    double dEndData = vecMemoryData.begin()->toDouble();
    ui.edtInput->setText( QString::number( dEndData, 'g', 16 ) );
}

void Qcalculate::on_btnRegister_clicked()
{
    ui.stackedWidget->setCurrentIndex( 0 );
}

void Qcalculate::on_btnMemory_clicked()
{
    ui.stackedWidget->setCurrentIndex( 1 );
}

void Qcalculate::deleteLayoutRegister()
{
	QLayout* layout = ui.scrollAreaWidgetContents_2->layout();

	if( layout->count() == 0 )
	{
        return;
	}

	QLayoutItem* item = layout->takeAt( 0 );
	QWidget* widget = item->widget();

	delete widget;
	widget = nullptr;

	if( layout->count() == 0 )
	{
		ui.edtInfo->show();
	}
}

void Qcalculate::on_btnRegisterClear_clicked()
{
    QLayout* layout = ui.scrollAreaWidgetContents_2->layout();
    if (layout == nullptr)
    {
        return;
    }

    vecRegisterData.clear();
    deleteLayoutRegister();
}

void Qcalculate::addDataFrame(const bool& isPageOne, const QString& dataValue )
{
    if( isPageOne == true )
    {
        ui.edtInfo->hide();

        QStringList sLiText = dataValue.split("=");
        QString sTextFirst = sLiText.at( 0 );
        QString sTextSecond = sLiText.at( 1 );

        vecRegisterData.append( sTextFirst );
        vecRegisterData.append( sTextSecond );

        QFrame* frame = new QFrame();
        frame->setAttribute( Qt::WA_StyledBackground, true );
        frame->setStyleSheet(
            "QFrame{ "
            "   border: none;"
            "   margin-left: auto;"
            "   font-family: '맑은 고딕';"
            "   font-size: 17pt;"
            "   font-weight: bold;"
            "}"
            "QFrame:hover{"
            "   background-color:rgb(234, 234, 234);"
            "}"
            "QLabel:hover{"
            "   background-color:rgb(234, 234, 234);"
            "}"
        );

        QHBoxLayout* frameLayout = new QHBoxLayout( frame );
        QLabel* label = new QLabel( dataValue, frame );
        frameLayout->setContentsMargins( 10, 5, 10, 5 );
        label->setObjectName( "labelMemory" );

        frameLayout->addStretch();
        frameLayout->addWidget( label );

        QLayout* layout = ui.scrollAreaWidgetContents_2->layout();
        if( layout == nullptr )
        {
            layout = new QVBoxLayout( ui.scrollAreaWidgetContents_2 );
        }

        QVBoxLayout* vLayout = qobject_cast< QVBoxLayout* >( layout );
        if( vLayout )
        {
            vLayout->insertWidget( 0, frame );
        }

    }
	else
	{
        ui.edtInfo2->hide();

        QFrame* frame = new QFrame();
        frame->setAttribute( Qt::WA_StyledBackground, true );
        frame->setStyleSheet(
            "QFrame{ "
            "   border: none;"
            "   margin-left: auto;"
            "   font-family: '맑은 고딕';"
            "   font-size: 17pt;"
            "   font-weight: bold;"
            "}"
            "QFrame:hover{"
            "   background-color:rgb(234, 234, 234);"
            "}"
            "QLabel:hover{"
            "   background-color:rgb(234, 234, 234);"
            "}"
        );

        QHBoxLayout* frameLayout = new QHBoxLayout( frame );
        QLabel* label = new QLabel( dataValue, frame );
        frameLayout->setContentsMargins( 10, 5, 10, 5 );
        label->setObjectName( "labelMemory" );

        frameLayout->addStretch();
        frameLayout->addWidget( label );

        QLayout* layout = ui.scrollAreaWidgetContents->layout();
        if( layout == nullptr )
        {
            layout = new QVBoxLayout( ui.scrollAreaWidgetContents );
        }

        QVBoxLayout* vLayout = qobject_cast< QVBoxLayout* >( layout );
        if( vLayout )
        {
            vLayout->insertWidget( 0, frame );
        }

	}
    
}

void Qcalculate::updateLayoutMemory( const QString& dataValue )
{
    vecMemoryData.insert( 0, dataValue );
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

    if (layout->count() == 0)
    {
        ui.edtInfo2->show();
    }
}
















