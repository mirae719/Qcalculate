#pragma once

#include <ui_MemoryWidget.h>
#include <QMainWindow>

class MemoryWidget : public QMainWindow
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
