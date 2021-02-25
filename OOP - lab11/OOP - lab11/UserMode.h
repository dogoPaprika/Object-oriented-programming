#pragma once

#include <QWidget>
#include "ui_UserMode.h"
#include "_Controller.h"

#include <qmessagebox.h>
#include <qlistwidget.h>
#include <qdesktopservices.h>
#include <Qurl>

class UserMode : public QWidget
{
	Q_OBJECT

public:
	UserMode(QWidget *parent = Q_NULLPTR);
	~UserMode();

	UserMode(Controller* c, QWidget * parent = Q_NULLPTR);

private:
	Ui::UserMode ui;

	Controller* controller;

	int getSelectedIndex(const QListWidget* l);
	void initiateWatchList();
	void filterRepositoryByGenre(std::string, int);
	int position = 0;

private slots:
	void saveMovie();
	void filterRepository();
	void initiate();
	void playTrailer();
	void nextMovie();
};
