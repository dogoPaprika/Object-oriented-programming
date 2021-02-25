#pragma once

#include "Movie.h"
#include "RepositoryExceptions.h"

class Repository
{
protected:
	std::vector<Movie> movies;
	std::vector<Movie> watchListArray;

public:
	Repository(); //Constructor

	/*
	Returns the dynamic vector of the repository.
	*/
	std::vector<Movie>& getArray() { return this->movies; }

	/*
	Returns the size of the repository as an integer.
	*/
	int getSize();

	
	Movie getMovie(int position);

	int findMovie(const Movie &movie);


	void addMovie(const Movie& newMovie);

	
	void deleteMovie(const Movie& movie);

	
	void updateMovie(Movie& movie1, Movie& movie2);

	/*
	Tests the methods from repository class.
	*/
	void static initiateRepositoryTest(Repository& repository);
	void static testRepository();
	void static testLengthRepository();
	void static testGoodAddRepository();
	void static testBadAddRepository();
	void static testGoodDeleteRepository();
	void static testBadDeleteRepository();
	void static testUpdateRepository();
	void static testGetArrayRepository();

	/*
	WatchList
	*/


	/*
	Returns the dynamic vector of the repository.
	*/
	std::vector<Movie>& getVector() { return this->watchListArray; }
	/*
	Adds a trench coat in the shop basket in oder to be purchased.
	*/
	void addMovieWatchList(const Movie& movie);
};