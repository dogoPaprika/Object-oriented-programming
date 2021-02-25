#pragma once
#include "Repository.h"

class CSVRepository : public Repository
{
private:
	std::string filename;
public:
	CSVRepository() {}
	CSVRepository(const std::string& filename) : filename{ filename } { this->readFromFile(); }

	void writeToFile();
	
	void readFromFile();
	
	Movie fromStringToMovie(std::string string);
	std::string fromMovieToString(Movie movie);

	void addMovie(const Movie& newMovie);
	void deleteMovie(const Movie& movie);
	void updateMovie(Movie& movie1, Movie& movie2);

	void setFile(std::string path)
	{
		this->filename = path;
		this->readFromFile();
	}


	//~CSVRepository() { this->writeToFile(); }
};