#include "Repository.h"
#include <iostream>
using namespace std;

Repository::Repository()
{
	this->readFromFile();
}

//Description : computes the total time of hours for a given description of a time interval
//Input: desc - string
//Outpu: totalHours - int
int Repository::sumHours(std::string desc)
{
	int totalHours = 0;
	for (auto wheather : this->timeIntervals)
	{
		if (wheather.getDescription() == desc)
			totalHours += (wheather.getEnd() - wheather.getStart());
	}
	return totalHours;
}

void Repository::filterByPrec(int x)
{
	this->precipitationIntervals.clear();
	for (auto b : this->timeIntervals)
	{
		if (b.getPrecipitation() < double(x))
			this->precipitationIntervals.push_back(b);
	}
}



void Repository::readFromFile()
{
	ifstream fin("wheather.txt");

	if (!fin.is_open())
		return;

	Wheather b;
	while (fin >> b)
		this->timeIntervals.push_back(b);
}