#include "_CSVRepository.h"
using namespace std;

void CSVRepository::addMovie(const Movie& newMovie)
{
	Repository::addMovie(newMovie);
	this->writeToFile();
}

void CSVRepository::deleteMovie(const Movie& movie)
{
	Repository::deleteMovie(movie);
	this->writeToFile();
}

void CSVRepository::updateMovie(Movie& movie1, Movie& movie2)
{
	Repository::updateMovie(movie1, movie2);
	this->writeToFile();
}

void CSVRepository::writeToFile()
{
	ofstream fileout(this->filename); //csv file in which we write

	/*if (!fout.is_open())
		throw FileException("The CSV could not be opened!");*/

	for (auto movie : this->getArray())
		fileout << fromMovieToString(movie);

	fileout.close();
}


void CSVRepository::readFromFile()
{
	std::ifstream filein(this->filename);

	//if (!fin.is_open())
	//	throw FileException("The file could not be opened!");

	string line;
	while (getline(filein, line))
	{
		this->addMovie(fromStringToMovie(line));
	}

	filein.close();
}

Movie fromStringToMovie(std::string string)
{
	int i = 0;
	int literalCount = 0;
	int parameterCount = 0;
	char parameters[200][200];
	while (i < string.size())
	{
		if (string[i] != ',')
		{
			parameters[parameterCount][literalCount] = string[i];
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
	parameters[parameterCount][literalCount] = '\0';
	Movie movie{ std::string(parameters[0]), std::string(parameters[1]), atoi(parameters[2]), atoi(parameters[3]), std::string(parameters[4]) };
	return movie;
}

std::string fromMovieToString(Movie movie)
{
	string movieToString = "";
	movieToString += string(movie.getTitle());
	movieToString += ",";
	movieToString += string(movie.getGenre());
	movieToString += ",";
	movieToString += std::to_string(movie.getYear());
	movieToString += ",";
	movieToString += std::to_string(movie.getLikes());
	movieToString += ",";
	movieToString += string(movie.getTrailer());
	movieToString += "\0";
	movieToString += "\n";
	return movieToString;

}

void CSVRepository::testCSVRepositoryDuplicateMovieException()
{
	CSVRepository repositoryTest{ "Movies.txt" };
	try {
		repositoryTest.addMovie(Movie{ "I origins", "ss", 1, 1, "ss" });
	}
	catch (DuplicateMovieException duplicateException)
	{
		return;
	}
}

void CSVRepository::testCSVRepositoryInexistentMovieException()
{
	CSVRepository repositoryTest{ "Movies.txt" };
	try {
		repositoryTest.deleteMovie(Movie{ "NonExistentMovie", "ss", 1, 1, "ss" });
	}
	catch (InexistentMovieException duplicateException)
	{
		return;
	}
}

void CSVRepository::testCSVRepository()
{
	testCSVRepositoryDuplicateMovieException();
	testCSVRepositoryInexistentMovieException();

	FileException fileException{};
	fileException.testFileException();
}




void CSVWatchList::readFromFile()
{
	std::ifstream filein(this->mylistLocation);

	//if (!fin.is_open())
	//	throw FileException("The file could not be opened!");

	string line;
	while (getline(filein, line))
	{
		this->addMovieWatchList(fromStringToMovie(line));
	}

	filein.close();
}

void CSVWatchList::writeToFile()
{
	ofstream fileout(this->mylistLocation);

	for (auto movie : this->getVector())
		fileout << fromMovieToString(movie);

	fileout.close();
}

void CSVWatchList::addMovieWatchList(const Movie& movie)
{
	WatchList::addMovieWatchList(movie);
	this->writeToFile();
}
