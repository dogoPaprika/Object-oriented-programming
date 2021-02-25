#pragma once

#include "CSVRepository.h"
#include "HTMLWatchList.h"
#include "MovieValidator.h"

class Controller
{
private:
	Repository* repository;
	WatchList* repositoryWatchList;
	MovieValidator validator;

public:
	//Constructor with parameters
	Controller(Repository* repository,  MovieValidator validator) : repository(repository),  validator(validator) {}
	Controller(Repository* repository, WatchList* repositoryWatchList, MovieValidator validator) : repository(repository), repositoryWatchList(repositoryWatchList), validator(validator) {}

	std::vector<Movie> getMovies() { return repository->getArray(); }
	int getSizeController() { return this->repository->getSize(); }

	int findMovie(Movie movie);

	Movie getMovie(int position);

	void findMovieByTitle(Movie &movie);

	
	void addMovie(std::string title, std::string genre, int year, int likes, std::string trailer);

	
	void deleteMovie(std::string title);

	
	void updateMovie(std::string title, std::string newGenre, int newYear, int newLikes, std::string newTrailer);

	void setFile(std::string path);
	void setMylistFile(std::string string);

	void static testController();
	void static testAddController();
	void static testDeleteController();
	void static testUpdateController();
	void static testFindMovieByTitle();
	void static testSetPath();
	void static testFakeRepository();

//#####################################  WatchList ####################################

	///*
	//Throws: FileException - if the given file cannot be opened.
	//*/
	//void saveWatchList();

	///*
	//Throws: FileException - if the given file cannot be opened.
	//*/
	//void openWatchList() const;

	void addMovieWatchList(Movie movie);
	std::vector<Movie> getWatchList() { return this->repositoryWatchList->getVector();  }
	int getSizeWatchList() { return this->repositoryWatchList->getSizeWatchList(); }
	void static testAddMovieWatchList();


};