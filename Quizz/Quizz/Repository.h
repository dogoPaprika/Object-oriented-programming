#pragma once
#include "Participant.h"
#include "Question.h"
#include <fstream>

class Repository
{
private:
	std::vector<Participant> participants;
	std::vector<Question> questions;
public:
	Repository() 
	{
		this->readParticipantsFile();
		this->readQuestionsFile();
	}
	int getSizeParticipants() { return participants.size(); }
	std::vector<Participant> getParticipants() { return participants; }
	std::vector<Question> getQuestions() { return questions; }
	std::vector<Question> getSortedQuestions()
	{
		for (int i = 0; i < questions.size() - 1; i++)
		{
			for (int j = i + 1; j < questions.size(); j++)
			{
				if (questions[i].getScore() < questions[j].getScore())
					std::swap(questions[i], questions[j]);
			}
		}
		return questions;
	}
	void addQuestion(Question que)
	{
		questions.push_back(que);
		this->writeToFile();
	}
	bool searchById(int id)
	{
		for (auto que : questions)
		{
			if (que.getId() == id)
				return true;
		}
		return false;
	}
	void readParticipantsFile()
	{
		std::string name;
		int score;
		std::ifstream f("participant.txt");
		while (f >> name >> score)
			participants.push_back(Participant{ name, score });
	}
	void setScoreAtParticipant(std::string name, int score)
	{
		for (int i = 0; i < this->participants.size(); i++)
			if (participants[i].getName() == name)
				participants[i].setScore(score);
	
	}
	void writeToFile()
	{
		std::ofstream f("question.txt");
		for(auto i : questions)
		{
			f << i.getId() << " " << i.getQuestion() << " " << i.getAnswer() << " " << i.getScore() << std::endl;
		}
	}
	void readQuestionsFile()
	{
		Question q{};
		std::ifstream f("question.txt");
		while (f >> q)
			questions.push_back(q);
	}
	~Repository() {};
};