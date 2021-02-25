#pragma once
#include "Building.h"


class Block : public Building
{
private:
	int totalApartments;
	int occupiedApartments;

public:
	Block() {}
	Block(std::string _address, int _constructionYear, int totalApartments, int occupiedApartments) : Building{ _address, _constructionYear }, totalApartments(totalApartments), occupiedApartments(occupiedApartments) {}
	bool mustBeRestored() override;
	bool canBeDemolished() override;
	std::string toString() override;
};


