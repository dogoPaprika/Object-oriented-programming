#include "Test.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	/*Lecture9_demo_Qt_designer w;
	w.show();*/

	ProgramaticallyDesignedWidget w;
	w.show();

	return a.exec();
}
