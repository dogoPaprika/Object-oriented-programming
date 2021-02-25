#pragma once

#include <QWidget>
#include "ui_Administrator.h"
#include "_Controller.h"

#include <qmessagebox.h>

class Administrator : public QWidget
{
	Q_OBJECT

public:
	Administrator(QWidget *parent = Q_NULLPTR);
	~Administrator();

	Administrator(Controller* c, QWidget * parent = Q_NULLPTR);

private:
	Ui::Administrator ui;

	Controller* controller;

	int getSelectedIndex(const QListWidget* l);
	void initiateRepository();

private slots:
	void addMovie();
	void deleteMovie();
	void updateMovie();
};
