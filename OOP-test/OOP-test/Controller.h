#pragma once

#include "Repository.h"


class Controller
{
private:
	Repository repository;

public:

	Controller(const Repository& repository) : repository(repository) {}

	DynamicArray<Team> getRepository() { return repository.getArray(); }
	int getSizeController() { return this->repository.getSize(); }

	Team getTeam(int position)
	{
		return repository.getTeam(position);
	}


	bool addTeamController(std::string name, std::string country, int score)
	{
		Team team{ name, country, score };

		return this->repository.addTeam(team);
	}

	void static testController()
	{
		Repository repo;
		repo.TestAddTeam();
	}
};