#include "CSVRepository.h"
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
	ofstream fout(this->filename); //csv file in which we write

	if (!fout.is_open())
		throw FileException("The CSV could not be opened!");

	for (auto movie : this->getArray())
		fout << fromMovieToString(movie);

	fout.close();
}

void CSVRepository::readFromFile()
{
	std::ifstream fin(this->filename);

	//if (!fin.is_open())
	//	throw FileException("The file could not be opened!");

	string line;
	while (getline(fin, line))
		this->addMovie(this->fromStringToMovie(line));

	fin.close();
}

Movie CSVRepository::fromStringToMovie(std::string string)
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

std::string CSVRepository::fromMovieToString(Movie movie)
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
