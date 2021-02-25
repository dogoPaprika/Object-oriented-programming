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

	friend Movie fromStringToMovie(std::string string);
	friend std::string fromMovieToString(Movie movie);

	void addMovie(const Movie& newMovie) override;
	void deleteMovie(const Movie& movie) override;
	void updateMovie(Movie& movie1, Movie& movie2) override;

	void writeMylistToFile();

	void setFile(std::string path)
	{
		this->filename = path;
		this->readFromFile();
	}

	void static testCSVRepository();
	void static testCSVRepositoryDuplicateMovieException();
	void static testCSVRepositoryInexistentMovieException();

	~CSVRepository() { this->writeToFile(); }
};

class CSVWatchList : public WatchList {
private:
	std::string mylistLocation = "";

public:
	CSVWatchList() {}
	CSVWatchList(const std::string& filename) : mylistLocation{ filename } { this->readFromFile(); }
	void readFromFile();
	void writeToFile();
	~CSVWatchList() { this->writeToFile(); }
	void addMovieWatchList(const Movie& movie);

	friend Movie fromStringToMovie(std::string string);
	friend std::string fromMovieToString(Movie movie);
};