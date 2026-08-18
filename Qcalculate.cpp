#include "Qcalculate.h"

#include <valarray>

#include "HoverButton.h"
#include "MemoryWidget.h"
#include "RegisterWidget.h"

Qcalculate::Qcalculate(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowOpacity( 0.99 );
    ui.edtCalculated->setAlignment( Qt::AlignRight );
    ui.edtInput->setAlignment( Qt::AlignRight );

    QWidget* widget = ui.scrollAreaWidgetContents;

}

Qcalculate::~Qcalculate()
{
}

// 연산자 계산
// const QString& 으로 매개변수로 받는 것과, QString* 으로 받는 것의 차이. 

double Qcalculate::calculated( const QString& sInputText )
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

            return dResult;
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

            return dResult;
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

            return dResult;
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
            return dResult;
        }
    }
}


void Qcalculate::insertComma( QString& sCurrentText, const QString& sInputText )
{
    if( sInputText.endsWith( "=" ) )
    {
        return;
    }

    QString sPureText = sCurrentText;
    sPureText.remove( "," );

    if( sPureText.isEmpty() )
    {
        ui.edtCalculated->setText( sPureText );
        sCurrentText = sPureText;
        return;
    }

    QStringList sLiParts = sPureText.split( "." );

    bool ok = false;

    qlonglong lNumber = sLiParts[ 0 ].toLongLong( &ok );

    if( ok == true )
    {
        QLocale locale( QLocale::English );
        QString formattedText = locale.toString( lNumber );

        if( sLiParts.size() > 1 )
        {
            formattedText += "." + sLiParts[ 1 ];
        }
        else if( sPureText.contains( '.' ) ) {
            formattedText += ".";
        }

        sCurrentText = formattedText;
        ui.edtCalculated->setText( sCurrentText );
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
            ui.edtCalculated->setText( sCurrentText += sBtn );
        }
        else
        {
            ui.edtInput->setText( sInputText + sBtn );
            isOperator = false;
            
        }
    }
    else
    {
        ui.edtCalculated->setText( sCurrentText += sBtn );
    }
}

void Qcalculate::ifCalculatedThenClearText( QString& sCurrentText, QString& sBtnText, const QString& sInputText )
{
    if( sCurrentText.isEmpty() == false && sInputText.endsWith( "=" ) )
    {
        ui.edtInput->clear();
        ui.edtCalculated->clear();

        ui.edtCalculated->setText( sBtnText );
        isOperator = false;
    }

}

void Qcalculate::on_btnZero_clicked()
{
    QString sBtnZeroText = ui.btnZero->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    decidePrint(sBtnZeroText, sCurrentText);
	ifCalculatedThenClearText(sCurrentText, sBtnZeroText, sInputText);
    insertComma( sCurrentText, sInputText );
	
}

void Qcalculate::on_btnOne_clicked()
{
    QString sBtnOneText = ui.btnOne->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    decidePrint( sBtnOneText, sCurrentText );
    ifCalculatedThenClearText( sCurrentText, sBtnOneText, sInputText );
	insertComma( sCurrentText, sInputText );

}
    

void Qcalculate::on_btnTwo_clicked()
{
    QString sBtnTwoText = ui.btnTwo->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    decidePrint( sBtnTwoText, sCurrentText );
    ifCalculatedThenClearText( sCurrentText, sBtnTwoText, sInputText );
    insertComma( sCurrentText, sInputText );

}

void Qcalculate::on_btnThree_clicked()
{
    QString sBtnThreeText = ui.btnThree->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    decidePrint( sBtnThreeText, sCurrentText );
    ifCalculatedThenClearText( sCurrentText, sBtnThreeText, sInputText );
    insertComma( sCurrentText, sInputText );

}

void Qcalculate::on_btnFour_clicked()
{
    QString sBtnFourText = ui.btnFour->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    decidePrint( sBtnFourText, sCurrentText );
    ifCalculatedThenClearText( sCurrentText, sBtnFourText, sInputText );
    insertComma( sCurrentText, sInputText );

}

void Qcalculate::on_btnFive_clicked()
{
    QString sBtnFiveText = ui.btnFive->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    decidePrint( sBtnFiveText, sCurrentText );
    ifCalculatedThenClearText( sCurrentText, sBtnFiveText, sInputText );
	insertComma( sCurrentText, sInputText );

}

