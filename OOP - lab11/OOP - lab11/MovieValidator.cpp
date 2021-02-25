#include "_MovieValidator.h"
using namespace std;

MovieValidator::MovieValidator() {}

//Validator of object
void MovieValidator::validate(const Movie& movie)
{
	vector<string> errors;

	if (movie.getTrailer().size() <= 0)
		errors.push_back("Trailer cannot be empty!\n");
	if (movie.getGenre().size() <= 0)
		errors.push_back("Genre cannot be empty!\n");
	if (movie.getTitle().size() <= 0)
		errors.push_back("Title cannot be empty!\n");
	if (movie.getYear() < 0)
		errors.push_back("Year cannot be negative!\n");
	if (movie.getLikes() < 0)
		errors.push_back("Likes must be positive!\n");

	////verify if "www" and "http" are at the beggining
	//int positionWww = movie.getTrailer().find("www");
	//int positionHttp = movie.getTrailer().find("http");

	//if (positionWww != 0 && positionHttp != 0)
	//	errors.push_back("The Trailer source must start with one of the following strings: \"www\" or \"http\" !\n");

	if (errors.size() > 0)
		throw MovieException(errors);
}

void MovieValidator::testValidator()
{
	Movie movieInvalid{ "", "", -1, -1, "" };

	MovieValidator movieValidator;

	vector<string> errorsTest;
	errorsTest.push_back("Trailer cannot be empty!\n");
	errorsTest.push_back("Genre cannot be empty!\n");
	errorsTest.push_back("Title cannot be empty!\n");
	errorsTest.push_back("Year cannot be negative!\n");
	errorsTest.push_back("Likes must be positive!\n");

	try {
		movieValidator.validate(movieInvalid);
	}
	catch (MovieException errors)
	{
		assert(errors.getErrors() == errorsTest);
	}
}