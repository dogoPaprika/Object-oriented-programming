#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GraphicalUserInterface.h"
#include "_Controller.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QFormLayout>
#include <QString>
#include <QMessageBox>
#include <Qstring>
#include <qdesktopservices.h>
#include <Qurl>
#include <time.h>
#include <string.h>

class GraphicalUserInterface : public QWidget
{
	Q_OBJECT

public:
	GraphicalUserInterface(QWidget *parent = Q_NULLPTR);

	//Constructor - calls initialization functions
	GraphicalUserInterface(Controller* c, QWidget * parent = Q_NULLPTR);
	~GraphicalUserInterface() {}

private:
	Ui::GraphicalUserInterfaceClass ui;

	Controller* controller;
	int position = 0;

	//Main widgets
	QListWidget* repositoryList;
	QListWidget* watchList;
	QMenu* fileMenu;

	//Line edits
	QLineEdit* titleTextBox;
	QLineEdit* genreTextBox;
	QLineEdit* yearTextBox;
	QLineEdit* likesTextBox;
	QLineEdit* trailerTextBox;

	//Buttons
	QPushButton* addButton = new QPushButton{ "Add" };
	QPushButton* deleteButton = new QPushButton{ "Delete" };
	QPushButton* updateButton = new QPushButton{ "Update" };
	QPushButton* filterButton = new QPushButton{ "Filter" }; // not sure if ok
	QPushButton* playButton = new QPushButton{ "Play" };   // not sure if ok
	QPushButton* nextButton = new QPushButton{ "Next" };   // not implemented
	QPushButton* saveButton = new QPushButton{ ">" };
	QPushButton* initialButton = new QPushButton{ "Initial Repository" };// extra
	QPushButton* userButton;
	QPushButton* adminButton;

	void chooseMode();
	/*
	Creates the layout and the fields of the class.
	IN:-
	OUT:-
	*/
	void initiateGraphicalUserInterfaceUser();

	void initiateGraphicalUserInterfaceAdmin();
	/*
	Updates the list repository with the actual objects from the memory repository.
	IN:-
	OUT:-
	*/
	void initiateRepository();
	/*
	filter the repository based on a genre and the number of likes
	*/
	void filterRepositoryByGenre(std::string, int);
	/*
	Updates the watchList with the actual objects from the memory watchList.
	IN:-
	OUT:-
	*/
	void initiateWatchList();
	/*
	Creates the connections between buttons and events (what to happen).
	IN: -
	OUT: -
	*/
	void setSignals();
	/*
	Returns an int representing the position of the selected element of the repository list.
	IN:-
	OUT:integer
	*/
	int getSelectedIndex(const QListWidget* l);

	void chooseRepository() { this->controller->readRepo(); }

private slots:
	void addMovie();
	void deleteMovie();
	void updateMovie();
	void saveMovie();
	void filterRepository();
	void initiate();
	void playTrailer();
	void nextMovie();
	void goToUser();
	void goToAdmin();
};
