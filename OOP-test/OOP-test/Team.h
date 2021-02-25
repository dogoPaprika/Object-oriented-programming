#pragma once

#include <iostream>
#include <string> //for stoi()
#include <assert.h>
#include <sstream> //for toString()
#include <Windows.h>
#include <shellapi.h> //for display()

class Team
{
private:
	std::string name;
	std::string country;
	int score;

public:
	
	Team() : name(""), country(""), score(0) {};

	
	Team(const std::string& name, const std::string& country, int score)
	{
		this->name = name;
		this->country = country;
		this->score = score;
	}


	Team(const Team& copiedteam)
	{
		this->name = copiedteam.name;
		this->country = copiedteam.country;
		this->score = copiedteam.score;
	}

	
	~Team() {}

	Team& operator=(const Team& team)
	{
		this->name = team.name;
		this->country = team.country;
		this->score = team.score;

		return *this;
	}
	bool operator==(const Team& team)
	{
		if (this->getName() == team.getName())
			return true;

		return false;
	}

	void copyTeam(Team team)
	{
		this->name = team.name;
		this->country = team.country;
		this->score = team.score;

	}


	std::string getName() const { return this->name; }
	std::string getCountry() const { return this->country; }
	int getScore() const { return this->score; }


	void setName(std::string name) { this->name = name; }
	void setCountry(std::string country) { this->country = country; }
	void setScore(int score) { this->score = score; }

	std::string toString()
	{
		std::stringstream teamToString;
		teamToString << "Team: " << this->name << ", country: " << this->country << ", score: " << this->score << std::endl;
		return teamToString.str();
	}

	//void static testTeam();
};
	

	