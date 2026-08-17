#include "MemoryWidget.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include "HoverButton.h"

MemoryWidget::MemoryWidget(QWidget *parent, const QString& data)
	: QWidget(parent), dataValue(data)
{
	ui.setupUi(this);

	QFrame* mainFrame = ui.mainFrame;
	mainFrame->setStyleSheet("QFrame:hover{"
								"background-color: #eaeaea;"
								"}" 
								"QFrame {"
								"background-color: #eff5f4;"
								"color: #191919;"
								"}" );

	mainFrame->setSizePolicy( QSizePolicy::Fixed, QSizePolicy::Fixed );
	mainFrame->setMinimumSize(310, 67);
	mainFrame->setMaximumSize(500, 67);
	mainFrame->setFrameShape(QFrame::NoFrame);
	mainFrame->setLineWidth(0);

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

	frame2->setMinimumSize(310, 33);
	frame3->setMaximumSize(500, 32);

	frame2->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed);
	frame3->setSizePolicy( QSizePolicy::Preferred, QSizePolicy::Fixed);

	QLineEdit* edtTextBox = new QLineEdit( data, frame2 );

	edtTextBox->setStyleSheet( "border: none;"
								"font: 15pt '맑은 고딕';" );
	edtTextBox->setEnabled( false );
	edtTextBox->setMinimumSize(200, 20);
	edtTextBox->setMaximumSize(200, 20);
	edtTextBox->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	edtTextBox->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

	QSpacerItem* leftSpacer1 = new QSpacerItem(700, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );
	QSpacerItem* leftSpacer2 = new QSpacerItem(300, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );

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

	hBtnMC->setStyleSheet("QPushButton{"
							" background-color: #f8f9fb;"
							" border-radius: 5px;"
							" border: 1px solid #dcdcdc;"
							"}"
							"QPushButton:hover{"
							" background-color: #f2f2f2;"
							"}");

	hBtnMP->setStyleSheet("QPushButton{"
							" background-color: #f8f9fb;"
							" border-radius: 5px;"
							" border: 1px solid #dcdcdc;"
							"}"
							"QPushButton:hover{"
							" background-color: #f2f2f2;"
							"}");

	hBtnMM->setStyleSheet("QPushButton{"
							" background-color: #f8f9fb;"
							" border-radius: 5px;"
							" border: 1px solid #dcdcdc;"
							"}"
							"QPushButton:hover{"
							" background-color: #f2f2f2;"
							"}");

	hBtnMC->setVisible(true);
	hBtnMC->setEnabled(true);
	hBtnMP->setVisible(true);
	hBtnMP->setEnabled(true);
	hBtnMM->setVisible(true);
	hBtnMM->setEnabled(true);

	h_layout2->setContentsMargins( 0, 0, 0, 0 );
	h_layout2->addItem( leftSpacer2 );
	h_layout2->addWidget( hBtnMC );
	h_layout2->addWidget( hBtnMP );
	h_layout2->addWidget( hBtnMM );

}

MemoryWidget::~MemoryWidget()
{}
