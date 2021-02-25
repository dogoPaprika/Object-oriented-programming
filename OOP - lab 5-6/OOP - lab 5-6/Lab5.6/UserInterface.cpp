#include "UserInterface.h"

void UserInterface::printMenu()
{
	cout << endl;
	cout << " MENU: " << endl;
	cout << "mode A - Administrator mode (manage movies repository)" << endl;
	cout << "mode B - User mode (manage shop basket)" << endl;
	cout << "exit - Exit" << endl;
}

void UserInterface::printAdministratorMenu()
{
	cout << endl;
	cout << "Administrator menu:" << endl;
	cout << "\tlist - List all movies" << endl;
	cout << "\tadd <title>, <genre>, <yearOfRealese>, <likes>, <trailer> - Add movie" << endl;
	cout << "\tdelete <title> - Delete movie" << endl;
	cout << "\tupdate <title>, <newGenre>, <newYearOfRealease>, <newLikes>, <newTrailer> - Update movie" << endl;
	cout << "\texit - exit" << endl;
}

void UserInterface::printUserMenu()
{
	cout << endl;
	cout << "User menu:" << endl;
	cout << "\tnext - go to next movie" << endl;
	cout << "\tsave - add movie to watch list" << endl;
	cout << "\tlist <genre>, <likes> - list all movieswith a given genre, that has a certain number of likes" << endl;
	cout << "\tmylist - see your watch list" << endl;
	cout << "\texit - exit" << endl;
}

void UserInterface::listAllMovies()
{
	DynamicArray<Movie> dynamicArray = this->controller.getRepository();
	//Movie* repository = dynamicArray.getAllElements();

	if (dynamicArray.getSize() == 0)
	{
		cout << "There are no movies in the repository." << endl;
		return;
	}

	for (int i = 0; i < dynamicArray.getSize(); i++)
	{
		Movie moviePrint = dynamicArray[i];
		cout << i + 1 << "." << moviePrint.toString();
	}
}

bool UserInterface::validate(string title, string genre, int year, int likes, string trailer)
{
	if (title == "")
		return false;
	if (genre == "")
		return false;
	if (year < 0)
		return false;
	if (likes < 0)
		return false;
	if (trailer == "") 
		return false;
	return true;
}

bool UserInterface::addMovieUserInterface(char parameters[][30])
{
	if (this->validate(string(parameters[1]), string(parameters[2]), atoi(parameters[3]), atoi(parameters[4]), string(parameters[5])) == false)
	{
		cout << "Error! Wrong data fields." << endl;
		return false;
	}

	bool addStatus = this->controller.addMovieController(string(parameters[1]), string(parameters[2]), atoi(parameters[3]), atoi(parameters[4]), string(parameters[5]));
	return addStatus;
}

bool UserInterface::deleteMovieUserInterface(char parameters[][30])
{
	bool deleteStatus = this->controller.deleteMovieController(string(parameters[1]));
	return deleteStatus;
}

bool UserInterface::updateMovieUserInterface(char parameters[][30])
{
	if (this->validate(string(parameters[1]), string(parameters[2]), atoi(parameters[3]), atoi(parameters[4]), string(parameters[5])) == false)
	{
		cout << "Error! Wrong data fields." << endl;
		return false;
	}

	bool updateStatus = this->controller.updateMovieController(string(parameters[1]), string(parameters[2]), atoi(parameters[3]), atoi(parameters[4]), string(parameters[5]));
	return updateStatus;
}


bool UserInterface::saveMovieUserInterface(string movieTitle)
{
	
	Movie movie = Movie(movieTitle, " ", 1, 1, " ");
	controller.findMovieByTitle(movieTitle, movie);
	std::cout << movie.toString();
	return controller.addMovieWatchListController(movie);
}

void UserInterface::listWatchList()
{
	DynamicArray<Movie> dynamicArray = this->controller.getWatchList();
	Movie* repository = dynamicArray.getAllElements();

	if (dynamicArray.getSize() == 0)
	{
		cout << "There are no movies in the watch list." << endl;
		return;
	}

	for (int i = 0; i < dynamicArray.getSize(); i++)
	{
		Movie moviePrint = dynamicArray[i];
		cout << i + 1 << "." << moviePrint.toString();
	}
}

DynamicArray<Movie> UserInterface::getAllMovies()
{
	DynamicArray<Movie> dynamicArray = this->controller.getRepository();
	return dynamicArray;
}

void UserInterface::displayMovieOnPosition(DynamicArray<Movie> repository, int &position)
{
	position++;
	if (position == repository.getSize())
		position = 0;
	cout << repository[position].toString();
}

void UserInterface::displayMoviesByGenreAndLikes(string genre, int likes)
{
	DynamicArray<Movie> dynamicArray = this->controller.getRepository();
	for (int i = 0; i < dynamicArray.getSize(); i++)
	{
		if ((dynamicArray[i].getGenre() == genre) && (dynamicArray[i].getLikes() >= likes))
			cout << i + 1 << "." << dynamicArray[i].toString();
	}
}



//reading input methods
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

