#pragma once
#include "Building.h"
#include "House.h"
#include "Block.h"
#include <vector>
#include <iostream>
#include <fstream>

class Controller
{
private:
	std::vector<Building*> buildings;

public:
	Controller();
	void addBuilding(Building* b);
	std::vector<Building*> getAllBuildings();
	std::vector<Building*> getAllToBeDemolished();
	std::vector<Building*> getAllToBeRestored();
	void writeToFile(std::string filename1, std::string filename2, std::vector<Building*> res);
};

