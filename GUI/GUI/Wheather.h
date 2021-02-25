#pragma once
#include <string>
#include <vector>
#include <sstream>

class Wheather
{
private:
	std::string description;
	double temperature;
	double precipitation;
	int start;
	int end;

public:
	Wheather();
	Wheather(std::string desc, double prec, double temp, int start, int end) : description(desc), precipitation(prec), temperature(temp), start(start), end(end) {}

	double getTemperature() const { return this->temperature; }
	double getPrecipitation() const { return this->precipitation; }
	int getStart() const { return this->start; }
	int getEnd() const { return this->end; }
	std::string getDescription() const { return this->description; }

	void setDescription(std::string v) { this->description = v; }
	void setStart(int v) { this->start = v; }
	void setEnd(int v) { this->end = v; }
	void setTemperature(double v) { this->temperature = v; }
	void setPrecipitation(double v) { this->precipitation = v; }

	friend std::istream& operator>>(std::istream& is, Wheather& b);
};


