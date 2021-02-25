#pragma once
#include "Repository.h"
#include <vector>
#include <algorithm>

class Controller {
private:
	Repository &repo;
public:
	Controller(Repository& repo) : repo{ repo } {};
	int getSizeParticipants() { return this->repo.getSizeParticipants(); }
	std::vector<Participant> getParticipants() { return this->repo.getParticipants(); }
	std::vector<Question> getQuestions() { return this->repo.getQuestions(); }
	std::vector<Question> getSortedQuestions()
	{
		std::vector<Question> sorted = this->repo.getQuestions();
		for (int i = 0; i < sorted.size() - 1; i++)
			for (int j = i + 1; j < sorted.size(); j++)
				if (sorted[i].getId() > sorted[j].getId())
					std::swap(sorted[i], sorted[j]);
		return sorted;
	}
	std::vector<Question> getSortedQuestionsByScore() { return this->repo.getSortedQuestions(); }
	bool searchById(int id) { return this->repo.searchById(id); }
	void addQuestion(int id, std::string question, std::string answer, int score)
	{
		this->repo.addQuestion(Question{ id, question, answer, score });
	}
	int isCorrectAddScore(std::string answer, int pos)
	{
		if (answer == this->getQuestions().at(pos).getAnswer())
			return this->getQuestions().at(pos).getScore();
		else
			return 0;
	}
	int getPrevScore(std::string name)
	{
		for (auto i : this->getParticipants())
			if (i.getName() == name)
				return i.getScore();
	}
	void setScoreParticipant(std::string name, int score)
	{
		this->repo.setScoreAtParticipant(name, score);
	}
	~Controller() {};
};