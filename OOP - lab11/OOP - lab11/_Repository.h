#pragma once

#include "_Movie.h"
#include "_RepositoryExceptions.h"

class Repository
{
protected:
	std::vector<Movie> movies;


public:
	Repository(); //Constructor

	/*
	Returns the dynamic vector of the repository.
	*/
	virtual std::vector<Movie>& getArray() { return this->movies; }

	/*
	Returns the size of the repository as an integer.
	*/
	int getSize();


	Movie getMovie(int position);

	int findMovie(const Movie &movie);


	virtual void addMovie(const Movie& newMovie);


	virtual void deleteMovie(const Movie& movie);


	virtual void updateMovie(Movie& movie1, Movie& movie2);

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

};

class FakeRepository : public Repository {

public:

	std::vector<Movie>& getArray() override
	{
		Movie movie1("FakeRepoMovie1", "thriller", 2018, 50000, "https://www.youtube.com/watch?v=XM0xWpBYlNM&t=34s");
		Movie movie2("FakeRepoMovie2", "action", 2005, 45000, "https://www.youtube.com/watch?v=qtRKdVHc-cE");
		Movie movie3{ "FakeRepoMovie3", "Sci-Fiction", 2014, 35000, "https://www.youtube.com/watch?v=XmIIgE7eSak" };
		Movie movie4{ "FakeRepoMovie1", "mistery", 2015, 25000, "https://www.youtube.com/watch?v=Mk4briOLrTQ" };

		this->movies.push_back(movie1);
		this->movies.push_back(movie2);
		this->movies.push_back(movie3);
		this->movies.push_back(movie4);

		return this->movies;
	}

};

class WatchList
{
protected:
	std::vector<Movie> watchListArray{};

public:

	/*
	Returns the dynamic vector of the repository.
	*/
	virtual std::vector<Movie>& getVector() { return this->watchListArray; }
	/*
	Adds a trench coat in the shop basket in oder to be purchased.
	*/
	virtual void addMovieWatchList(const Movie& movie)
	{
		this->watchListArray.push_back(movie);
	}

	int getSizeWatchList()
	{
		return this->watchListArray.size();
	}

	virtual void mylistLocation(std::string) {};
};