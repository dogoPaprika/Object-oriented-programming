#include "Student.h"
#include <vector>
#include <sstream>
#include <string>

vector<string> tokenize(string s, char del)
{
	stringstream ss(s);
	string aux;
	vector<string> res;
	while (getline(ss, aux, del))
		res.push_back(aux);
	return res;
}

istream& operator>>(istream& is, Student& x)
{
	string s;
	getline(is, s);

	vector<string> rez = tokenize(s, ',');
	

	x.setId(rez[0]);
	x.setName(rez[1]);
	x.setEmail(rez[2]);
	x.setYear(stoi(rez[3]));

	if (rez.size() == 6)
	{
		x.setTitle(rez[4]);
		x.setCoordinator(rez[5]);
	}
	else
	{
		x.setTitle("No title");
		x.setCoordinator("");
	}

	return is;
}