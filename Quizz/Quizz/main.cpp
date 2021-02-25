#include "Quizz.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{};
	Controller ctrl{ repo };
	Quizz w{ctrl};
	return a.exec();
}
