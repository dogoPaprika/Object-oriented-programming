#include "GraphicalUserInterface.h"

GraphicalUserInterface::GraphicalUserInterface(Controller* controller, QWidget *parent)
	: controller{ controller }, QWidget{ parent }
{
	//ui.setupUi(this);
	
	this->chooseMode();
	this->chooseRepository();
	this->setSignals();
}

void GraphicalUserInterface::chooseMode()
{
	QVBoxLayout* mainLayout = new QVBoxLayout{ this };
	QLabel* labelMovies = new QLabel{ "Please choose a mode" };
	mainLayout->addWidget(labelMovies);

	QGridLayout* buttonsLayout = new QGridLayout{};
	this->userButton = new QPushButton{ "User Mode" };
	this->adminButton = new QPushButton{ "Administrator Mode" };
	buttonsLayout->addWidget(this->userButton, 0, 0);
	buttonsLayout->addWidget(this->adminButton, 0, 1);

	mainLayout->addLayout(buttonsLayout);
}

void GraphicalUserInterface::goToAdmin()
{
	
	this->initiateGraphicalUserInterfaceAdmin();
	this->initiateRepository();
}

void GraphicalUserInterface::goToUser()
{
	this->initiateGraphicalUserInterfaceUser();
	this->initiateWatchList();
}

void GraphicalUserInterface::initiateGraphicalUserInterfaceUser()
{

	//General layout of the window
	QHBoxLayout* mainLayout = new QHBoxLayout{ this };

	//this->saveButton = new QPushButton{ ">" };
	mainLayout->addWidget(saveButton);

	////////////////////// User Vertical Layout - right

	QVBoxLayout* userLayout = new QVBoxLayout{};
	QLabel* labelWatchList = new QLabel{ "WatchList" };
	userLayout->addWidget(labelWatchList);


	watchList = new QListWidget{};
	watchList->setSelectionMode(QAbstractItemView::SingleSelection); 	// Set the selection model
	//repoList->setMinimumWidth(500);
	watchList->setGeometry(10, 10, 10, 10);

	labelWatchList->setBuddy(watchList);

	userLayout->addWidget(watchList);

	//Buttons - creation
	QGridLayout* buttonsUserLayout = new QGridLayout{};
	//this->playButton = new QPushButton{ "Play" };
	//this->nextButton = new QPushButton{ "Next" };
	buttonsUserLayout->addWidget(this->playButton, 0, 0);
	buttonsUserLayout->addWidget(this->nextButton, 0, 1);


	userLayout->addLayout(buttonsUserLayout);

	QWidget* userWindow = new QWidget;
	userWindow->setLayout(userLayout);

	mainLayout->addWidget(userWindow);
}

void GraphicalUserInterface::initiateGraphicalUserInterfaceAdmin()
{

	//General layout of the window
	QHBoxLayout* mainLayout = new QHBoxLayout{ this };

	//Names for lists
	QVBoxLayout* administratorLayout = new QVBoxLayout{};
	QLabel* labelMovies = new QLabel{ "Movies" };
	administratorLayout->addWidget(labelMovies);


	repositoryList = new QListWidget{};	 // Left side - just the list
	repositoryList->setSelectionMode(QAbstractItemView::SingleSelection); 	// Set the selection model
	repositoryList->setMinimumWidth(500);
	repositoryList->setMinimumHeight(200);
	repositoryList->setGeometry(30, 10, 10, 10);

	labelMovies->setBuddy(repositoryList);

	administratorLayout->addWidget(repositoryList);

	//Middle part - Line edits where data is inputed
	QFormLayout* middleLayout = new QFormLayout{};
	titleTextBox = new QLineEdit{};
	genreTextBox = new QLineEdit{};
	yearTextBox = new QLineEdit{};
	likesTextBox = new QLineEdit{};
	trailerTextBox = new QLineEdit{};
	middleLayout->addRow("Title: ", titleTextBox);
	middleLayout->addRow("Genre: ", genreTextBox);
	middleLayout->addRow("Year: ", yearTextBox);
	middleLayout->addRow("Likes: ", likesTextBox);
	middleLayout->addRow("Trailer: ", trailerTextBox);

	administratorLayout->addLayout(middleLayout);

	//Buttons - creation
	QGridLayout* buttonsLayout = new QGridLayout{};
	//this->addButton = new QPushButton{ "Add" };
	//this->deleteButton = new QPushButton{ "Delete" };
	//this->updateButton = new QPushButton{ "Update" };
	//this->filterButton = new QPushButton{ "Filter" };
	//this->initialButton = new QPushButton{ "Initial Repository" };
	buttonsLayout->addWidget(this->addButton, 0, 0);
	buttonsLayout->addWidget(this->deleteButton, 0, 1);
	buttonsLayout->addWidget(this->updateButton, 0, 2);

	administratorLayout->addLayout(buttonsLayout);

	QWidget* adminWindow = new QWidget;
	adminWindow->setLayout(administratorLayout);

	mainLayout->addWidget(adminWindow);
	
}

