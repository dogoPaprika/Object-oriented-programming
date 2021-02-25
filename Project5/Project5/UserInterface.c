#include "UserInterface.h"
#include <ctype.h>
/*
Creates a UI in memory and returns a pointer to it.
IN: pt to Controller
OUT:-
*/
UserInterface* createUserInterface(Controller* controller)
{
	if (controller == NULL)
		return NULL;

	UserInterface* userInterface = (UserInterface*)malloc(sizeof(UserInterface));
	userInterface->controller = controller;

	return userInterface;
}

/*
Deallocates the memory used for the ui.
IN: pt to UI
OUT:-
*/
void destroyUserInterface(UserInterface* userInterface)
{
	if (userInterface == NULL)
		return;

	// first destroy the controller
	destroyController(userInterface->controller);
	// free the UI memory
	free(userInterface);
}

/*
Prints the menu on screen.
IN: -
OUT: -
*/
void printMenu()
{
	printf("\n");
	printf("\n");
	printf("The operations are: \n");
	printf("<exit> - exit program\n");
	printf("<add> (id, type, destination, price)- add new Offer\n");
	printf("<list> - show all offers\n");
	printf("<delete> (id) - delete offer\n");
	printf("<update> id, newType, newDestination, newPrice - update offer\n");
	printf("<list> (destination) - all the available offers containing a given destination \n");
	printf("<list> (maxPrice) - list all offers below a certain price, sorted ascendingly by type \n");
	printf("<undo> - undo last operation\n");
	printf("<redo> - redo lst operation\n");
	printf("\n");
	printf("\n");
}

/*
Reads a string with spaces from the standard input.
Input:	message - string, message to be shown to the user.
maxStrSize - the maximum size for the string to be read
Output: the string that was read.
*/
void readStringWithSpaces(const char* message, int maxStringSize, char string[])
{
	printf(message);
	fgets(string, maxStringSize, stdin);
	//the newline is also read so we must eliminate it from the string
	int size = strlen(string) - 1;
	if (string[size] == '\n')
		string[size] = '\0';
}


/*
Prints on screen a given offer repository.
IN: OfferRepo*
OUT:-
*/
void printRepository(OfferRepository* repository)
{
	int length = getLength(repository);
	for (int i = 0; i < length; i++)
	{
		char string[200];
		toString(getOfferOnPosition(repository, i), string);
		printf("%d.%s\n", i + 1, string);
	}
}

/*
Calls the fct of adding from controller.
IN: UI*
OUT: 1 if succesful, anything else if unsuccesful
*/
int addOfferUserInterface(UserInterface* userInterface, char parameters[][30], int length)
{
	if (userInterface == NULL)
		return 0;

	if (length != 5)
		return -1;

	int id = 0;
	float price = 0.0;

	/*
	for (int i = 0; i < strlen(params[1]); i++)
		if (!isdigit(params[1][i]))
			return -1;
		else
			id = id * 10 + (params[1][i]) - '0';
	*/

	return addOfferController(userInterface->controller, atoi(parameters[1]), parameters[2], parameters[3], atof(parameters[4]));
}

/*
Updates an offer with a given id with another non-unique fields.
IN: UI*
OUT: 1 if succesful, else not 1
CONDIS: -
*/
int updateByIdUserInterface(UserInterface* userInterface, char parameters[][30], int length)
{
	if (userInterface == NULL)
		return -1;

	if (length != 5)
		return -1;

	int id = 0;
	float price = 0.0;

	for (int i = 0; i < strlen(parameters[1]); i++)
		if (!isdigit(parameters[1][i]))
			return -1;
		else
			id = id * 10 + (parameters[1][i]) - '0';

	return updateOfferController(userInterface->controller, id, parameters[2], parameters[3], atof(parameters[4]));
}

/*
Removes the offer with a given id.
IN: UI*
OUT: 1 if succesful, else not 1
CONDIS: -
*/
int deleteByIdUserInterface(UserInterface* userInterface, char parameters[][30], int length)
{
	if (userInterface == NULL)
		return -1;

	if (length != 2)
		return -1;
	int id = 0;

	for (int i = 0; i < strlen(parameters[1]); i++)
		if (!isdigit(parameters[1][i]))
			return -1;
		else
			id = id * 10 + (parameters[1][i]) - '0';

	return deleteByIdController(userInterface->controller, id);
}

/*
Prints on screen all offers from the repository.
IN: UI*
OUT:-
*/
void listAllOffers(UserInterface* userInterface)
{
	if (userInterface == NULL)
		return;

	OfferRepository* offerRepository = getRepository(userInterface->controller);
	int length = getLength(offerRepository);

	if (length == 0)
	{
		char* string = "There are no stored offers.";
		printf("%s \n", string);
	}
	printRepository(offerRepository);
}