void Qcalculate::on_btnSix_clicked()
{
    QString sBtnSixText = ui.btnSix->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    decidePrint( sBtnSixText, sCurrentText );
    ifCalculatedThenClearText( sCurrentText, sBtnSixText, sInputText );
    insertComma( sCurrentText, sInputText );

}

void Qcalculate::on_btnSeven_clicked()
{
    QString sBtnSevenText = ui.btnSeven->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    decidePrint( sBtnSevenText, sCurrentText );

    ifCalculatedThenClearText( sCurrentText, sBtnSevenText, sInputText );
    insertComma( sCurrentText, sInputText );
}

void Qcalculate::on_btnAte_clicked()
{
    QString sBtnAteText = ui.btnAte->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    decidePrint( sBtnAteText, sCurrentText );
    ifCalculatedThenClearText( sCurrentText, sBtnAteText, sInputText );
    insertComma( sCurrentText, sInputText );
}

void Qcalculate::on_btnNine_clicked()
{
    QString sBtnNineText = ui.btnNine->text();
    QString sCurrentText = ui.edtCalculated->text();
    QString sInputText = ui.edtInput->text();

    decidePrint( sBtnNineText, sCurrentText );
    ifCalculatedThenClearText( sCurrentText, sBtnNineText, sInputText );
    insertComma( sCurrentText, sInputText );

}

void Qcalculate::decideForOperatorPrint( QString& sCurrentText, QString& sInputText, const QString& sBtnText)
{

	if( sCurrentText.isEmpty() == true )
	{
        return;
	}

    // 다른 연사자가 있을때, 연사자 교체
    if(
    	sInputText.endsWith( "+" ) == true ||
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
    isOperator = false;

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

    // = 연산자 계속 계산
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

    dResult = calculated( sInputText += sCurrentText );

    // 포인터 -> 값이 들어가기도 하고, 주소가 들어가기도 함

    ui.edtInput->setText( sInputText += "=" );

    ui.edtCalculated->setText( QString::number( dResult, 'g', 16 ) );

    QString calcuText =  ui.edtCalculated->text();
	insertComma( calcuText, sInputText );

    // 기록 하기.
    isPageOne = true;
	addDataFrame( isPageOne, sInputText + QString::number( dResult, 'g', 16 ) );

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

    QLineEdit* edt = ui.edtCalculated;
    
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

    deleteLayoutRegister();
}

void Qcalculate::addDataFrame(const bool& isPageOne, const QString& dataValue )
{
    if( isPageOne == true )
    {
        ui.edtInfo->hide();

        QStringList sLiText = dataValue.split("=");
        const QString& sTextFirst = sLiText.at( 0 ) + '=';
        const QString& sTextSecond = sLiText.at( 1 );

        QWidget* widgetContents = ui.scrollAreaWidgetContents_2;

		RegisterWidget* registerWidget = new RegisterWidget(widgetContents, sTextFirst, sTextSecond);
        registerWidget->setFixedHeight(70);
        registerWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

        QLayout* layout = widgetContents->layout();

        if (layout == nullptr)
        {
            layout = new QVBoxLayout(widgetContents);
            layout->setContentsMargins(0, 0, 0, 0);
            layout->setSpacing(0);
        }

        QVBoxLayout* vLayout = qobject_cast<QVBoxLayout*>(layout);

        if (vLayout)
        {
            vLayout->insertWidget(0, registerWidget);

        }

        vLayout->addStretch();

    }
    else
    {
        
        ui.edtInfo2->hide();

        QWidget* widgetContents = ui.scrollAreaWidgetContents;

		MemoryWidget* memoryWidget = new MemoryWidget(widgetContents, dataValue);
        memoryWidget->setFixedHeight(70);
		memoryWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

        QLayout* layout = widgetContents->layout();

        if (layout == nullptr)
        {
			layout = new QVBoxLayout(widgetContents);
			layout->setContentsMargins(0, 0, 0, 0);
			layout->setSpacing(0);
        }

		QVBoxLayout* vLayout = qobject_cast<QVBoxLayout*>(layout);

        if (vLayout)
        {
            vLayout->insertWidget(0, memoryWidget);
			
        }

        vLayout->addStretch();

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
















