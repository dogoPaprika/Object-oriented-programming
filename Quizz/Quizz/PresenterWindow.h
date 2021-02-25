#pragma once

#include <QWidget>
#include "ui_PresenterWindow.h"
#include "Controller.h"
#include "Subject.h"
#include <qpushbutton.h>
#include <QMessageBox>

class PresenterWindow : public QWidget, public Subject
{
	Q_OBJECT

public:
	PresenterWindow(Controller ctrl, QWidget *parent = Q_NULLPTR) : ctrl{ ctrl }, QWidget(parent)
	{
		ui.setupUi(this);
		this->populateList();
		QObject::connect(this->ui.addQuestion, &QPushButton::clicked, this, &PresenterWindow::addQuestion);
	}
	~PresenterWindow() {}
	void populateList()
	{
		this->ui.questionsList->clear();
		std::vector<Question> vect = this->ctrl.getSortedQuestions();
		for (auto i : vect)
			this->ui.questionsList->addItem(QString::fromStdString(std::to_string(i.getId())) + " " + QString::fromStdString(i.getQuestion()) + " " + QString::fromStdString(i.getAnswer()) + " " + QString::fromStdString(std::to_string(i.getScore())));
	}
	void addQuestion()
	{
		if (this->ui.questionLine->text().isEmpty() || this->ui.idLine->text().isEmpty() || this->ui.answerLine->text().isEmpty() || this->ui.scoreLine->text().isEmpty())
		{
			QMessageBox messageBox;
			messageBox.critical(0, "Error", "An error has occured !");
		}
		else {
			QString question = this->ui.questionLine->text();
			std::string que = question.toStdString();

			QString id = this->ui.idLine->text();
			std::string id1 = id.toStdString();
			int id2 = std::stoi(id1);

			QString answer = this->ui.answerLine->text();
			std::string ans = answer.toStdString();

			QString score1 = this->ui.scoreLine->text();
			std::string sc1 = score1.toStdString();
			int score = std::stoi(sc1);

			if (this->ctrl.searchById(id2))
			{
				QMessageBox messageBox;
				messageBox.critical(0, "Error", "An error has occured !");
			}
			else {
				this->ctrl.addQuestion(id2, que, ans, score);
				this->notify();
			}
		}
		this->ui.questionsList->clear();
		this->populateList();
	}
private:
	Controller ctrl;
	Ui::PresenterWindow ui;
};
