#pragma once

#include <QWidget>
#include "ui_TWindow.h"
#include "Subject.h"
#include "Controller.h"

class TWindow : public QWidget, public Subject
{
	Q_OBJECT

public:
	TWindow(Controller ctrl,QWidget *parent = Q_NULLPTR) :ctrl{ ctrl }, QWidget(parent) { }
	void notifica() { this->notify(); }
	~TWindow() {};

private:
	Ui::TWindow ui;
	Controller ctrl;
};
