#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUI.h"
#include "Repository.h"
#include <qlistwidget.h>
#include "Controller.h"

class GUI : public QMainWindow
{
	Q_OBJECT

public:
	GUI(QWidget *parent = Q_NULLPTR);
	//GUI(Repository& repo, QWidget *parent = Q_NULLPTR);
	GUI(Controller& controller, QWidget *parent = Q_NULLPTR);

	void initRepo();
	void initPrecipitation();
private:
	Ui::GUIClass ui;

	Controller& controller;
	//Repository& repository;
private slots:
	void filterCommand();
	void hoursCommand();

};


