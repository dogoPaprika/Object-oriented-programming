#pragma once

#include <iostream>
#include <string> //for stoi()
#include <assert.h>
#include <sstream> //for toString()

#include <Windows.h>
#include <shellapi.h> //for display()

/*
A movie has a title, a genre, a year of release, a number of likes and a trailer (as a link).
*/
class Movie
{
private:
	std::string title;
	std::string genre;
	int year;
	int likes;
	std::string trailer;

public:
	//Constructor with default fields
	Movie() : title(""), genre(""), year(0), likes(0), trailer("") {};

	//Constructor with parameters
	Movie(const std::string& title, const std::string& genre, int year, int likes, const std::string& trailer);

	//Copy constructor
	Movie(const Movie& movie);

	//Destructor
	~Movie();

	Movie& operator=(const Movie& movie);
	bool operator==(const Movie& movie);

	//Getter function
	std::string getTitle() const { return this->title; }
	std::string getGenre() const { return this->genre; }
	int getYear() const { return this->year; }
	int getLikes() const { return this->likes; }
	std::string getTrailer() const { return this->trailer; }
	

	//Setter function
	void setTitle(std::string title) { this->title = title; }
	void setGenre(std::string genre) { this->genre = genre; }
	void setYear(int year) { this->year = year; }
	void setLikes(int likes) { this->likes = likes; }
	void setTrailer(std::string trailer) { this->trailer = trailer; }

	std::string toString();

	//Test the methods of the class.
	void static testMovie();
};