/*
Prints on screen the offers having a given destination.
IN: UI*
OUT:-
*/
void listOffersByDestinationUserInterface(UserInterface* userInterface, char* parameters)
{
	if (userInterface == NULL)
		return;
	
	OfferRepository* offerRepository = getOffersByDestinationController(userInterface->controller, parameters);

	int length = getLength(offerRepository);
	if (length == 0)
	{
		printf("There are no offers with destination '%s'.", parameters);
	}
	else
	{
		printRepository(offerRepository);
	}

	destroyRepository(offerRepository);
}

/*
Prints on screen the offers having a given destination.
IN: UI*
OUT:-
*/
void listOffersByPriceUserInterface(UserInterface* userInterface, float maximumPrice)
{
	if (userInterface == NULL)
		return;

	OfferRepository* offerRepository = getOffersByPriceController(userInterface->controller, maximumPrice);

	int length = getLength(offerRepository);
	if (length == 0)
	{
		printf("There are no offers with price lower than %.2f", maximumPrice);
	}
	else
	{
		printRepository(offerRepository);
	}

	destroyRepository(offerRepository);
}

void calculateFirstWord(char* option, char *firstWord)
{
	int i = 0;
	while ((i < strlen(option)) && (option[i] != ' '))
	{
		firstWord[i] = option[i];
		firstWord[i + 1] = '\0';
		i++;
	}
}

int InOptions(char* option)
{
	char instruction[][20] = { "exit", "add", "delete", "list", "update", "undo", "redo" };
	for (int i = 0; i < 7; i++)
	{
		if (strcmp(instruction[i], option) == 0)
			return 1;
	}
	return 0;
}


/*
char returnParameters(char* opt, char params[][10], int* length)
{
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < strlen(opt))
	{
		if (opt[i] != ' ')
		{
			params[j][k] = opt[i];
			k++;
			params[j][k] = '\0';
		}
		else
		{
			k = 0;
			j++;
		}
		i++;
	}
	*length = ++j;
}
*/

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


/*
Keeps the application in an infinite loop while demanding operations.
IN: UI*
OUT: -
*/
void startUserInterface(UserInterface* userInterface)
{
	if (userInterface == NULL)
		return;

	char UserInput[100] = "";
	char firstWord[20] = "";
	int length = 0;

	while (1)
	{
		printMenu();
		readStringWithSpaces("\nWhat option do you choose: ", 100, UserInput);
		char parameters[30][30];
		returnParameters(UserInput, parameters, &length);

		

		if (!InOptions(parameters[0]))
		{
			printf("Error! No such option exists.");
			continue;
		}
		else if ((strcmp(parameters[0], "add") == 0) || (strcmp(parameters[0], "delete") == 0) || (strcmp(parameters[0], "update") == 0))
		{
			clearRedo(userInterface->controller);
			clearDynamicArray(userInterface->controller->redoList);
		}

		if (strcmp(UserInput, "exit") == 0)
		{
			printf("Goodbye lovely User\n");
			return;
		}

		//id, type, destination and price
		//add offer
		if (strcmp(parameters[0], "add") == 0)
		{
			int addStatus = addOfferUserInterface(userInterface, parameters, length);
			if (addStatus == 1)
				printf("Offer successfully added.\n");
			else
				printf("Error! offer could not be added!\n");
		}

		if (strcmp(parameters[0], "list") == 0)
		{
			if (strcmp(UserInput, parameters[0]) == 0)
			{
				//show what we have
				listAllOffers(userInterface);
			}
			else if (isdigit(parameters[1][0]))
			{
				//all offers with price lower than a given price, sorted asc by type
				listOffersByPriceUserInterface(userInterface, atof(parameters[1]));
			}
			else
			{
				//all containing given destination
				listOffersByDestinationUserInterface(userInterface, parameters[1]);
			}
		}

		if (strcmp(parameters[0], "delete") == 0)
		{
			//delete
			int deleteStatus = deleteByIdUserInterface(userInterface, parameters, length);
			if (deleteStatus == 1)
				printf("Offer successfully deleted.\n");
			else
				printf("Error! offer could not be deleted, as entity does not exist!\n");
		}

		if (strcmp(parameters[0], "update") == 0)
		{
			//update
			int updateStatus = updateByIdUserInterface(userInterface, parameters, length);
			if (updateStatus == 1)
				printf("Offer successfully updated.\n");
			else
				printf("Error! Offer could not be updated!\n");
		}

		if (strcmp(UserInput, "undo") == 0)
		{
			//undo
			//int res = undoOperationStack(ui->ctrl);
			int undoStatus = undoListOfList(userInterface->controller);

			if (undoStatus == 1)
				printf("Undo was successful.\n");
			else
				printf("No more undos to be made.\n");
		}

		if (strcmp(UserInput, "redo") == 0)
		{
			//redo
			//int res = redo(ui->ctrl);
			int redoStatus = redoListOfList(userInterface->controller);
			
			if (redoStatus == 1)
				printf("Redo was successful.\n");
			else
				printf("No more redos to be made.\n");
		}
	}
}