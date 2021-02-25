#include "UserInterface.h"
#include <Windows.h>
#include <crtdbg.h>
#include "FileRepository.h"
#include "CSVRepository.h"


void tests()
{
	UserInterface::testUserInterface();
	cout << "Tests succesfully passed!";
}

void start()
{
	CSVRepository csvRepository{};
	Controller controller{ csvRepository, MovieValidator{} };
	UserInterface userInterface{ controller };
	userInterface.run();
}

int main()
{
	//tests();

	start(); //so dynamic allocated objects are destroyed by destructors before memory leak check

	if (_CrtDumpMemoryLeaks())
		cout << "There are memory leaks!" << endl;

	//system("pause");
	return 0;
}