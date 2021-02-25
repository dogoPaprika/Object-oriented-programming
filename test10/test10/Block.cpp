#pragma once
#include "Block.h"
#include <string.h>
#include <iostream>

std::string Block::toString()
{
	std::string res = Building::toString();
	res += ", total apartments: " + std::to_string(this->totalApartments);
	res += ", occupied apartments: " + std::to_string(this->occupiedApartments);
	return res;
}

bool Block::mustBeRestored()
{
	if ((2019 - this->constructionYear > 40) && ((double)occupiedApartments > (double)totalApartments / 100 * 80))
		return true;
	else
		return false;
}

bool Block::canBeDemolished()
{
	if ((double)occupiedApartments < (double)totalApartments / 100 * 5)
		return true;
	else
		return false;
}
