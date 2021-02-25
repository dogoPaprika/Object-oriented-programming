#include "_movie.h"

/*
Constructs a movie with parameters.
*/
Movie::Movie(const std::string& title, const std::string& genre, int year, int likes, const std::string& trailer)
{
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->likes = likes;
	this->trailer = trailer;
}


Movie::~Movie()
{
	//empty for now
}


Movie::Movie(const Movie& copiedMovie)
{
	this->title = copiedMovie.title;
	this->genre = copiedMovie.genre;
	this->year = copiedMovie.year;
	this->likes = copiedMovie.likes;
	this->trailer = copiedMovie.trailer;
}

/*
Transforms the object in a string and returns the string.
*/
std::string Movie::toString()
{
	std::stringstream movieToString;
	movieToString << "Title: " << this->title << ", genre: " << this->genre << ", year: " << this->year << ", likes: " << this->likes << ", trailer: " << this->trailer << std::endl;
	return movieToString.str();
}



/*
Returns 1 if they are equal.
*/
bool Movie::operator==(const Movie& movie)
{
	if (this->getTitle() != movie.getTitle())
		return false;

	return true;
}

Movie& Movie::operator=(const Movie& movie)
{
	this->title = movie.title;
	this->genre = movie.genre;
	this->year = movie.year;
	this->likes = movie.likes;
	this->trailer = movie.trailer;

	return *this;
}


//TESTS
void testMovieGetter()
{
	Movie movie{ "Atomic Blonde", "action", 2016, 10000, "https://www.youtube.com/watch?v=yIUube1pSC0" };

	//getters
	assert(movie.getTitle() == "Atomic Blonde");
	assert(movie.getGenre() == "action");
	assert(movie.getYear() == 2016);
	assert(movie.getLikes() == 10000);
	assert(movie.getTrailer() == "https://www.youtube.com/watch?v=yIUube1pSC0");
}

void testMovieSetter()
{

	Movie movie{};

	//setters
	movie.setTitle("Sherlock Holmes");
	movie.setGenre("mistery");
	movie.setYear(2008);
	movie.setLikes(16000);
	movie.setTrailer("https://www.youtube.com/watch?v=J7nJksXDBWc");

	assert(movie.getTitle() == "Sherlock Holmes");
	assert(movie.getGenre() == "mistery");
	assert(movie.getYear() == 2008);
	assert(movie.getLikes() == 16000);
	assert(movie.getTrailer() == "https://www.youtube.com/watch?v=J7nJksXDBWc");
}

void testMovieOperators()
{
	Movie movie1{ "Atomic Blonde", "action", 2016, 10000, "https://www.youtube.com/watch?v=yIUube1pSC0" };
	Movie movie2{ "Atomic Blonde", "action", 2016, 10000, "https://www.youtube.com/watch?v=yIUube1pSC0" };
	assert(movie1 == movie2);

	//copy constructor
	Movie movie3 = movie1;
	assert(movie1 == movie3);
}

void testMovieToString()
{
	Movie movie("Atomic Blonde", "action", 2016, 10000, "https://www.youtube.com/watch?v=yIUube1pSC0");

	std::stringstream movieToString;
	movieToString << "Title: " << movie.getTitle() << ", genre: " << movie.getGenre() << ", year: " << movie.getYear() << ", likes: " << movie.getLikes() << ", trailer: " << movie.getTrailer() << std::endl;
	assert(movieToString.str() == movie.toString());
}

void Movie::testMovie()
{
	testMovieGetter();
	testMovieSetter();
	testMovieOperators();
	testMovieToString();
}