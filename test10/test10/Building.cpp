#include "Building.h"

using namespace std;

string Building::toString()
{
	string res;
	res += " Address: " + this->address;
	res += " Construction Year: " + to_string(this->constructionYear);
	return res;
}