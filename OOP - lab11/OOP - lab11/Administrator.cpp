#include "Administrator.h"

Administrator::Administrator(Controller* controller, QWidget *parent)
	: controller{ controller }, QWidget(parent)
{
	ui.setupUi(this);
	this->initiateRepository();
}

Administrator::~Administrator()
{
}

void Administrator::initiateRepository()
{
	this->ui.listMovies->clear();

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
		this->ui.listMovies->addItem(item);
	}
}

int Administrator::getSelectedIndex(const QListWidget* l)
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

void Administrator::addMovie()
{
	try
	{
		if (ui.titleLineEdit->text().isEmpty() || ui.genreLineEdit->text().isEmpty() || ui.yearLineEdit->text().isEmpty() || ui.likesLineEdit->text().isEmpty() || ui.trailerLineEdit->text().isEmpty())
			throw 1;

		//if it cannot convert, it throws automatically
		std::string title = ui.titleLineEdit->text().toStdString();
		std::string genre = ui.genreLineEdit->text().toStdString();
		int year = stoi(ui.yearLineEdit->text().toStdString());
		int likes = stoi(ui.likesLineEdit->text().toStdString());
		std::string trailer = ui.trailerLineEdit->text().toStdString();

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

void Administrator::deleteMovie()
{
	try
	{
		int index = this->getSelectedIndex(this->ui.listMovies);
		if (index == -1)
			throw 1;
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

void Administrator::updateMovie()
{
	try
	{
		if (ui.titleLineEdit->text().isEmpty() || ui.genreLineEdit->text().isEmpty() || ui.yearLineEdit->text().isEmpty() || ui.likesLineEdit->text().isEmpty() || ui.trailerLineEdit->text().isEmpty())
			throw 1;

		//read old object
		int index = this->getSelectedIndex(this->ui.listMovies);
		Movie movie = this->controller->getMovies()[index];
		std::string oldTitle = movie.getTitle();

		//read new fields, if it cannot convert, it throws automatically
		//std::string s1 = this->titleTextBox->text().toStdString();	
		std::string genre = ui.genreLineEdit->text().toStdString();
		int year = stoi(ui.yearLineEdit->text().toStdString());
		int likes = stoi(ui.likesLineEdit->text().toStdString());
		std::string trailer = ui.trailerLineEdit->text().toStdString();

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