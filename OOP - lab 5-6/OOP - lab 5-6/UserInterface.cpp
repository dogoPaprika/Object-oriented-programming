#include "UserInterface.h"

//function that prints the general Menu
void UserInterface::printMenu()
{
	cout << endl;
	cout << " MENU: " << endl;
	cout << "mode A - Administrator mode (manage movies repository)" << endl;
	cout << "mode B - User mode (manage watch list)" << endl;
	cout << "exit - Exit" << endl;
}

//function that prints the Administrator Menu
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

//function that prints the User Menu
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

//this function lists all movies from repository
void UserInterface::listAllMovies()
{
	std::vector<Movie> movies = this->controller.getMovies();

	if (movies.size() == 0)
	{
		cout << "There are no movies in the repository." << endl;
		return;
	}

	for (auto movie : movies)
		cout << movie.toString();
}

//function that adds a movie
//input : an array of chars - which corresponds to a movie object`s fields
void UserInterface::addMovie(char parameters[][300])
{
	this->controller.addMovie(string(parameters[1]), string(parameters[2]), atoi(parameters[3]), atoi(parameters[4]), string(parameters[5]));
	cout << "Movie succesfully added" << endl;
}

//function that deletes a movie
//input : an array of chars - which corresponds to a movie object`s fields
void UserInterface::deleteMovie(char parameters[][300])
{
	this->controller.deleteMovie(string(parameters[1]));
	cout << "Movie succesfully deleted" << endl;
}

//function that updates a movie
//input : an array of chars - which corresponds to a movie object`s fields
void UserInterface::updateMovie(char parameters[][300])
{
	this->controller.updateMovie(string(parameters[1]), string(parameters[2]), atoi(parameters[3]), atoi(parameters[4]), string(parameters[5]));
	cout << "Movie succesfully updated" << endl;
}

//function that saves a movie to the Watch List
//input: a string - Title of a movie (that already exists in the repository)
void UserInterface::saveMovieWatchList(string movieTitle)
{
	Movie movie = Movie(movieTitle, "sss", 1, 1, "sss");
	controller.findMovieByTitle(movie);
	controller.addMovieWatchList(movie);
	cout << "Movie succesfully added to the Watch List" << endl;
}

//function that lists the Watch List
void UserInterface::listWatchList()
{
	std::vector<Movie> movies = this->controller.getWatchList();

	if (movies.size() == 0)
	{
		cout << "There are no movies in the watch list." << endl;
		return;
	}

	for (auto movie : movies)
		cout << movie.toString();
}

//function that returns all the movies from repository
//output: vector of Movies - all the movies from repository
std::vector<Movie> UserInterface::getAllMovies()
{
	std::vector<Movie> movies = this->controller.getMovies();
	return movies;
}

//function that displays a movie on specific position
//input: vector of Movies - repository, int - position
void UserInterface::displayMovieOnPosition(std::vector<Movie> repository, int &position)
{
	position++;
	if (position == repository.size())
		position = 0;
	cout << repository[position].toString();
}

//functions that displays movies depending on their genre and likes
void UserInterface::displayMoviesByGenreAndLikes(string genre, int likes)
{
	std::vector<Movie> movies = this->controller.getMovies();
	for (int i = 0; i < movies.size(); i++)
	{
		if ((movies[i].getGenre() == genre) && (movies[i].getLikes() >= likes))
			cout << i + 1 << "." << movies[i].toString();
	}
}

//function that prints the errors
void UserInterface::printErrors(vector<string> errors)
{
	cout << "Error!\n";
	for (auto error : errors)
	{
		cout << error;
	}
}

//void UserInterface::saveWatchListToFile()
//{
//	try
//	{
//		this->controller.saveWatchList();
//		cout << "Watch list saved to file." << endl;
//	}
//	catch (FileException& e)
//	{
//		cout << e.what() << endl;
//	}
//}



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

//function that return parameters, separating the input on whitespaces and commas
void returnParameters(char* userInput, char parameters[][300], int* length)
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

//function that checks if option is in menu options
//output: true - option in options; false - option not in options
bool InMenuOptions(char* option)
{
	char instruction[][20] = { "exit", "mode", "fileLocation", "mylistLocation"};
	for (int i = 0; i < 4; i++)
	{
		if (strcmp(instruction[i], option) == 0)
			return true;
	}
	return false;
}