void GraphicalUserInterface::initiateRepository()
{
	this->repositoryList->clear();

	int length = this->controller->getSizeController();
	//Iterate repository
	for (int i = 0; i < length; i++)
	{
		Movie movie = this->controller->getMovies()[i];
		std::string title = movie.getTitle();
		std::string genre = movie.getGenre();
		std::string year = std::to_string(movie.getYear());
		std::string likes = std::to_string(movie.getLikes());
		std::string trailer = movie.getTrailer();

		QString itemInList = QString::fromStdString("Ttile: " + title + ", Genre: " + genre + ", Year: " + year + ", Likes: " + likes + ", Trailer: " + trailer);
		QListWidgetItem *item = new QListWidgetItem(itemInList);
		this->repositoryList->addItem(item);
	}
}

void GraphicalUserInterface::initiate()
{
	this->initiateRepository();
}

void GraphicalUserInterface::initiateWatchList()
{
	this->watchList->clear();

	int length = this->controller->getSizeWatchList();
	//Iterate 
	for (int i = 0; i < length; i++)
	{
		Movie movie = this->controller->getWatchList()[i];
		std::string title = movie.getTitle();
		std::string genre = movie.getGenre();
		std::string year = std::to_string(movie.getYear());
		std::string likes = std::to_string(movie.getLikes());
		std::string trailer = movie.getTrailer();

		QString itemInList = QString::fromStdString("Title: " + title + ", genre: " + genre + ", year: " + year + ", likes: " + likes + ", trailer: " + trailer);
		QListWidgetItem *item = new QListWidgetItem(itemInList);
		this->watchList->addItem(item);
	}
}

void GraphicalUserInterface::setSignals()
{
	//Buttons clicked signals
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addMovie()));
	QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deleteMovie()));
	QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateMovie()));
	QObject::connect(this->filterButton, SIGNAL(clicked()), this, SLOT(filterRepository()));
	QObject::connect(this->saveButton, SIGNAL(clicked()), this, SLOT(saveMovie()));
	QObject::connect(this->initialButton, SIGNAL(clicked()), this, SLOT(initiate()));
	QObject::connect(this->playButton, SIGNAL(clicked()), this, SLOT(playTrailer()));
	QObject::connect(this->nextButton, SIGNAL(clicked()), this, SLOT(nextMovie()));
	QObject::connect(this->userButton, SIGNAL(clicked()), this, SLOT(goToUser()));
	QObject::connect(this->adminButton, SIGNAL(clicked()), this, SLOT(goToAdmin()));
}

int GraphicalUserInterface::getSelectedIndex(const QListWidget* l)
{
	//if the list is empty
	if (l->count() == 0)
		return -1;

	QModelIndexList index = l->selectionModel()->selectedIndexes();
	if (index.size() == 0) //if no index was selected
		return -1;

	int idx = index.at(0).row();
	return idx;
}

void GraphicalUserInterface::addMovie()
{
	try
	{
		if (titleTextBox->text().isEmpty() || genreTextBox->text().isEmpty() || yearTextBox->text().isEmpty() || likesTextBox->text().isEmpty() || trailerTextBox->text().isEmpty())
			throw 1;

		//if it cannot convert, it throws automatically
		std::string title = this->titleTextBox->text().toStdString();	
		std::string genre = this->genreTextBox->text().toStdString();		
		int year = stoi(this->yearTextBox->text().toStdString());	
		int likes = stoi(this->likesTextBox->text().toStdString());	
		std::string trailer = this->trailerTextBox->text().toStdString();

		this->controller->addMovie(title, genre, year, likes, trailer);
		this->initiateRepository();
	}
	catch (MovieException& movieException)
	{
		QMessageBox messageBox;
		std::string allErrors = "";

		for (auto error : movieException.getErrors())
			allErrors += error;

		messageBox.critical(0, "Error", QString::fromStdString(allErrors));
	}
	catch (DuplicateMovieException& duplicateException)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "This element already exists!");
	}
	catch (...)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Empty fields or cannot convert!");
	}
}

