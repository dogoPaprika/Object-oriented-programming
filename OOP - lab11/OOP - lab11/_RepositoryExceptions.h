#pragma once
#include <string>
#include <exception>
#include <assert.h>

class FileException : public std::exception
{
protected:
	std::string message;

public:
	FileException() {};
	FileException(const std::string& message);
	virtual std::string what();
	void static testFileException();
};

class RepositoryException : public std::exception
{
protected:
	std::string message;

public:
	RepositoryException();
	RepositoryException(const std::string& message);
	virtual ~RepositoryException() {}
	virtual std::string what();
	void static testRepositoryException();
};

class DuplicateMovieException : public RepositoryException
{
public:
	std::string what();
};

class InexistentMovieException : public RepositoryException
{
public:
	std::string what();
};