#pragma once

#include "Team.h"
#include "DynamicArray.h"

class Repository
{
private:
	DynamicArray <Team> dynamicArray;

public:
	Repository() {} 

	DynamicArray<Team> getArray() { return this->dynamicArray; }

	int getSize()
	{
		return this->dynamicArray.getSize();
	}


	Team getTeam(int position)
	{

		//if (position < 0 || position >= len)
		//return NULL;

		return this->dynamicArray[position];
	}

	bool addTeam(Team team)
	{
		if (dynamicArray.find(team) != -1)
			return false;

		this->dynamicArray.add(team);
		return true;
	}

	//Function that test the add function for repository
	//IN: -
	//Out: -
	void TestAddTeam()
	{
		Repository repositoryInitiate;
		Team team1("Team1", "Romania", 40);
		Team team2("Team2", "Poland", 20);
		Team team3{ "Team3", "SUA", 44 };
		Team team4{ "Team4", "Uganda", 55 };
		Team team5{ "Team5", "Australia", 78 };

		repositoryInitiate.addTeam(team1);
		repositoryInitiate.addTeam(team2);
		repositoryInitiate.addTeam(team3);
		repositoryInitiate.addTeam(team4);
		repositoryInitiate.addTeam(team5);

		assert(repositoryInitiate.getSize() == 5);
		assert(repositoryInitiate.getTeam(0) == team1);
	}

};
	