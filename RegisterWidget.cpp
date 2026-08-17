#include "RegisterWidget.h"
#include <QVBoxLayout>
#include <QLineEdit>

RegisterWidget::RegisterWidget(QWidget *parent, const QString& sTextFirst, const QString& sTextSecond)
	: QWidget(parent), sTextFirst(sTextFirst), sTextSecond(sTextSecond)
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

	QLineEdit* edtTextBox1 = new QLineEdit( sTextFirst, frame2 );

	edtTextBox1->setStyleSheet( "border: none;"
								"font: 15pt '맑은 고딕';" );
	edtTextBox1->setEnabled( false );
	edtTextBox1->setMinimumSize(200, 20);
	edtTextBox1->setMaximumSize(200, 20);
	edtTextBox1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	edtTextBox1->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

	QSpacerItem* leftSpacer1 = new QSpacerItem(700, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );
	QSpacerItem* leftSpacer2 = new QSpacerItem(300, 10, QSizePolicy::Expanding, QSizePolicy::Minimum );

	QHBoxLayout* h_layout = new QHBoxLayout( frame2 );
	h_layout->setContentsMargins( 0, 0, 0, 0 );
	h_layout->addItem( leftSpacer1 );
	h_layout->addWidget(edtTextBox1);

	QHBoxLayout* h_layout2 = new QHBoxLayout( frame3 );

	QLineEdit* edtTextBox2 = new QLineEdit(sTextSecond, frame3);
	edtTextBox2->setStyleSheet("border: none;"
		"font: 15pt '맑은 고딕';");
	edtTextBox2->setEnabled(false);
	edtTextBox2->setMinimumSize(200, 20);
	edtTextBox2->setMaximumSize(200, 20);
	edtTextBox2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	edtTextBox2->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	
	h_layout2->setContentsMargins( 0, 0, 0, 0 );
	h_layout2->addItem( leftSpacer2 );
	h_layout2->addWidget(edtTextBox2);
	

}

RegisterWidget::~RegisterWidget()
{}
