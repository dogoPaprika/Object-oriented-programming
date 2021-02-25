#pragma once
#include "Repository.h"
#include <iostream>

class HTMLRepository : public Repository {

private:
	std::string source;

public:
	HTMLRepository(std::string source);
	void readFromFile();
	void writeToFile();
	~HTMLRepository();
	void addMovie(const Movie& newMovie) override;
	void deleteMovie(const Movie& movie) override;
	void updateMovie(Movie& movie1, Movie& movie2) override;
};

class HTMLWatchList : public WatchList {
private:
	std::string mylistLocation = "";

public:
	HTMLWatchList() {}
	HTMLWatchList(const std::string& filename) : mylistLocation{ filename } { this->readFromFile(); }
	void readFromFile();
	void writeToFile();
	~HTMLWatchList() { this->writeToFile(); }
	void addMovieWatchList(const Movie& movie);
	std::vector<Movie>& getVector() override 
	{
		system(mylistLocation.c_str()); return this->watchListArray;
	}
};