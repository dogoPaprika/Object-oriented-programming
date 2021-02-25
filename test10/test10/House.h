
#pragma once
#include "Building.h"


class House : public Building
{
private:
	std::string type;
	bool isHistorical;

public:
	House() {};
	House(std::string _address, int _constructionYear, std::string type, bool isHistorical) : Building{ _address, _constructionYear }, type(type), isHistorical(isHistorical) {}
	bool mustBeRestored() override;
	bool canBeDemolished() override;
	std::string toString() override;
};


