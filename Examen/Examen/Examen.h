#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Examen.h"
#include "Controller.h"
#include "TeacherWindow.h"
#include "Subject.h"

class Examen : public QMainWindow
{
	Q_OBJECT

public:
	Examen(QWidget *parent = Q_NULLPTR);
	Examen(Controller ctrl, QWidget *parent = Q_NULLPTR) : ctrl{ ctrl }, QMainWindow(parent)
	{
		ui.setupUi(this);
		this->createWindows();
	}

private:
	Ui::ExamenClass ui;

	Controller ctrl;

public:
	void createWindows()
	{
		std::string name;
		int size = this->ctrl.getSizeTeachers();
		std::vector<Teacher> vect = this->ctrl.getTeachers();

		TWindow *sub = new TWindow{ctrl};

		for (int i = 0; i < size; i++)
		{
			TeacherWindow* pres1 = new TeacherWindow{*sub, ctrl, vect.at(i).getName() };
			name = vect.at(i).getName();
			pres1->setWindowTitle(QString::fromStdString(name));
			pres1->show();
		}
	}
};
