#include "HoverButton.h"

#include <qcoreevent.h>

HoverButton::HoverButton( QWidget* target, QWidget* parent )
	:QPushButton( parent ), wTarget( target )
{
	if (wTarget)
	{
		// target의 이벤트를 가로채기
		wTarget->installEventFilter( this );
	}

	QSizePolicy sp = this->sizePolicy();
	sp.setRetainSizeWhenHidden( true );
	this->setSizePolicy( sp );

	this->setVisible( true );
	
}

HoverButton::~HoverButton()
{
}

/*
void HoverButton::enterEvent( QEvent* event )
{
	QPushButton::enterEvent( event );
	wTarget->show();
} 
*/

void HoverButton::enterEvent(QEvent* event)
{
}

bool HoverButton::eventFilter(QObject* target, QEvent* event)
{
	if( target == wTarget )
	{
		if( event->type() == QEvent::Enter )
		{
			this->setVisible( true );
			this->setEnabled( true );
		}
		else if( event->type() == QEvent::Leave )
		{
			this->setVisible( false );
			this->setEnabled( false );
		}
	}
	return QPushButton::eventFilter(target, event);
}

