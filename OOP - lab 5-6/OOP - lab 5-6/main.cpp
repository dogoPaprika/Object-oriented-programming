#pragma once
#include "GraphicalUserInterface.h"
#include <QtWidgets/QApplication>
#include "_Controller.h"
#include "DecideMode.h"

void initiateRepositoryTest(Repository& repositoryInitiate);

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//Repository* repository = new CSVRepository{"movies.txt"};
	Repository* repository = new Repository;
	initiateRepositoryTest(*repository);
	WatchList* watchList = new WatchList;
	Controller controller{ repository, watchList, MovieValidator{} };

	//Administrator ad{ &controller };
	//ad.show();

	/*UserMode us{ &controller };
	us.show();*/

	DecideMode decideMode{ &controller, argc, argv };
	decideMode.show();

	//GraphicalUserInterface graphicalInterface{&controller};
	//graphicalInterface.show();
	return a.exec();
}

void initiateRepositoryTest(Repository& repositoryInitiate)
{
	Movie movie1("Brandersnatch", "thriller", 2018, 50000, "https://www.youtube.com/watch?v=XM0xWpBYlNM&t=34s");
	Movie movie2("Figh Club", "action", 2005, 45000, "https://www.youtube.com/watch?v=qtRKdVHc-cE");
	Movie movie3{ "Oblivion", "Sci-Fiction", 2014, 35000, "https://www.youtube.com/watch?v=XmIIgE7eSak" };
	Movie movie4{ "I origins", "mistery", 2015, 25000, "https://www.youtube.com/watch?v=Mk4briOLrTQ" };
	Movie movie5{ "The Illusionist", "romance", 2008, 23000, "https://www.youtube.com/watch?v=i0xO64icGSY" };
	Movie movie6{ "Transformers: Dark side of the Moon", "action", 2011, 40000, "https://www.youtube.com/watch?v=kHRf01Gjosk" };
	Movie movie7{ "Interstellar", "Sci-Fiction", 2016, 55000, "https://www.youtube.com/watch?v=2LqzF5WauAw" };
	Movie movie8{ "The Zookeeper`s wife", "drama", 2018, 33000, "https://www.youtube.com/watch?v=eiEfrA6MWs4" };
	Movie movie9{ "Project X", "comedy", 2015, 24000, "https://www.youtube.com/watch?v=3BEIhA8CcY0" };
	Movie movie10{ "The Hobbit2: Battle of five armies", "fantasy", 2015, 49000, "https://www.youtube.com/watch?v=iVAgTiBrrDA" };

	repositoryInitiate.addMovie(movie1);
	repositoryInitiate.addMovie(movie2);
	repositoryInitiate.addMovie(movie3);
	repositoryInitiate.addMovie(movie4);
	repositoryInitiate.addMovie(movie5);
	repositoryInitiate.addMovie(movie6);
	repositoryInitiate.addMovie(movie7);
	repositoryInitiate.addMovie(movie8);
	repositoryInitiate.addMovie(movie9);
	repositoryInitiate.addMovie(movie10);
}
