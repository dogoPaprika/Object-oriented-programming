#pragma once

#include "Controller.h"
using namespace std;

class UserInterface
{
private:
	Controller controller;

	static void printMenu();
	static void printAdministratorMenu();
	static void printUserMenu();

	//prints on screen all movies
	void listAllMovies();

	//calls the controller function of adding new movie
	void addMovie(char parameters[][300]);

	//calls the controller function of deleting an existing movie
	void deleteMovie(char parameters[][300]);

	//calls the update function from controller
	void updateMovie(char parameters[][300]);


	void listWatchList();

	void saveMovieWatchList(string movieTitle);

	void displayGenreUserInterface(string genre);

	void displayMoviesByGenreAndLikes(string genre, int likes);

	std::vector<Movie> getAllMovies();
	void displayMovieOnPosition(std::vector<Movie> movie, int &position);
	int changePositionByGenre(std::vector<Movie> repository, string genre, int nextMovieCounter);
	int changePositionByGenreAndLikes(std::vector<Movie> repository, string genre, int likes, int nextMovieCounter);
	int changeNext(bool listNormal, bool listGenre, bool listGenreLikes, std::vector<Movie> repository, string genre, int likes, int nextMovieCounter);

	/*
	Prints a vector of strings given by a catch block.
	*/
	void printErrors(std::vector<std::string> errs);

	/*
	Calls the function of saving shopbasket to a file from controller.
	*/
	void saveWatchListToFile();

public:
	UserInterface(const Controller& controller) : controller(controller) {}

	//Validates a movie object
	bool validate(string title, string genre, int year, int likes, string trailer);


	//Runs the program until stopped.
	void run();

	void runAsAdministrator();

	void runAsUser();

	void static testUserInterface();
};