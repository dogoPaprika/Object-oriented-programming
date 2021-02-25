#include "Controller.h"
using namespace std;

Controller::Controller()
{
}

void Controller::addBuilding(Building * b)
{
	this->buildings.push_back(b);
}

std::vector<Building*> Controller::getAllBuildings()
{
	return this->buildings;
}

std::vector<Building*> Controller::getAllToBeDemolished()
{
	vector<Building*> res;

	for (auto a : this->buildings)
	{
		if (a->canBeDemolished())
			res.push_back(a);
	}
	return res;
}

std::vector<Building*> Controller::getAllToBeRestored()
{
	vector<Building*> res;

	for (auto a : this->buildings)
	{
		if (a->mustBeRestored())
			res.push_back(a);
	}
	return res;
}

void Controller::writeToFile(std::string filenameDemolished, std::string filenameRestored,std::vector <Building*> res)
{
	ofstream g1(filenameDemolished);
	ofstream g2(filenameRestored);

	if (!g1.is_open() && !g2.is_open())
		cout << "Not opened file!";

	for (auto building : res)
	{

		if (dynamic_cast<Block*>(building) == nullptr)
		{
			House* house = dynamic_cast<House*>(building);
			if (house->mustBeRestored())
				g2 << house->toString() << std::endl;
			if (house->canBeDemolished())
				g1 << house->toString() << std::endl;
		}
		else
		{
			Block* block = dynamic_cast<Block*>(building);
			if (block->mustBeRestored())
				g2 << block->toString()<<std::endl;
			if (block->canBeDemolished())
				g1 << block->toString()<<std::endl;
		}
	}

	g1.close();
	g2.close();
}
