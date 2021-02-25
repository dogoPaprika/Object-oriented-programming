#pragma once

#include <utility>
#include "Controller.h"
using namespace std;

class UserInterface
{
private:
	Controller controller;

	static void printMenu()
	{
		cout << endl;
		cout << " MENU: " << endl;
		cout << "Add a new team" << endl;
		cout << "List teams in descending order by score" << endl;
		cout << "exit - Exit" << endl;
	}

	void sortDescendinglyByScore(DynamicArray<Team> &dynamicArray)
	{
		for (int i = 0; i < dynamicArray.getSize()-1; i++)
			for (int j = i+1;j < dynamicArray.getSize(); j++)
					if ((dynamicArray[j].getScore()) > (dynamicArray[i].getScore()))
					{
						Team aux = dynamicArray[i];
						dynamicArray[i] = dynamicArray[j];
						dynamicArray[j] = aux;
					}
	}


	void listAllTeamsDescendByScore()
	{
		DynamicArray<Team> dynamicArray = this->controller.getRepository();
		

		if (dynamicArray.getSize() == 0)
		{
			cout << "There are no teams in the repository." << endl;
			return;
		}

		sortDescendinglyByScore(dynamicArray);
	

		for (int i = 0; i < dynamicArray.getSize(); i++)
		{
			Team teamPrint = dynamicArray[i];
			cout << i + 1 << "." << teamPrint.toString();
		}
	}


	bool addTeamUserInterface(char parameters[][30])
	{
		if (this->validate(string(parameters[1]), string(parameters[2]), atoi(parameters[3])) == false)
		{
			cout << "Error! Wrong data fields." << endl;
			return false;
		}

		bool addStatus = this->controller.addTeamController(string(parameters[1]), string(parameters[2]), atoi(parameters[3]));
		return addStatus;
	}

	bool InMenuOptions(char* option)
	{
		char instruction[][20] = { "exit", "list", "add"};
		for (int i = 0; i < 3; i++)
		{
			if (strcmp(instruction[i], option) == 0)
				return true;
		}
		return false;
	}


	void readStringWithSpaces(const char* message, int maxStringSize, char string[])
	{
		printf(message);
		fgets(string, maxStringSize, stdin);
		//the newline is also read so we must eliminate it from the string
		int size = strlen(string) - 1;
		if (string[size] == '\n')
			string[size] = '\0';
	}

	void returnParameters(char* userInput, char parameters[][30], int* length)
	{
		int i = 0;
		int parameterCount = 0;
		int literalCount = 0;

		while (i < strlen(userInput))
		{
			if (userInput[i] != ' ')
			{
				parameters[parameterCount][literalCount] = userInput[i];
				literalCount++;
				parameters[parameterCount][literalCount] = '\0';
			}
			else
			{
				literalCount = 0;
				parameterCount++;
				break;
			}
			i++;
		}

		while (i < strlen(userInput))
		{
			if (userInput[i] != ',')
			{
				parameters[parameterCount][literalCount] = userInput[i];
				literalCount++;
				parameters[parameterCount][literalCount] = '\0';
			}
			else
			{
				literalCount = 0;
				parameterCount++;
			}
			i++;
		}
		*length = ++parameterCount;
		for (int i = 0; i < *length; i++)
			if (parameters[i][0] == ' ')
				strcpy(parameters[i], parameters[i] + 1);
	}

public:
	UserInterface(const Controller& controller) : controller(controller) {}

	bool validate(string name, string country, int score)
	{
		if (name == "")
			return false;
		if (country == "")
			return false;
		if (score < 0)
			return false;
		return true;
	}

	//Runs the program until stopped.
	void run()
	{

		char UserInput[100] = "";
		char firstWord[20] = "";
		int length = 0;

		while (1)
		{
			//printing menu, reading input, returning parameters
			printMenu();
			readStringWithSpaces("\nWhat option do you choose: ", 100, UserInput);
			char parameters[30][30];
			returnParameters(UserInput, parameters, &length);

			//verifying if the option is valid
			if (!InMenuOptions(parameters[0]))
			{
				printf("Error! No such option exists.");
				continue;
			}

			//exiting the program
			if (strcmp(UserInput, "exit") == 0)
			{
				printf("Goodbye lovely User\n");
				return;
			}

			if (strcmp(parameters[0], "add") == 0)
			{
				bool addStatus = addTeamUserInterface(parameters);
				if (addStatus == false)
				{
					cout << "There is already a team";
				}
				else
					cout << "succesfull team added";
			}

			if (strcmp(parameters[0], "list") == 0)
			{
				listAllTeamsDescendByScore();
			}
		}
	}

	void static testUserInterface()
	{
		Repository repo;
		Controller controller(repo);
		controller.testController;
	}
};