//function that checks if option is in administrator menu options
//output: true - option in options; false - option not in options
bool InAdministratorMenuOptions(char* option)
{
	char instruction[][20] = { "exit", "list", "add", "delete", "update", "mode", "fileLocation", "mylistLocation"};
	for (int i = 0; i < 8; i++)
	{
		if (strcmp(instruction[i], option) == 0)
			return true;
	}
	return false;
}

//function that checks if option is in user menu options
//output: true - option in options; false - option not in options
bool InUserMenuOptions(char* option)
{
	char instruction[][20] = { "exit", "list", "save", "next", "mylist", "mode", "fileLocation", "mylistLocation"};
	for (int i = 0; i < 8; i++)
	{
		if (strcmp(instruction[i], option) == 0)
			return true;
	}
	return false;
}

//function that runs as Administrator
void UserInterface::runAsAdministrator()
{
	char UserInput[200] = "";
	char firstWord[20] = "";
	int length = 0;

	while (1)
	{
		try {
			printAdministratorMenu();
			readStringWithSpaces("\nWhat option do you choose: ", 200, UserInput);
			char parameters[300][300];
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

			if (strcmp(parameters[0], "fileLocation") == 0)
			{
				this->controller.setFile(string(parameters[1]));
			}

			if (strcmp(parameters[0], "mylistLocation") == 0)
			{
				this->controller.setMylistFile(string(parameters[1]));
			}

			//id, type, destination and price
			//add movie
			if (strcmp(parameters[0], "add") == 0)
			{
				addMovie(parameters);
			}

			//delete movie
			if (strcmp(parameters[0], "delete") == 0)
			{
				deleteMovie(parameters);
			}

			//update movie
			if (strcmp(parameters[0], "update") == 0)
			{
				updateMovie(parameters);
			}

			//list movies
			if (strcmp(parameters[0], "list") == 0)
			{
				//show what we have
				listAllMovies();
			}
		}
		catch (MovieException& exception)
		{
			this->printErrors(exception.getErrors());
		}
		catch (RepositoryException& exception)
		{
			cout << exception.what() << endl;
		}
		catch (FileException& exception)
		{
			cout << exception.what() << endl;
		}
	}
}

//function that runs as User
void UserInterface::runAsUser()
{
	char UserInput[200] = "";
	char firstWord[20] = "";
	int length = 0;
	int nextMovieCounter = -1;
	bool stillWatchingTrailer = false;
	std::vector<Movie> repositoryTrailer = getAllMovies();
	std::string Genre = "";
	int Likes = 0;

	while (1)
	{
		printUserMenu();
		readStringWithSpaces("\nWhat option do you choose: ", 200, UserInput);
		char parameters[300][300];
		returnParameters(UserInput, parameters, &length);
		
		try {

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

			if (strcmp(parameters[0], "fileLocation") == 0)
			{
				this->controller.setFile(string(parameters[1]));
			}

			if (strcmp(parameters[0], "mylistLocation") == 0)
			{
				this->controller.setMylistFile(string(parameters[1]));
			}


			//add movie to watch list
			if ((strcmp(parameters[0], "save") == 0) && (length == 2))
			{
				saveMovieWatchList(parameters[1]);
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
		catch (MovieException& exception)
		{
			this->printErrors(exception.getErrors());
		}
		catch (RepositoryException& exception)
		{
			cout << exception.what() << endl;
		}
		catch (FileException& exception)
		{
			cout << exception.what() << endl;
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

	char UserInput[200] = "";
	char firstWord[20] = "";
	int length = 0;

	while (1)
	{
		//printing menu, reading input, returning parameters
		printMenu();
		readStringWithSpaces("\nWhat option do you choose: ", 200, UserInput);
		char parameters[300][300];
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
		if (strcmp(parameters[0], "fileLocation") == 0)
		{
			this->controller.setFile(string(parameters[1]));
		}
		if (strcmp(parameters[0], "mylistLocation") == 0)
		{
			this->controller.setMylistFile(string(parameters[1]));
		}
	}
}

//propagate testing
void UserInterface::testUserInterface()
{
	Repository repositoryTesting{};
	Controller controllerTesting(&repositoryTesting, MovieValidator{});
	controllerTesting.testController();
}