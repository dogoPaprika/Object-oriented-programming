#include "Examen.h"
#include <QtWidgets/QApplication>
#include "Controller.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{};
	Controller ctrl{ repo };
	ctrl.testAddCoordinatorStudent();
	ctrl.testSearch();
	Examen w{ ctrl };
	return a.exec();
}
