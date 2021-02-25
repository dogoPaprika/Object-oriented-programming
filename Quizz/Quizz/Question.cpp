#include "Question.h"

vector<string> tokenize(string s, char del)
{
	stringstream ss(s);
	string aux;
	vector<string> res;
	while (getline(ss, aux, del))
		res.push_back(aux);
	return res;
}

istream& operator>>(istream& is, Question& x)
{
	string s;
	getline(is, s);

	vector<string> rez = tokenize(s, ',');
	if (rez.size() != 4)
		return is;

		x.setId(stoi(rez[0]));
		x.setQuestion(rez[1]);
		x.setAnswer(rez[2]);
		x.setScore(stoi(rez[3]));

	return is;
}