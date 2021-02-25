#pragma once

#include <QWidget>
#include "ui_ParticipantWindow.h"
#include "Controller.h"
#include "Observer.h"
#include "PresenterWindow.h"

class ParticipantWindow : public QWidget, Observer
{
	Q_OBJECT

public:
	ParticipantWindow(PresenterWindow& presenter, Controller ctrl, std::string name, QWidget *parent = Q_NULLPTR)
		: presenter{ presenter }, ctrl{ ctrl }, name{ name }, QWidget(parent)
	{
		ui.setupUi(this);
		this->populateList();
		this->ui.score->addItem(QString::fromStdString(std::to_string(0)));
		QObject::connect(this->ui.answer, &QPushButton::clicked, this, &ParticipantWindow::answerQuestion);
		this->presenter.registerObserver(this);
	}
	~ParticipantWindow() {};
	void populateList()
	{
		this->ui.questions->clear();
		std::vector<Question> vect = this->ctrl.getSortedQuestionsByScore();
		for (auto i : vect)
			this->ui.questions->addItem(QString::fromStdString(std::to_string(i.getId())) + " " + QString::fromStdString(i.getQuestion()) + " " + QString::fromStdString(std::to_string(i.getScore())));
	}
	void answerQuestion()
	{
		int pos = this->ui.questions->currentRow();
		if (this->ui.questions->currentItem()->backgroundColor() == "green")
			this->ui.answer->setEnabled(true);
		else {
			QString ans = this->ui.answerLineEdit->text();
			std::string answer = ans.toStdString();

			if (this->ctrl.isCorrectAddScore(answer, pos))
			{
				int score = this->ctrl.getPrevScore(this->name);
				score += this->ctrl.getQuestions().at(pos).getScore();
				this->ui.score->clear();
				this->ui.questions->currentItem()->setBackgroundColor("green");
				this->ui.score->addItem(QString::fromStdString(std::to_string(score)));
				this->ctrl.setScoreParticipant(this->name, score);
			}
		}
	}
	void update() override
	{
		this->populateList();
	}

private:
	Controller ctrl;
	std::string name;
	PresenterWindow& presenter;
	Ui::ParticipantWindow ui;
};
