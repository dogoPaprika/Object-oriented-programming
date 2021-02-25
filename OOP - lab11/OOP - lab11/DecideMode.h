#pragma once

#include <QWidget>
#include "ui_DecideMode.h"
#include "UserMode.h"
#include "Administrator.h"

class DecideMode : public QWidget
{
	Q_OBJECT

public:
	DecideMode(QWidget *parent = Q_NULLPTR);
	~DecideMode();
	DecideMode(Controller* c, int argc, char* argv[], QWidget * parent = Q_NULLPTR);

private:
	Ui::DecideMode ui;

	Controller* controller;
	int argc;
	char** argv;

private slots:
	void goToUser();
	void goToAdmin();
};

