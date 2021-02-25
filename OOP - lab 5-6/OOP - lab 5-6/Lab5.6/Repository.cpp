#include "Repository.h"

Repository::Repository() {}

Movie* Repository::getAll()
{
	return this->dynamicArray.getAllElements();
}

int Repository::getSize()
{
	return this->dynamicArray.getSize();
}

Movie Repository::getMovie(int position)
{
	
	//if (position < 0 || position >= len)
		//return NULL;
	
	return this->dynamicArray[position];
}

void Repository::findMovieByTitle(std::string title, Movie &movie)
{
	std::cout << getSize();
	for (int i = 0; i < getSize(); i++)
		if (title == dynamicArray[i].getTitle())
		{
			movie.setGenre(dynamicArray[i].getGenre());
			std::cout << "am gasit";
			return;
		}
}

bool Repository::addMovie(const Movie& newMovie)
{
	int position = dynamicArray.find(newMovie);
	if (position != -1)
		return false;

	dynamicArray.add(newMovie);
	return true;
}

bool Repository::deleteMovie(const Movie& movie)
{
	int position = dynamicArray.find(movie);
	if (position == -1)
		return false;

	this->dynamicArray.remove(position);
	return true;
}

bool Repository::updateMovie(Movie& movie1, Movie& movie2)
{
	int position = dynamicArray.find(movie1);
	if (position == -1)
		return false;
	
	dynamicArray[position] = movie2;

	return true;
}

int Repository::findMovieRepository(Movie movie)
{
	for (int i = 0; i < dynamicArray.getSize(); i++)
		if (dynamicArray[i] == movie)
			return i;
		
	return -1;
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

void Repository::testAdd_LengthRepository()
{
	Repository testRepository;
	initiateRepositoryTest(testRepository);

	int lengthRepository = testRepository.getSize();
	assert(lengthRepository == 10);

	//Add
	Movie movie1("Babadoock", "horror", 2015, 24000, "https://www.youtube.com/watch?v=k5WQZzDRVtw");
	testRepository.addMovie(movie1);
	assert(testRepository.getSize() == lengthRepository + 1);
	assert(testRepository.addMovie(movie1) == false);//add it again, must return false
}

void Repository::testDeleteRepository()
{
	Repository testRepository;
	initiateRepositoryTest(testRepository);

	int lengthRepository = testRepository.getSize();

	//Delete
	Movie movie = testRepository.getMovie(1);
	testRepository.deleteMovie(movie);
	assert(testRepository.getSize() == lengthRepository - 1);
	assert(testRepository.deleteMovie(movie) == false); //Element cant be found so it returns false
}

void Repository::testUpdateRepository()
{
	Repository testRepository;
	initiateRepositoryTest(testRepository);

	int lengthRepository = testRepository.getSize();

	//Update
	Movie movie = testRepository.getMovie(3);
	Movie movieUpdate{ movie.getTitle(), "comedy", 2013, 25000, "https://www.youtube.com/watch?v=JsMFggMLgY0" };
	testRepository.updateMovie(movie, movieUpdate);
	
	int position = testRepository.dynamicArray.find(movie);
	Movie movieTest = testRepository.getMovie(position);
	
	assert(movieTest.getGenre() == "comedy");
	assert(movieTest.getYear() == 2013);
	assert(movieTest.getLikes() == 25000);
	assert(movieTest.getTrailer() == "https://www.youtube.com/watch?v=JsMFggMLgY0");
}

void Repository::testGetArrayRepository()
{
	//getArray()
	Repository testRepository;
	initiateRepositoryTest(testRepository);

	int lengthRepository = testRepository.getSize();
	Movie movie1 = testRepository.getMovie(1);
	testRepository.deleteMovie(movie1);
	Movie movie2 = testRepository.getMovie(2);
	testRepository.deleteMovie(movie2);
	Movie movie3 = testRepository.getMovie(3);
	testRepository.deleteMovie(movie3);
	Movie movie4("Babadoock", "horror", 2015, 24000, "https://www.youtube.com/watch?v=k5WQZzDRVtw");
	testRepository.addMovie(movie4);

	DynamicArray<Movie> arrayAuxiliarry = testRepository.getArray();
	assert(arrayAuxiliarry.getSize() == lengthRepository - 2);//delete, delete, delete, add
}

void Repository::testRepository()
{
	//calling the testing function of a movie from movie.h
	Movie movieTesting;
	movieTesting.testMovie();


	testAdd_LengthRepository();
	testDeleteRepository();
	testUpdateRepository();
	testGetArrayRepository();
}



bool Repository::addMovieWatchList(const Movie& movie)
{
	if (watchListArray.find(movie) != -1)
		return false;

	this->watchListArray.add(movie);
	return true;
}
