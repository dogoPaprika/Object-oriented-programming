#pragma once
#include "Wheather.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

class Repository
{
private:
	std::vector<Wheather> timeIntervals;
	std::vector<Wheather> precipitationIntervals;

public:
	Repository();
	std::vector<Wheather> getAll() const { return this->timeIntervals; }
	std::vector<Wheather> getAllPrecipitation() const { return this->precipitationIntervals; }

	void filterByPrec(int x);


	int sumHours(std::string desc);

	void readFromFile();
};


