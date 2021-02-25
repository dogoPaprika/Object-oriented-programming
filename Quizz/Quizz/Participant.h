#pragma once
#include <iostream>
#include <string>

class Participant {
private:
	std::string name;
	int score;
public:
	Participant(std::string name, int score)
	{
		this->name = name;
		this->score = score;
	}
	int getScore() { return this->score; }
	std::string getName() { return this->name; }
	void setScore(int score) 
	{ 
		this->score = score; 
	}
	~Participant() {};
};
