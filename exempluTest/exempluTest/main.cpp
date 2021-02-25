#include "Circle.h"
#include "Line.h"
#include "Drawing.h"
#include <crtdbg.h>

void drawShapes()
{
	Shape* circle = new Circle{ "circle1", Point{ 0, 0 }, 1 };
	Shape* line = new Line{ "line", Point{ 0, 0 }, Point{ 1, 1 } };
	Drawing* drawing1 = new Drawing{ "drawing1" };
	drawing1->add(line);
	drawing1->add(circle);

	Drawing* drawing2 = new Drawing{ "drawing2" };
	drawing2->add(new Circle{ "circle2", Point{ 3, 4 }, 10 });
	drawing2->add(drawing1);

	drawing2->draw();

	delete drawing2; // deleting this will delete all its components
}

int main()
{
	drawShapes();

	if (_CrtDumpMemoryLeaks())
		cout << "Memory leaks" << endl;
	else
		cout << "No memory leaks" << endl;

	system("pause");
	return 0;
}