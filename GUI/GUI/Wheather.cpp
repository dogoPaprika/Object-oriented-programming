#include "Wheather.h"
using namespace std;

Wheather::Wheather()
{
	this->description = "";
	this->start = 0;
	this->end = 0;
	this->precipitation = 0.0;
	this->temperature = 0.0;
}

vector<string> tokenize(string s, char del)
{
	stringstream ss(s);
	string aux;
	vector<string> res;
	while (getline(ss, aux, del))
		res.push_back(aux);
	return res;
}

istream& operator>>(istream& is, Wheather& x)
{
	std::string s;
	getline(is, s);

	vector<string> rez = tokenize(s, ';');
	if (rez.size() != 5)
		return is;

	x.setStart(stoi(rez[0]));
	x.setEnd(stoi(rez[1]));
	x.setTemperature(stod(rez[2]));
	x.setPrecipitation(stod(rez[3]));
	x.setDescription(rez[4]);
	return is;
}
