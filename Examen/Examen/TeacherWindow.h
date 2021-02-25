#pragma once

#include <QWidget>
#include "ui_TeacherWindow.h"
#include "Controller.h"
#include "Subject.h"
#include "TWindow.h"

class TeacherWindow : public QWidget, public Subject, Observer
{
	Q_OBJECT
private:
	Ui::TeacherWindow ui;

	Controller ctrl;
	string name;
	TWindow& sub;

public:
	TeacherWindow(QWidget *parent = Q_NULLPTR);
	~TeacherWindow() {};

	void addStudent()
	{
		int pos = this->ui.allStudents->currentRow();
		if (!(this->ctrl.haveCoordinator(pos)))
		{
			this->ui.studentsList->clear();
			this->ctrl.setCoordinatorStudent(this->name, pos);
			this->populateList();
			this->sub.notifica();
		}

	}

	TeacherWindow(TWindow &sub, Controller ctrl, string name, QWidget *parent = Q_NULLPTR) : sub{ sub }, ctrl { ctrl }, name{ name }, QWidget(parent)
	{
		ui.setupUi(this);
		this->populateList();
		this->populateAllList();
		QObject::connect(this->ui.Add, &QPushButton::clicked, this, &TeacherWindow::addStudent);
		this->sub.registerObserver(this);
	}
	void update() override
	{
		this->populateAllList();
	}

	void populateList()
	{
		this->ui.studentsList->clear();
		std::vector<Student> vect = this->ctrl.getSortedStudents();
		for (auto i : vect)
		{
			if (i.getCoordinator() == name)
				this->ui.studentsList->addItem(QString::fromStdString(i.getId()) + ", " + QString::fromStdString(i.getName()) + ", " + QString::fromStdString(i.getEmail()) + ", " + QString::fromStdString(std::to_string(i.getYear())) + ", " + QString::fromStdString(i.getTitle()) + ", " + QString::fromStdString(i.getCoordinator()));
		}
	}

	void populateAllList()
	{
		this->ui.allStudents->clear();
		std::vector<Student> vect = this->ctrl.getStudents();
		for (auto i : vect)
		{
				this->ui.allStudents->addItem(QString::fromStdString(i.getId()) + ", " + QString::fromStdString(i.getName()) + ", " + QString::fromStdString(i.getEmail()) + ", " + QString::fromStdString(std::to_string(i.getYear())) + ", " + QString::fromStdString(i.getTitle()) + ", " + QString::fromStdString(i.getCoordinator()));
		}
	}

};
