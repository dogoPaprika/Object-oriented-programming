#include "Controller.h"

int Controller::findMovieController(Movie movie)
{
	return repository.findMovie(movie);
}

void Controller::addMovieController(std::string title, std::string genre, int year, int likes, std::string trailer)
{
	Movie movie{ title, genre, year, likes, trailer};

	this->validator.validate(movie);
	this->repository.addMovie(movie);
}

void Controller::deleteMovieController(std::string title)
{
	Movie movieEmpty{title, "sss", 1, 1, "www"};

	this->validator.validate(movieEmpty);
	this->repository.deleteMovie(movieEmpty);
}

void Controller::updateMovieController(std::string title, std::string newGenre, int newYear, int newLikes, std::string newTrailer)
{
	Movie movie1{ title, "sss", 1, 1, "www" };
	Movie movie2{ title, newGenre, newYear, newLikes, newTrailer};

	this->validator.validate(movie2);
	this->repository.updateMovie(movie1, movie2);
}

void Controller::addMovieWatchListController(Movie movie)
{
	this->validator.validate(movie);
	this->repository.addMovieWatchList(movie);
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

void Controller::setFile(std::string path)
{
	this->repository.setFile(path);
}
//
//void Controller::saveWatchList()
//{
//	if (this->watchList == nullptr)
//		return;
//
//	this->watchList->writeToFile();
//}
//
//void Controller::openWatchList() const
//{
//	if (this->watchList == nullptr)
//		return;
//
//	this->watchList->displayWatchList();
//}


// TESTS

void Controller::testAddController()
{
	CSVRepository repositoryTest{ "Movies.txt" };
	Controller controllerTest{ repositoryTest, MovieValidator{} };

	int lengthRepository = controllerTest.getSizeController();
	controllerTest.addMovieController("Pirates of Caribean: Dead man tells no tales", "action", 2017, 36000, "https://www.youtube.com/watch?v=KpFMVcZ4o7U");
	assert(controllerTest.getSizeController() == lengthRepository + 1);
}

void Controller::testDeleteController()
{
	CSVRepository repositoryTest{ "Movies.txt" };
	Controller controllerTest{ repositoryTest, MovieValidator{} };

	int lengthRepository = controllerTest.getSizeController();

	//controller delete function
	controllerTest.deleteMovieController("Oblivion");
	controllerTest.deleteMovieController("I origins");
	assert(controllerTest.getSizeController() == lengthRepository - 2);
}

void Controller::testUpdateController()
{
	CSVRepository repositoryTest{"Movies.txt"};
	Controller controllerTest{ repositoryTest, MovieValidator{} };

	//controller update function
	Movie movieBeforeUpdate = controllerTest.getMovies()[0];
	controllerTest.updateMovieController(movieBeforeUpdate.getTitle(), "romance", 2008, 25000, "https://www.youtube.com/watch?v=6QRvTv_tpw0");

	int position = controllerTest.findMovieController(movieBeforeUpdate);
	Movie movieAfterUpdate = controllerTest.getMovies()[position];
	
	assert(movieAfterUpdate.getGenre() == "romance");
	assert(movieAfterUpdate.getYear() == 2008);
	assert(movieAfterUpdate.getLikes() == 25000);
	assert(movieAfterUpdate.getLikes() == 25000);
	assert(movieAfterUpdate.getTrailer() == "https://www.youtube.com/watch?v=6QRvTv_tpw0");
}
void testReadBadFile()
{
	try {
		CSVRepository repositoryTest{ "NOTaFile.txt" };} 
	catch (FileException& e) {
		return;}
}


void Controller::testController()
{
	//calling the test function for a repository from repository.h
	Repository repositoryTesting;
	repositoryTesting.testRepository();
	
	testReadBadFile();
	testAddController();
	testDeleteController();
	testUpdateController();
}

