#include "GUI.h"
#include <QtWidgets/QApplication>
#include "Repository.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo;
	Controller controller{ repo };
	GUI w{ controller };
	w.show();
	return a.exec();
}
