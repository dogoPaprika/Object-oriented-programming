#pragma once
#include <string> 

class Building
{
protected:
	std::string address;
	int constructionYear;

public:
	Building() {}
	Building(std::string _address, int _constructionYear) : address(_address), constructionYear(_constructionYear) {}
	virtual ~Building() {}

	virtual bool mustBeRestored() = 0;
	virtual bool canBeDemolished() = 0;
	virtual std::string toString();
};