#include "Controller.h"

int Controller::findMovieController(Movie movie)
{
	return repository.findMovieRepository(movie);
}

bool Controller::addMovieController(std::string title, std::string genre, int year, int likes, std::string trailer)
{
	Movie movie{ title, genre, year, likes, trailer};

	return this->repository.addMovie(movie);
}

bool Controller::deleteMovieController(std::string title)
{
	Movie movieEmpty{title, "", 0, 0, ""};

	return this->repository.deleteMovie(movieEmpty);
}

bool Controller::updateMovieController(std::string title, std::string newGenre, int newYear, int newLikes, std::string newTrailer)
{
	Movie movie1{ title, "", 0, 0, "" };
	Movie movie2{ title, newGenre, newYear, newLikes, newTrailer};

	return this->repository.updateMovie(movie1, movie2);
}

bool Controller::addMovieWatchListController(Movie movie)
{
	return repository.addMovieWatchList(movie);
}

Movie Controller::getMovie(int position)
{
	return repository.getMovie(position);
}

void Controller::findMovieByTitle(std::string title, Movie &movie)
{
	for (int i = 0; i < repository.getSize(); i++)
		if (movie == repository.getMovie(i))
		{
			movie = repository.getMovie(i);
			return;
		}
}


// TESTS

void Controller::testAddController()
{
	Repository repositoryTest{};
	repositoryTest.initiateRepositoryTest(repositoryTest);
	Controller controllerTest{ repositoryTest };

	int lengthRepository = controllerTest.getSizeController();
	controllerTest.addMovieController("Pirates of Caribean: Dead man tells no tales", "action", 2017, 36000, "https://www.youtube.com/watch?v=KpFMVcZ4o7U");
	assert(controllerTest.getSizeController() == lengthRepository + 1);
}

void Controller::testDeleteController()
{
	Repository repositoryTest{};
	repositoryTest.initiateRepositoryTest(repositoryTest);
	Controller controllerTest{ repositoryTest };

	int lengthRepository = controllerTest.getSizeController();

	//controller delete function
	controllerTest.deleteMovieController("Oblivion");
	controllerTest.deleteMovieController("I origins");
	assert(controllerTest.getSizeController() == lengthRepository - 2);
}

void Controller::testUpdateController()
{
	Repository repositoryTest{};
	repositoryTest.initiateRepositoryTest(repositoryTest);
	Controller controllerTest{ repositoryTest };

	//controller update function
	Movie movieBeforeUpdate = controllerTest.getRepository()[0];
	controllerTest.updateMovieController(movieBeforeUpdate.getTitle(), "romance", 2008, 25000, "https://www.youtube.com/watch?v=6QRvTv_tpw0");

	int position = controllerTest.findMovieController(movieBeforeUpdate);
	Movie movieAfterUpdate = controllerTest.getRepository()[position];
	
	assert(movieAfterUpdate.getGenre() == "romance");
	assert(movieAfterUpdate.getYear() == 2008);
	assert(movieAfterUpdate.getLikes() == 25000);
	assert(movieAfterUpdate.getLikes() == 25000);
	assert(movieAfterUpdate.getTrailer() == "https://www.youtube.com/watch?v=6QRvTv_tpw0");
}

void Controller::testController()
{
	//calling the test function for a repository from repository.h
	Repository repositoryTesting;
	repositoryTesting.testRepository();

	testAddController();
	testDeleteController();
	testUpdateController();	
}

