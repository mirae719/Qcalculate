#pragma once
#include <QPushButton>

class HoverButton : public QPushButton
{
	Q_OBJECT

protected:
	void enterEvent( QEvent* event ) override;
	bool eventFilter( QObject* watched, QEvent* event ) override;

public:
	explicit HoverButton( QWidget* target, QWidget* parent = nullptr );
	~HoverButton();

private:
	QWidget* wTarget;

};

