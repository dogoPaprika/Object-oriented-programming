#include "Repository.h"
#include "RepositoryExceptions.h"

Repository::Repository() 
{
}

int Repository::getSize()
{
	return this->movies.size();
}

Movie Repository::getMovie(int position)
{
	
	int length = this->getSize();

	if (position < 0 || position >= length)
		throw InexistentMovieException();

	return this->movies[position];
}

int Repository::findMovie(const Movie& movie)
{
	for (int i = 0; i < this->getSize(); i++)
	{
		if (this->getMovie(i) == movie)
			return i;
	}
	return -1;
}

void Repository::addMovie(const Movie& newMovie)
{
	if (this->findMovie(newMovie) != -1)
		throw DuplicateMovieException();

	this->movies.push_back(newMovie);
}

void Repository::deleteMovie(const Movie& movie)
{
	//Check if what we want to delete does not exist
	int pos = this->findMovie(movie);
	if (pos == -1)
		throw InexistentMovieException();

	this->movies.erase(movies.begin() + pos);
}

void Repository::updateMovie(Movie& movie1, Movie& movie2)
{
	int pos = this->findMovie(movie1);

	//updating smth inexistent?
	if (pos == -1)
		throw InexistentMovieException();

	this->movies[pos] = movie2;
}


//TESTS
void Repository::initiateRepositoryTest(Repository& repositoryInitiate)
{
	Movie movie1("Brandersnatch", "thriller", 2018, 50000, "https://www.youtube.com/watch?v=XM0xWpBYlNM&t=34s");
	Movie movie2("Figh Club", "action", 2005, 45000, "https://www.youtube.com/watch?v=qtRKdVHc-cE");
	Movie movie3{"Oblivion", "Sci-Fiction", 2014, 35000, "https://www.youtube.com/watch?v=XmIIgE7eSak"};
	Movie movie4{"I origins", "mistery", 2015, 25000, "https://www.youtube.com/watch?v=Mk4briOLrTQ"};
	Movie movie5{"The Illusionist", "romance", 2008, 23000, "https://www.youtube.com/watch?v=i0xO64icGSY"};
	Movie movie6{"Transformers: Dark side of the Moon", "action", 2011, 40000, "https://www.youtube.com/watch?v=kHRf01Gjosk"};
	Movie movie7{"Interstellar", "Sci-Fiction", 2016, 55000, "https://www.youtube.com/watch?v=2LqzF5WauAw"};
	Movie movie8{"The Zookeeper`s wife", "drama", 2018, 33000, "https://www.youtube.com/watch?v=eiEfrA6MWs4"};
	Movie movie9{"Project X", "comedy", 2015, 24000, "https://www.youtube.com/watch?v=3BEIhA8CcY0"};
	Movie movie10{"The Hobbit: Battle of five armies", "fantasy", 2015, 49000, "https://www.youtube.com/watch?v=iVAgTiBrrDA"};

	repositoryInitiate.addMovie(movie1);
	repositoryInitiate.addMovie(movie2);
	repositoryInitiate.addMovie(movie3);
	repositoryInitiate.addMovie(movie4);
	repositoryInitiate.addMovie(movie5);
	repositoryInitiate.addMovie(movie6);
	repositoryInitiate.addMovie(movie7);
	repositoryInitiate.addMovie(movie8);
	repositoryInitiate.addMovie(movie9);
	repositoryInitiate.addMovie(movie10);
}

void Repository::testLengthRepository()
{
	Repository testRepository;
	initiateRepositoryTest(testRepository);

	int lengthRepository = testRepository.getSize();
	assert(lengthRepository == 10);
}

void Repository::testGoodAddRepository()
{
	Repository testRepository;
	initiateRepositoryTest(testRepository);
	Movie movie1("Babadoock", "horror", 2015, 24000, "https://www.youtube.com/watch?v=k5WQZzDRVtw");
	
	testRepository.addMovie(movie1);
	assert(testRepository.getSize() == 11);
}

void Repository::testBadAddRepository()
{
	Repository testRepository;
	initiateRepositoryTest(testRepository);
	Movie movie1("Babadoock", "horror", 2015, 24000, "https://www.youtube.com/watch?v=k5WQZzDRVtw");
	
	testRepository.addMovie(movie1);
	try {
		testRepository.addMovie(movie1);/*add it again, must return false*/ }
	catch (RepositoryException& e) {
		return; } }

void Repository::testGoodDeleteRepository()
{
	Repository testRepository;
	initiateRepositoryTest(testRepository);
	Movie movie = testRepository.getMovie(1);
	
	testRepository.deleteMovie(movie);
	assert(testRepository.getSize() == 9);
}

void Repository::testBadDeleteRepository()
{
	Repository testRepository;
	initiateRepositoryTest(testRepository);
	Movie movie = testRepository.getMovie(1);
	
	testRepository.deleteMovie(movie);
	try {
		testRepository.deleteMovie(movie); }
	catch (RepositoryException& e){
		return; } }


void Repository::testUpdateRepository()
{
	Repository testRepository;
	initiateRepositoryTest(testRepository);

	int lengthRepository = testRepository.getSize();

	Movie movie = testRepository.getMovie(3);
	Movie movieUpdate{ movie.getTitle(), "comedy", 2013, 25000, "https://www.youtube.com/watch?v=JsMFggMLgY0" };
	testRepository.updateMovie(movie, movieUpdate);
	
	int position = testRepository.findMovie(movie);
	Movie movieTest = testRepository.getMovie(position);
	
	assert(movieTest.getGenre() == "comedy");
	assert(movieTest.getYear() == 2013);
	assert(movieTest.getLikes() == 25000);
	assert(movieTest.getTrailer() == "https://www.youtube.com/watch?v=JsMFggMLgY0");
}

void Repository::testGetArrayRepository()
{
	Repository testRepository;
	initiateRepositoryTest(testRepository);

	Movie movie1 = testRepository.getMovie(1);
	testRepository.deleteMovie(movie1);
	Movie movie2 = testRepository.getMovie(2);
	testRepository.deleteMovie(movie2);

	std::vector<Movie> vectorAuxiliarry = testRepository.getArray();
	assert(vectorAuxiliarry.size() == 8);
}



void Repository::testRepository()
{
	//calling the testing function of a movie from movie.h
	Movie movieTesting;
	movieTesting.testMovie();

	RepositoryException repositoryException{};
	repositoryException.testRepositoryException();

	testLengthRepository();
	testGoodAddRepository();
	testBadAddRepository();
	testGoodDeleteRepository();
	testBadDeleteRepository();
	testUpdateRepository();
	testGetArrayRepository();
}




