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
	bool addMovieUserInterface(char parameters[][30]);

	//calls the controller function of deleting an existing movie
	bool deleteMovieUserInterface(char parameters[][30]);

	//calls the update function from controller
	bool updateMovieUserInterface(char parameters[][30]);


	void listWatchList();

	bool saveMovieUserInterface(string movieTitle);

	void displayGenreUserInterface(string genre);

	void displayMoviesByGenreAndLikes(string genre, int likes);

	DynamicArray<Movie> getAllMovies();
	void displayMovieOnPosition(DynamicArray<Movie> movie, int &position);
	int changePositionByGenre(DynamicArray<Movie> repository, string genre, int nextMovieCounter);
	int changePositionByGenreAndLikes(DynamicArray<Movie> repository, string genre, int likes, int nextMovieCounter);
	int changeNext(bool listNormal, bool listGenre, bool listGenreLikes, DynamicArray<Movie> repository, string genre, int likes, int nextMovieCounter);

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