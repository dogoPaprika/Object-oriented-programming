#include "Controller.h"
#include <string.h>
using namespace std;
//function that returns the position of a movie in the repository
int Controller::findMovie(Movie movie)
{
	return repository->findMovie(movie);
}

//function that validates and adds a movie
void Controller::addMovie(std::string title, std::string genre, int year, int likes, std::string trailer)
{
	Movie movie{ title, genre, year, likes, trailer};

	this->validator.validate(movie);
	this->repository->addMovie(movie);
}

//function that deletes a movie
void Controller::deleteMovie(std::string title)
{
	Movie movieEmpty{title, "sss", 1, 1, "www"};

	this->validator.validate(movieEmpty);
	this->repository->deleteMovie(movieEmpty);
}

//function that updates a movie in the repository
void Controller::updateMovie(std::string title, std::string newGenre, int newYear, int newLikes, std::string newTrailer)
{
	Movie movie1{ title, "sss", 1, 1, "www" };
	Movie movie2{ title, newGenre, newYear, newLikes, newTrailer};

	this->validator.validate(movie2);
	this->repository->updateMovie(movie1, movie2);
}


//function that adds a movie to the WatchList
void Controller::addMovieWatchList(Movie movie)
{
	this->validator.validate(movie);
	this->repositoryWatchList->addMovieWatchList(movie);
}

//function that returns a movie from a specific position
//in: int - position
//out: Movie - the returned movie
Movie Controller::getMovie(int position)
{
	return repository->getMovie(position);
}

//function that finds a movie by Title
void Controller::findMovieByTitle(Movie &movie)
{
	for (auto currentMovie : repository->getArray())
		if (movie == currentMovie)
		{
			movie = currentMovie;
			return;
		}
}

//function that set a filename to a csv repository
void Controller::setFile(std::string string)
{
	delete this->repository;
	size_t foundCsv = string.find(".csv");
	size_t foundTxt = string.find(".txt");
	size_t foundHtml = string.find(".html");

	if ((foundCsv != string::npos) || (foundTxt != string::npos))
		this->repository = new CSVRepository(string);
	else if (foundHtml != string::npos)
		this->repository = new HTMLRepository(string);
}

void Controller::setMylistFile(std::string string)
{
	delete this->repositoryWatchList;
	size_t foundCsv = string.find(".csv");
	size_t foundTxt = string.find(".txt");
	size_t foundHtml = string.find(".html");

	if ((foundCsv != string::npos) || (foundTxt != string::npos))
		this->repositoryWatchList = new CSVWatchList(string);
	else if (foundHtml != string::npos)
		this->repositoryWatchList = new HTMLWatchList(string);
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
	Repository* repositoryTest = new CSVRepository{ "Movies.txt" };
	Controller controllerTest{ repositoryTest, MovieValidator{} };

	int lengthRepository = controllerTest.getSizeController();
	controllerTest.addMovie("Pirates of Caribean: Dead man tells no tales", "action", 2017, 36000, "https://www.youtube.com/watch?v=KpFMVcZ4o7U");
	assert(controllerTest.getSizeController() == lengthRepository + 1);

	delete repositoryTest;
}

void Controller::testDeleteController()
{
	Repository* repositoryTest = new CSVRepository{ "Movies.txt" };
	Controller controllerTest{ repositoryTest, MovieValidator{} };

	int lengthRepository = controllerTest.getSizeController();

	//controller delete function
	controllerTest.deleteMovie("Oblivion");
	controllerTest.deleteMovie("I origins");
	assert(controllerTest.getSizeController() == lengthRepository - 2);

	delete repositoryTest;
}

void Controller::testUpdateController()
{
	Repository* repositoryTest = new CSVRepository{ "Movies.txt" };
	Controller controllerTest{ repositoryTest, MovieValidator{} };

	//controller update function
	Movie movieBeforeUpdate = controllerTest.getMovies()[0];
	controllerTest.updateMovie(movieBeforeUpdate.getTitle(), "romance", 2008, 25000, "https://www.youtube.com/watch?v=6QRvTv_tpw0");

	int position = controllerTest.findMovie(movieBeforeUpdate);
	Movie movieAfterUpdate = controllerTest.getMovie(position);
	
	assert(movieAfterUpdate.getGenre() == "romance");
	assert(movieAfterUpdate.getYear() == 2008);
	assert(movieAfterUpdate.getLikes() == 25000);
	assert(movieAfterUpdate.getLikes() == 25000);
	assert(movieAfterUpdate.getTrailer() == "https://www.youtube.com/watch?v=6QRvTv_tpw0");

	delete repositoryTest;
}
//void testReadBadFile()
//{
//	try {
//		CSVRepository repositoryTest{ "NOTaFile.txt" };} 
//	catch (FileException& e) {
//		return;}
//}

void testAddMovieWatchList()
{
	Repository* repositoryTest = new CSVRepository{ "Movies.txt" };
	Controller controllerTest{ repositoryTest, MovieValidator{} };

	int lengthWatchList = controllerTest.getSizeWatchList();
	controllerTest.addMovieWatchList(Movie("Pirates of Caribean: Dead man tells no tales", "action", 2017, 36000, "https://www.youtube.com/watch?v=KpFMVcZ4o7U"));
	std::vector<Movie> testVector = controllerTest.getWatchList();
	
	assert(testVector.size() == lengthWatchList + 1);
	delete repositoryTest;
}

void Controller::testFindMovieByTitle()
{
	Repository* repositoryTest = new CSVRepository{ "Movies.txt" };
	Controller controllerTest{ repositoryTest, MovieValidator{} };

	Movie emptyMovie{ "Figh Club", "s", 1, 1, "s" };
	controllerTest.findMovieByTitle(emptyMovie);

	assert(emptyMovie.getGenre() == "action");
	assert(emptyMovie.getTitle() == "Figh Club");
	assert(emptyMovie.getYear() == 2005);

	delete repositoryTest;
}

void Controller::testFakeRepository()
{
	Repository* repositoryTest = new FakeRepository;
	Controller controllerTest{ repositoryTest, MovieValidator{} };

	Movie emptyMovie{ "FakeRepoMovie2", "s", 1, 1, "s" };
	controllerTest.findMovieByTitle(emptyMovie);

	assert(emptyMovie.getGenre() == "action");
	assert(emptyMovie.getTitle() == "FakeRepoMovie2");
	assert(emptyMovie.getYear() == 2005);

	delete repositoryTest;
}

void Controller::testSetPath()
{
	Repository* repositoryTest = new CSVRepository{ "Movies.txt" };
	Controller controllerTest{ repositoryTest, MovieValidator{} };

	controllerTest.setFile("abc.txt");
	delete repositoryTest;
}

//testing the controller
void Controller::testController()
{
	//calling the test function for a repository from repository.h
	Repository repositoryTesting;
	repositoryTesting.testRepository();

	//calling the test function for a validator from MovieValidator.h
	MovieValidator validatorTesting;
	validatorTesting.testValidator();

	//calling the test function for a csv repository
	CSVRepository repositoryCSVTesting;
	repositoryCSVTesting.testCSVRepository();
	
	//testAddMovieWatchList();
	//testSetPath();
	//testReadBadFile();
	testAddController();
	testDeleteController();
	testUpdateController();
	testFindMovieByTitle();
	

	testFakeRepository();
}

