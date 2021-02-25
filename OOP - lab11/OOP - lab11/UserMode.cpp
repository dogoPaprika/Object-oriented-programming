#include "UserMode.h"

UserMode::UserMode(Controller* controller, QWidget *parent)
	: controller{ controller }, QWidget(parent)
{
	ui.setupUi(this);
	this->initiateWatchList();
}

UserMode::~UserMode()
{
}

int UserMode::getSelectedIndex(const QListWidget* l)
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

void UserMode::initiateWatchList()
{
	this->ui.watchList->clear();

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
		this->ui.watchList->addItem(item);
	}
}

void UserMode::saveMovie()
{
	try
	{
		Movie movie;
		if (!ui.saveLineEdit->text().isEmpty())
		{
			std::string title = ui.saveLineEdit->text().toStdString();
			movie.setTitle(title); movie.setGenre("empty"); movie.setYear(0); movie.setLikes(0); movie.setTrailer("a");
			this->controller->findMovieByTitle(movie);
			if (movie.getGenre() == "empty")
				throw InexistentMovieException();
		}
		else
		{
			int index = this->getSelectedIndex(this->ui.filterList);
			if (index != -1)
				movie = this->controller->getMovies()[index];
			else
				throw 1;
		}	

		this->controller->addMovieWatchList(movie);
		this->initiateWatchList();
	}
	catch (InexistentMovieException& inexistentException)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "This element does not exist!");
	}
}

void UserMode::playTrailer()
{
	try
	{
		Movie movie;
		int index = this->getSelectedIndex(this->ui.watchList);
		if (index == -1)
			throw 1;
		movie = this->controller->getWatchList()[index];
		QString link = QString::fromStdString(movie.getTrailer());
		QDesktopServices::openUrl(QUrl(link));
	}
	catch (InexistentMovieException& inexistentException)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "This element does not exist!");
	}
}

void UserMode::nextMovie()
{
	if (this->position >= this->ui.filterList->count())
		this->position = 0;

	QListWidgetItem* item = ui.filterList->item(this->position);

	this->position++;
	QMessageBox messagebox;
	messagebox.setText(item->text());
	messagebox.exec();
}

void UserMode::filterRepository()
{
	try
	{
		if (ui.genreLineEdit->text().isEmpty() || ui.likesLineEdit->text().isEmpty())
			throw 1;

		//if it cannot convert, it throws automatically
		std::string genre = this->ui.genreLineEdit->text().toStdString();
		int likes = stoi(this->ui.likesLineEdit->text().toStdString());

		this->position = 0;
		this->filterRepositoryByGenre(genre, likes);
	}
	catch (...)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "Empty fields or cannot convert!");
	}
}

void UserMode::initiate()
{
	this->ui.filterList->clear();

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
		this->ui.filterList->addItem(item);
	}
	this->position = 0;
}

void UserMode::filterRepositoryByGenre(std::string genre, int like)
{
	this->ui.filterList->clear();

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
			this->ui.filterList->addItem(item);
	}
}
