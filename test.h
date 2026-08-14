#pragma once

#include <QMainWindow>
#include "ui_test.h"

class test : public QMainWindow
{
	Q_OBJECT

public:
	test(QWidget *parent = nullptr);
	~test();

private:
	Ui::test ui;
};
