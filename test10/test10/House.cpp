#pragma once
#include "House.h"
#include <string.h>

std::string House::toString()
{
	std::string res = Building::toString();
	res += ", type: " + this->type;
	res += ", is historical: " + std::to_string(this->isHistorical);
	return res;
}

bool House::mustBeRestored()
{
	if (2019 - this->constructionYear > 100)
		return true;
	else
		return false;
}

bool House::canBeDemolished()
{
	if (this->isHistorical)
		return false;
	else
		return true;
}

