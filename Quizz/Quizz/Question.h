#pragma once

#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Question {
private:
	int id;
	std::string question;
	std::string answer;
	int score;
public:
	Question() {}
	Question(int id, std::string question, std::string answer, int score)
	{
		this->id = id;
		this->question = question;
		this->answer = answer;
		this->score = score;
	}
	int getId() { return id; }
	int getScore() { return score; }
	std::string getQuestion() { return question; }
	std::string getAnswer() { return answer; }

	void setId(int id) 
	{
		this->id = id; 
	}
	void setScore(int sc) 
	{ 
		this->score = sc; 
	}
	void setQuestion(string q) 
	{ 
		question = q; 
	}
	void setAnswer(string a) 
	{ 
		answer = a; 
	}
	~Question() {};

	friend istream& operator>>(istream& is, Question& b);
};

