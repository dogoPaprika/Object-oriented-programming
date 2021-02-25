#pragma once
#include "Repository.h"

class Controller {
private:
	Repository& repository;
public:
	Controller(Repository& repo) : repository{ repo } {};
	~Controller() {};
	
	void filterController(int prec)
	{
		this->repository.filterByPrec(prec);
	}
	int sumHoursController(std::string desc)
	{
		return this->repository.sumHours(desc);
	}
	std::vector<Wheather> getAll() const { return this->repository.getAll();  }
	std::vector<Wheather> getAllPrecipitation() const { return this->repository.getAllPrecipitation(); }
};