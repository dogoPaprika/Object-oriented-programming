#define _CRT_SECURE_NO_WARNINGS
#include "UserInterface.h"
#include <Windows.h>
#include <crtdbg.h>


void initialization(Repository& repositoryInitiate)
{
	Team team1("Team1", "Romania", 40);
	Team team2("Team2", "Poland", 20);
	Team team3{ "Team3", "SUA", 44};
	Team team4{ "Team4", "Uganda", 55};
	Team team5{ "Team5", "Australia", 78};

	repositoryInitiate.addTeam(team1);
	repositoryInitiate.addTeam(team2);
	repositoryInitiate.addTeam(team3);
	repositoryInitiate.addTeam(team4);
	repositoryInitiate.addTeam(team5);
}

void tests()
{
	UserInterface::testUserInterface();
}

void start()
{
	Repository repository;
	initialization(repository);
	Controller controller{ repository };
	UserInterface userInterface{ controller };

	userInterface.run();
}

int main()
{
	tests();

	start(); 

	if (_CrtDumpMemoryLeaks())
		cout << "There are memory leaks!" << endl;

	system("pause");
	return 0;
}