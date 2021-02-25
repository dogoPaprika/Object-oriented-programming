#include "GUI.h"
#include <string>

//GUI::GUI(Repository& repo, QWidget *parent)
//	: repository(repo), QMainWindow(parent)
//{
//	ui.setupUi(this);
//	this->initRepo();
//}

GUI::GUI(Controller& repo, QWidget *parent)
	: controller(repo), QMainWindow(parent)
{
	ui.setupUi(this);
	this->initRepo();
}


void GUI::initRepo()
{
	this->ui.repoList->clear();

	for (auto b : this->controller.getAll())
	{
		std::string s1 = b.getDescription();
		std::string s2 = std::to_string(b.getStart());
		std::string s3 = std::to_string(b.getEnd());
		std::string s4 = std::to_string(b.getTemperature());
		std::string s5 = std::to_string(b.getPrecipitation());

		QString itemInList;
		itemInList = QString::fromStdString("Start: " + s2+ ", End: " + s3 + ", Temperature: " + s4 + "Precipitation:" + s5 + ", Description;" + s1);

		QListWidgetItem *item3 = new QListWidgetItem(itemInList);
		this->ui.repoList->addItem(item3);
	}
}

void GUI::initPrecipitation()
{
	this->ui.listPrecipitation->clear();

	for (auto b : this->controller.getAllPrecipitation())
	{
		std::string s1 = b.getDescription();
		std::string s2 = std::to_string(b.getStart());
		std::string s3 = std::to_string(b.getEnd());
		std::string s4 = std::to_string(b.getTemperature());
		std::string s5 = std::to_string(b.getPrecipitation());

		QString itemInList;
		itemInList = QString::fromStdString("Start: " + s2 + ", End: " + s3 + ", Temperature: " + s4 + "Precipitation:" + s5 + ", Description;" + s1);

		QListWidgetItem *item3 = new QListWidgetItem(itemInList);
		this->ui.listPrecipitation->addItem(item3);
	}
}
void GUI::filterCommand()
{
	std::string target = this->ui.precipitationLineEdit->text().toUtf8().constData();
	double prec = stod(target);
	this->controller.filterController(prec);
	this->initPrecipitation();
}

void GUI::hoursCommand()
{
	std::string target = this->ui.descriptionLineEdit->text().toUtf8().constData();
	int res = this->controller.sumHoursController(target);
	std::string s = "Result: " + std::to_string(res) + " hours";
	this->ui.calculateLabel->setText(QString::fromStdString(s));
}
