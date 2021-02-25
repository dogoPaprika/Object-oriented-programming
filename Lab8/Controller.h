#pragma once

#include "CSVRepository.h"
#include "MovieValidator.h"



class Controller
{
private:
	CSVRepository repository;
	MovieValidator validator;

public:
	//Constructor with parameters
	Controller(const CSVRepository& repository, MovieValidator validator) : repository(repository), validator(validator) {}

	std::vector<Movie> getMovies() { return repository.getArray(); }
	int getSizeController() { return this->repository.getSize(); }

	int findMovieController(Movie movie);

	Movie getMovie(int position);

	void findMovieByTitle(std::string title, Movie &movie);

	
	void addMovieController(std::string title, std::string genre, int year, int likes, std::string trailer);

	
	void deleteMovieController(std::string title);

	
	void updateMovieController(std::string title, std::string newGenre, int newYear, int newLikes, std::string newTrailer);

	void setFile(std::string path);


	void static testController();
	void static testAddController();
	void static testDeleteController();
	void static testUpdateController();



//#####################################  WatchList ####################################

	///*
	//Saves the shopbasket to an appropriate file type (CSV or HTML).
	//Throws: FileException - if the given file cannot be opened.
	//*/
	//void saveWatchList();

	///*
	//Opens the shopbasket, with an appropriate application.
	//Throws: FileException - if the given file cannot be opened.
	//*/
	//void openWatchList() const;

	void addMovieWatchListController(Movie movie);
	std::vector<Movie> getWatchList() { return this->repository.getVector();  }


};