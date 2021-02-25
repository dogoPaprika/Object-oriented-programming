#include "UserInterface.h"
#include <crtdbg.h>
#include <Windows.h>

/*
Checks if the program has memory leaks.
IN:-
OUT:-
*/
void checkMemoryLeaks()
{
	if (_CrtDumpMemoryLeaks())
	{
		printf("\nThere are memory leaks!\n");
	}
	system("pause");
	return;
}

void tests()
{
	testOffer();
	testDynamicArray();
	testOfferRepository();
	testOperationsStack();
	testController();
}

/*
Makes up everything.
IN:-
OUT:-
*/
int main() {

	tests();
	//checkMemoryLeaks();
	//return 1;

	
	OperationsStack* undoStack = createStack();
	OperationsStack* redoStack = createStack();
	DynamicArray* newDynamicArray = createDynamicArray(100, destroyOffer);
	OfferRepository* newRepository = createRepository(newDynamicArray);
	Controller* newController = createController(newRepository, undoStack, redoStack);

	
	addOfferController(newController, 1, "seaside", "Sardinia", 70.5);
	addOfferController(newController, 2, "mountain", "Honduras", 87.6);
	addOfferController(newController, 3, "seaside", "Hawai", 120.0);
	addOfferController(newController, 4, "mountain", "Alpi", 50.8);
	addOfferController(newController, 5, "mountain", "Kilimindjaro", 100, 45.0);
	addOfferController(newController, 6, "seaside", "Ururu", 70.55);
	addOfferController(newController, 7, "zoro", "Varsow", 45.75);
	addOfferController(newController, 8, "citybreak", "Boston", 180.99);
	addOfferController(newController, 9, "citybreak", "Taiwan", 120.99);
	addOfferController(newController, 10, "ashore", "Rio", 10.99);
	

	UserInterface* newUserInterface = createUserInterface(newController);

	startUserInterface(newUserInterface);
	destroyUserInterface(newUserInterface);

	checkMemoryLeaks();
	return 0;
}