#pragma once

#include "Repository.h"


class Controller
{
private:
	Repository repository;

public:
	//Constructor with parameters
	Controller(const Repository& repository) : repository(repository) {}

	DynamicArray<Movie> getRepository() { return repository.getArray(); }
	int getSizeController() { return this->repository.getSize(); }

	int findMovieController(Movie movie);

	Movie getMovie(int position);

	void findMovieByTitle(std::string title, Movie &movie);

	
	bool addMovieController(std::string title, std::string genre, int year, int likes, std::string trailer);

	
	bool deleteMovieController(std::string title);

	
	bool updateMovieController(std::string title, std::string newGenre, int newYear, int newLikes, std::string newTrailer);

	Movie* getAllMovies();

	void static testController();
	void static testAddController();
	void static testDeleteController();
	void static testUpdateController();



//#####################################  WatchList ####################################


	bool addMovieWatchListController(Movie movie);
	DynamicArray<Movie> getWatchList() { return this->repository.getVector();  }


};