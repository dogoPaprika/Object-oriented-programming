#include "RepositoryExceptions.h"

FileException::FileException(const std::string & msg) : message(msg)
{
}

std::string FileException::what()
{
	return message;
}

RepositoryException::RepositoryException() : exception{}, message{ "" }
{
}

RepositoryException::RepositoryException(const std::string & msg) : message{ msg }
{
}

std::string RepositoryException::what()
{
	return this->message;
}

std::string DuplicateMovieException::what()
{
	return "There is another movie with this name!";
}

std::string InexistentMovieException::what()
{
	return "There is no movie with this name!";
}

void RepositoryException::testRepositoryException()
{
	DuplicateMovieException duplicateException{};
	assert(duplicateException.what() == "There is another movie with this name!");
	InexistentMovieException inexistentException{};
	assert(inexistentException.what() == "There is no movie with this name!");
	RepositoryException repositoryException{"Message specific to a repository exception!"};
	assert(repositoryException.what() == "Message specific to a repository exception!");
}

void FileException::testFileException()
{
	FileException fileException{ "Message specific to a file exception!" };
	assert(fileException.what() == "Message specific to a file exception!");
}