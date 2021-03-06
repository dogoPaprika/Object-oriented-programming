#pragma once
#include "Repository.h"
#include <fstream>
#include "RepositoryExceptions.h"



class FileRepository : public Repository
{
protected:
	std::string filename;

public:
	FileRepository(const std::string& filename) : filename(filename) {}
	virtual ~FileRepository() {}

	virtual void writeToFile() = 0;
	virtual void displayRepository() const = 0;
};