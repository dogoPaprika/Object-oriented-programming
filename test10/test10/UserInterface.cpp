
#include "UserInterface.h"
using namespace std;

UserInterface::UserInterface()
{
}

void UserInterface::printMenu()
{
	cout << "MENU: " << endl;
	cout << "1 - add new building" << endl;
	cout << "2 - display all" << endl;
	cout << "3 - display all to be demolished" << endl;
	cout << "4 - display all to be restored" << endl;
	cout << "5 - save to file restored/ demoloshed buildings" << endl;
	cout << "0 - exit" << endl;

}

void UserInterface::addBuildingCommand()
{
	string address = "";
	int constructionYear = 0;
	char buffer[200];

	string type = "";
	bool isHistorical = 0;
	
	int totalApartments = 0;
	int occupiedApartments = 0;

	cout << "Give address: ";
	cin >> address;
	cout << "Give construction Year:";
	cin >> constructionYear;

	Building* b;

	int opt = 0;
	cout << "What type of building (1 - block, 2 - house): ";
	cin >> opt;

	try
	{
		switch (opt)
		{
			//block
		case 1:
			cout << "Give total aparments:";
			cin >> totalApartments;
			cout << "Give occupied apartments:";
			cin >> occupiedApartments;

			b = new Block{ address, constructionYear, totalApartments, occupiedApartments };
			this->ctrl.addBuilding(b);
			break;

			//house
		case 2:
			cout << "Give type:";
			cin >> type;
			cout << "It`s historical?:";
			cin >> isHistorical;

			b = new House{ address, constructionYear, type, isHistorical };
			this->ctrl.addBuilding(b);
			break;

		default:
			cout << "Invalid type!" << endl;
		}
	}
	catch (...)
	{

	}
}

void UserInterface::displayAll()
{
	vector<Building*> res = this->ctrl.getAllBuildings();

	if (res.size() == 0)
	{
		cout << "Its empty." << endl;
		return;
	}

	for (auto a : res)
		cout << a->toString() << endl;
}


void UserInterface::displayAllToBeDemolished()
{
	vector<Building*> res = this->ctrl.getAllToBeDemolished();

	if (res.size() == 0)
	{
		cout << "Its empty." << endl;
		return;
	}

	for (auto a : res)
		cout << a->toString() << endl;
}

void UserInterface::displayAllToBeRestored()
{
	vector<Building*> res = this->ctrl.getAllToBeRestored();

	if (res.size() == 0)
	{
		cout << "Its empty." << endl;
		return;
	}

	for (auto a : res)
		cout << a->toString() << endl;
}

void UserInterface::saveToFile()
{
	vector<Building*> res = this->ctrl.getAllBuildings();

	this->ctrl.writeToFile("demolished.txt", "restored.txt", res);
}

void UserInterface::run()
{
	int opt = 0;

	while (1)
	{
		UserInterface::printMenu();
		cout << "What option do you choose: ";
		cin >> opt;

		if (opt == 0)
			break;

		switch (opt)
		{
		case 1:
			this->addBuildingCommand();
			break;

		case 2:
			this->displayAll();
			break;

		case 3:
			this->displayAllToBeDemolished();
			break;
		case 4:
			this->displayAllToBeRestored();
			break;
		case 5:
			this->saveToFile();
			break;

		default:
			cout << "Invalid option!" << endl;
		}

	}


}