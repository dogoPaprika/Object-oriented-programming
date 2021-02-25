#include "UserInterface.h"
#include <windows.h>
using namespace std;

void init(Controller& ctrl)
{
	Building* b1 = new House{ "address1", 2000, "fancy", 1 };
	Building* b3 = new House{ "address3", 1900, "modern", 0 };
	Building* b2 = new Block{ "address2", 2001, 50, 45 };
	Building* b4 = new Block{ "address4", 1970, 50, 1 };

	ctrl.addBuilding(b1);
	ctrl.addBuilding(b2);
	ctrl.addBuilding(b3);
	ctrl.addBuilding(b4);
}

int main()
{
	Controller ctrl;
	init(ctrl);
	UserInterface ui{ ctrl };

	ui.run();


	system("pause");
	return 0;
}