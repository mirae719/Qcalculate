#pragma once

#include <ui_MemoryWidget.h>
#include <QWidget>

class MemoryWidget : public QWidget
{
	Q_OBJECT

private:
	const QString& dataValue;

public:
	MemoryWidget( QWidget* parent = nullptr, const QString& data = nullptr );
	~MemoryWidget();

private:
	Ui::widget ui;
};