bool InMenuOptions(char* option)
{
	char instruction[][20] = { "exit", "mode"};
	for (int i = 0; i < 2; i++)
	{
		if (strcmp(instruction[i], option) == 0)
			return true;
	}
	return false;
}

bool InAdministratorMenuOptions(char* option)
{
	char instruction[][20] = { "exit", "list", "add", "delete", "update", "mode"};
	for (int i = 0; i < 6; i++)
	{
		if (strcmp(instruction[i], option) == 0)
			return true;
	}
	return false;
}

bool InUserMenuOptions(char* option)
{
	char instruction[][20] = { "exit", "list", "save", "next", "mylist", "mode"};
	for (int i = 0; i < 6; i++)
	{
		if (strcmp(instruction[i], option) == 0)
			return true;
	}
	return false;
}

void UserInterface::runAsAdministrator()
{
	char UserInput[100] = "";
	char firstWord[20] = "";
	int length = 0;

	while (1)
	{
		printAdministratorMenu();
		readStringWithSpaces("\nWhat option do you choose: ", 100, UserInput);
		char parameters[30][30];
		returnParameters(UserInput, parameters, &length);


		if (!InAdministratorMenuOptions(parameters[0]))
		{
			printf("Error! No such option exists.");
			continue;
		}
		if (strcmp(UserInput, "exit") == 0)
		{
			printf("Exit administrator mode - back to choosing mode\n");
			return;
		}
		if ((strcmp(parameters[0], "mode") == 0) && (string(parameters[1]) == "B"))
		{
			runAsUser();
			return;
		}

		//id, type, destination and price
		//add movie
		if (strcmp(parameters[0], "add") == 0)
		{
			bool addStatus = addMovieUserInterface(parameters);
			if (addStatus == true)
				printf("Movie successfully added.\n");
			else
				printf("Error! movie could not be added!\n");
		}

		//delete movie
		if (strcmp(parameters[0], "delete") == 0)
		{
			//delete
			bool deleteStatus = deleteMovieUserInterface(parameters);
			if (deleteStatus)
				printf("Movie successfully deleted.\n");
			else
				printf("Error! Movie could not be deleted, as entity does not exist!\n");
		}

		//update movie
		if (strcmp(parameters[0], "update") == 0)
		{
			//update
			bool updateStatus = updateMovieUserInterface(parameters);
			if (updateStatus == 1)
				printf("Movie successfully updated.\n");
			else
				printf("Error! Movie could not be updated!\n");
		}

		//list movies
		if (strcmp(parameters[0], "list") == 0)
		{
			//show what we have
			listAllMovies();
		}
	}
}


void UserInterface::runAsUser()
{
	char UserInput[100] = "";
	char firstWord[20] = "";
	int length = 0;
	int nextMovieCounter = -1;
	bool stillWatchingTrailer = false;
	DynamicArray<Movie> repositoryTrailer = getAllMovies();
	std::string Genre = "";
	int Likes = 0;

	while (1)
	{
		printUserMenu();
		readStringWithSpaces("\nWhat option do you choose: ", 100, UserInput);
		char parameters[30][30];
		returnParameters(UserInput, parameters, &length);
		

		if (!InUserMenuOptions(parameters[0]))
		{
			printf("Error! No such option exists.");
			continue;
		}
		if (strcmp(UserInput, "exit") == 0)
		{
			printf("Exit User mode - back to choosing mode\n");
			return;
		}

		if ((strcmp(parameters[0], "mode") == 0) && (string(parameters[1]) == "A"))
		{
			runAsAdministrator();
			return;
		}

		//add movie to watch list
		if ((strcmp(parameters[0], "save") == 0) && (length == 2))
		{
			bool saveStatus = false;
			if (length == 2)
				saveStatus = saveMovieUserInterface(parameters[1]);
			if (saveStatus == true)
				printf("Movie successfully added to watch list.\n");
			else
				printf("Error! movie could not be added!\n");
			continue;
		}

		//display the watch list
		if (strcmp(parameters[0], "mylist") == 0)
		{
			listWatchList();
			continue;
		}

		if (strcmp(parameters[0], "next") == 0)
		{
			displayMovieOnPosition(repositoryTrailer, nextMovieCounter);
			continue;
		}

		//list movies
		if (strcmp(parameters[0], "list") == 0)
		{
			displayMoviesByGenreAndLikes(parameters[1], atoi(parameters[2]));
			continue;
		}		
	}
}


/*
Keeps the application in an infinite loop while demanding operations.
IN: UI*
OUT: -
*/
void UserInterface::run()
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

		if ((strcmp(parameters[0], "mode") == 0) && (string(parameters[1]) == "A"))
		{
			runAsAdministrator();
			return;
		}

		if ((strcmp(parameters[0], "mode") == 0) && (string(parameters[1]) == "B"))
		{
			runAsUser();
			return;
		}
	}
}

//propagate testing
void UserInterface::testUserInterface()
{
	Repository repositoryTesting;
	Controller controllerTesting(repositoryTesting);
	controllerTesting.testController();
}