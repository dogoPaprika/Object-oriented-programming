#pragma once

#include <iostream>
#include <string> 
#include <assert.h>
#include <sstream> 
#include <vector>
#include <fstream>
#include <Windows.h>
#include <shellapi.h> 
#include <algorithm> 


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

	static std::vector<std::string> tokenize(std::string s, char del)
	{
		std::stringstream ss(s);
		std::string aux;
		std::vector<std::string> res;
		while (getline(ss, aux, del))
			res.push_back(aux);
		return res;
	}

	friend std::istream& operator>>(std::istream & istream, Movie &movie)
	{
		std::string s;
		getline(istream, s);

		std::vector<std::string> result = tokenize(s, ',');
		if (result.size() != 5)
			return istream;

		movie.title = result[0];
		movie.genre = result[1];
		movie.year = atoi(result[2].c_str());
		movie.likes = atoi(result[3].c_str());
		movie.trailer = result[4];

		return istream;
	}
	friend std::ostream& operator<<(std::ostream & ostream, Movie &movie)
	{
		ostream << movie.title << "," << movie.genre << "," << movie.year << "," << movie.likes << "," << movie.trailer << '\n';
		return ostream;
	}
};