#pragma once

#include "Movie.h"
#include "DynamicArray.h"

class Repository
{
private:
	DynamicArray <Movie> dynamicArray;
	DynamicArray <Movie> watchListArray;

public:
	Repository(); //Constructor

	/*
	Returns the dynamic vector of the repository.
	*/
	DynamicArray<Movie> getArray() { return this->dynamicArray; }

	/*
	Returns a pointer to first element in dynamic vector's elements.
	*/
	Movie* getAll();

	/*
	Returns the size of the repository as an integer.
	*/
	int getSize();

	
	Movie getMovie(int position);

	int findMovieRepository(Movie movie);

	void findMovieByTitle(std::string title, Movie &movie);


	bool addMovie(const Movie& newMovie);

	
	bool deleteMovie(const Movie& movie);

	
	bool updateMovie(Movie& movie1, Movie& movie2);

	/*
	Tests the methods from repository class.
	*/
	void static initiateRepositoryTest(Repository& repository);
	void static testRepository();
	void static testAdd_LengthRepository();
	void static testDeleteRepository();
	void static testUpdateRepository();
	void static testGetArrayRepository();

	/*
	WatchList
	*/


	/*
	Returns the dynamic vector of the repository.
	*/
	DynamicArray<Movie> getVector() { return this->watchListArray; }
	/*
	Adds a trench coat in the shop basket in oder to be purchased.
	*/
	bool addMovieWatchList(const Movie& movie);
};