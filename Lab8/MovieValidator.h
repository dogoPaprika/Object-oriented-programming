#pragma once
#include "Movie.h"

class MovieException
{
private:
	std::vector<std::string> errors;

public:
	//Constructor
	MovieException(std::vector<std::string> _errors) : errors(_errors) {}

	//Getter of strings
	std::vector<std::string> getErrors() const { return this->errors; }
};

class MovieValidator
{
public:
	MovieValidator();
	static void validate(const Movie& movie);
};