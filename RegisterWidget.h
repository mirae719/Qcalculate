#pragma once

#include <ui_MemoryWidget.h>
#include <QWidget>

class RegisterWidget : public QWidget
{
	Q_OBJECT

private:
	const QString& sTextFirst;
	const QString& sTextSecond;

public:
	RegisterWidget( QWidget* parent = nullptr, const QString& sTextFirst = nullptr, const QString& sTextSecond = nullptr);
	~RegisterWidget();

private:
	Ui::widget ui;
};
