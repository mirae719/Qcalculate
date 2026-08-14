#include "test.h"

#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>

#include "HoverButton.h"

test::test(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QFrame* mainFrame = ui.mainFrame;
	mainFrame->setStyleSheet( "QFrame:hover{"
							  "background-color: #eaeaea;"
							  "}"
							  "QFrame {"
							  "background-color: #eff5f4;"
							  "}" );

	mainFrame->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
	
	QVBoxLayout* v_layout = new QVBoxLayout( mainFrame );

	QFrame* frame2 = new QFrame( mainFrame );
	QFrame* frame3 = new QFrame( mainFrame );
	
	v_layout->addWidget( frame2 );
	v_layout->addWidget( frame3 );

	v_layout->setContentsMargins( 0, 0, 0, 0 );
	v_layout->setSpacing( 0 );

	frame2->setStyleSheet(
		"background-color: transparent;" );
	frame3->setStyleSheet(
		"background-color: transparent;" );

	frame2->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
	frame3->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );

	QLineEdit* edtTextBox = new QLineEdit( frame2 );

	edtTextBox->setStyleSheet( "border: none;"
								"font: 15pt '맑은 고딕';" );
	edtTextBox->setEnabled( false );

	QSpacerItem* leftSpacer1 = new QSpacerItem(300, 30, QSizePolicy::Expanding, QSizePolicy::Minimum );
	QSpacerItem* leftSpacer2 = new QSpacerItem(300, 30, QSizePolicy::Expanding, QSizePolicy::Minimum );

	QHBoxLayout* h_layout = new QHBoxLayout( frame2 );
	h_layout->setContentsMargins( 0, 0, 0, 0 );
	h_layout->addItem( leftSpacer1 );
	h_layout->addWidget( edtTextBox );

	QHBoxLayout* h_layout2 = new QHBoxLayout( frame3 );

	HoverButton* hBtnMC = new HoverButton( mainFrame, this );
	hBtnMC->setText( "MC" );

	HoverButton* hBtnMP = new HoverButton( mainFrame, this );
	hBtnMP->setText( "M+" );

	HoverButton* hBtnMM = new HoverButton( mainFrame, this );
	hBtnMM->setText( "M-" );

	h_layout2->setContentsMargins( 0, 0, 0, 0 );
	h_layout2->addItem( leftSpacer2 );
	h_layout2->addWidget( hBtnMC );
	h_layout2->addWidget( hBtnMP );
	h_layout2->addWidget( hBtnMM );

}


test::~test()
{}
