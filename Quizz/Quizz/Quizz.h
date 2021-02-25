#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Quizz.h"
#include "Controller.h"
#include "PresenterWindow.h"
#include "ParticipantWindow.h"

class Quizz : public QMainWindow
{
	Q_OBJECT

private:
	Ui::QuizzClass ui;

	Controller ctrl;

public:
	Quizz(Controller ctrl, QWidget *parent = Q_NULLPTR) : ctrl{ ctrl }, QMainWindow(parent)
	{
		ui.setupUi(this);
		this->createWindows();
	}
	void createWindows()
	{

		PresenterWindow* pres = new PresenterWindow{ ctrl };
		pres->setWindowTitle("Presenter");
		pres->show();

		std::string name;
		int size = this->ctrl.getSizeParticipants();
		std::vector<Participant> vect = this->ctrl.getParticipants();
		
		for (int i = 0; i < size; i++)
		{
			ParticipantWindow* pres1 = new ParticipantWindow{ *pres, ctrl, vect.at(i).getName() };
			name = vect.at(i).getName();
			pres1->setWindowTitle(QString::fromStdString(name));
			pres1->show();
		}
	}
	~Quizz() {}
};
