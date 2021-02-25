#pragma once
#include "Controller.h"
#include "House.h"
#include "Block.h"
#include "Building.h"
#include <vector>

class UserInterface
{
private:
	Controller ctrl;

	static void printMenu();

	void addBuildingCommand();

	void displayAll();
	void displayAllToBeDemolished();
	void displayAllToBeRestored();

	void saveToFile();


public:
	UserInterface();
	UserInterface(const Controller& c) : ctrl(c) {}

	void run();
};


