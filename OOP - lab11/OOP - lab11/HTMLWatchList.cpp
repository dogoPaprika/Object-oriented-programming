#include "_HTMLWatchList.h"
#include <fstream>

using namespace std;

HTMLRepository::HTMLRepository(string path)
{
	this->source = path;
	this->readFromFile();
}

void HTMLRepository::readFromFile()
{
	char string[200];
	char title[100], genre[10], trailer[100];
	int year = 0, likes = 0;
	ifstream file(source);
	file.getline(string, 99);
	file.getline(string, 99);
	while (strcmp(string, "<tr><td>") == 0)
	{
		file.getline(title, 99);
		file.getline(string, 99);
		file.getline(genre, 9);
		file.getline(string, 99);
		file >> year; file.get();
		file.getline(string, 99);
		file >> likes; file.get();
		file.getline(string, 99);
		file.getline(trailer, 99);
		file.getline(string, 99);
		Movie movie(title, genre, year, likes, trailer);
		Repository::addMovie(movie);
		file.getline(string, 99);
	}

	file.close();
}

void HTMLRepository::writeToFile()
{
	ofstream file(source);
	file << "<html><body><table border=1><tr><th>Title</th><th>Genre</th><th>Year</th><th>Likes</th><th>Trailer</th></tr>\n";
	for (auto i : this->getArray())
		file << "<tr><td>\n" << i.getTitle() << "\n</td><td>\n" << i.getGenre() << "\n</td><td>\n" << i.getYear() << "\n</td><td>\n" << i.getLikes() << "\n</td><td>\n" << i.getTrailer() << "\n</td></tr>\n";
	file << "</table></body></html>";
	file.close();
}

HTMLRepository::~HTMLRepository()
{
	this->writeToFile();
}

void HTMLRepository::addMovie(const Movie& movie)
{
	Repository::addMovie(movie);
	this->writeToFile();
}

void HTMLRepository::deleteMovie(const Movie& movie)
{
	Repository::deleteMovie(movie);
	this->writeToFile();
}

void HTMLRepository::updateMovie(Movie& movie1, Movie& movie2)
{
	Repository::updateMovie(movie1, movie2);
	this->writeToFile();
}



void HTMLWatchList::readFromFile()
{
	char string[200];
	char title[100], genre[10], trailer[100];
	int year = 0, likes = 0;
	ifstream file(mylistLocation);
	file.getline(string, 99);
	file.getline(string, 99);
	while (strcmp(string, "<tr><td>") == 0)
	{
		file.getline(title, 99);
		file.getline(string, 99);
		file.getline(genre, 9);
		file.getline(string, 99);
		file >> year; file.get();
		file.getline(string, 99);
		file >> likes; file.get();
		file.getline(string, 99);
		file.getline(trailer, 99);
		file.getline(string, 99);
		Movie movie(title, genre, year, likes, trailer);
		WatchList::addMovieWatchList(movie);
		file.getline(string, 99);
	}

	file.close();
}

void HTMLWatchList::writeToFile()
{
	ofstream file(this->mylistLocation);

	file << "<html><body><table border=1><tr><th>Title</th><th>Genre</th><th>Year</th><th>Likes</th><th>Trailer</th></tr>\n";
	for (auto i : this->getVector())
		file << "<tr><td>\n" << i.getTitle() << "\n</td><td>\n" << i.getGenre() << "\n</td><td>\n" << i.getYear() << "\n</td><td>\n" << i.getLikes() << "\n</td><td>\n" << i.getTrailer() << "\n</td></tr>\n";
	file << "</table></body></html>";

	file.close();
}

void HTMLWatchList::addMovieWatchList(const Movie& movie)
{
	WatchList::addMovieWatchList(movie);
	this->writeToFile();
}