void GraphicalUserInterface::deleteMovie()
{
	try
	{
		int index = this->getSelectedIndex(this->repositoryList);
		Movie movie = this->controller->getMovies()[index];
		std::string title = movie.getTitle();

		this->controller->deleteMovie(title);
		this->initiateRepository();
	}
	catch (InexistentMovieException& inexistentException)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "This element does not exist!");
	}
	catch (...)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Empty fields or cannot convert!");
	}
}

void GraphicalUserInterface::updateMovie()
{
	try
	{
		if (titleTextBox->text().isEmpty() || genreTextBox->text().isEmpty() || yearTextBox->text().isEmpty() || likesTextBox->text().isEmpty() || trailerTextBox->text().isEmpty())
			throw 1;

		//read old object
		int index = this->getSelectedIndex(this->repositoryList);
		Movie movie = this->controller->getMovies()[index];
		std::string oldTitle = movie.getTitle();

		//read new fields, if it cannot convert, it throws automatically
		//std::string s1 = this->titleTextBox->text().toStdString();	
		std::string genre = this->genreTextBox->text().toStdString();		
		int year = stoi(this->yearTextBox->text().toStdString());	
		int likes = stoi(this->likesTextBox->text().toStdString());	
		std::string trailer = this->trailerTextBox->text().toStdString(); 

		this->controller->updateMovie(oldTitle, genre, year, likes, trailer);
		this->initiateRepository();
	}
	catch (InexistentMovieException& inexistentException)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "This element does not exist!");
	}
	catch (DuplicateMovieException& duplicateException)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "This element already exists!");
	}
	catch (MovieException& movieException)
	{
		QMessageBox messageBox;
		std::string allErrors = "";

		for (auto error : movieException.getErrors())
			allErrors += error;

		messageBox.critical(0, "Error", QString::fromStdString(allErrors));
	}
	catch (...)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Empty fields or cannot convert!");
	}
}
void GraphicalUserInterface::saveMovie()
{
	try
	{
		int index = this->getSelectedIndex(this->repositoryList);
		Movie movie = this->controller->getMovies()[index];

		this->controller->addMovieWatchList(movie);
		this->initiateWatchList();
	}
	catch (InexistentMovieException& inexistentException)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "This element does not exist!");
	}
}

void GraphicalUserInterface::playTrailer()
{
	try
	{
		int index = this->getSelectedIndex(this->repositoryList);
		Movie movie = this->controller->getMovies()[index];
		QString link = QString::fromStdString(movie.getTrailer());
		QDesktopServices::openUrl(QUrl(link));
	}
	catch (InexistentMovieException& inexistentException)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "This element does not exist!");
	}
}

void GraphicalUserInterface::nextMovie()
{
	Movie movie = this->controller->getMovie(this->position);
	this->position++;
	QMessageBox messageBox;
	messageBox.setText(QString::fromStdString(movie.toString()));
	messageBox.exec();
	if (this->position == this->controller->getSizeController())
		this->position = 0;
}

void GraphicalUserInterface::filterRepository()
{
	try
	{
		if (genreTextBox->text().isEmpty() || likesTextBox->text().isEmpty())
			throw 1;

		//if it cannot convert, it throws automatically
		std::string genre = this->genreTextBox->text().toStdString(); 
		int likes = stoi(this->likesTextBox->text().toStdString());	   

		this->filterRepositoryByGenre(genre, likes);
	}
	catch (...)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Empty fields or cannot convert!");
	}
}

void GraphicalUserInterface::filterRepositoryByGenre(std::string genre, int like)
{
	this->repositoryList->clear();

	int length = this->controller->getSizeController();
	//Iterate repository
	for (int i = 0; i < length; i++)
	{
		Movie movie = this->controller->getMovies()[i];
		std::string title = movie.getTitle();
		std::string gen = movie.getGenre();
		std::string year = std::to_string(movie.getYear());
		std::string likes = std::to_string(movie.getLikes());
		std::string trailer = movie.getTrailer();

		QString itemInList = QString::fromStdString("Ttile: " + title + ", Genre: " + gen + ", Year: " + year + ", Likes: " + likes + ", Trailer: " + trailer);
		QListWidgetItem *item = new QListWidgetItem(itemInList);
		if ((movie.getGenre() == genre) && (movie.getLikes() > like))
			this->repositoryList->addItem(item);
	}
}