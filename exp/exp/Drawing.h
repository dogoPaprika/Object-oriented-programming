#pragma once
#include "Shape.h"
#include <vector>

class Drawing : public Shape
{
private:
	std::vector<Shape*> shapes;

public:
	Drawing(const std::string& name);
	~Drawing();

	void draw() override;
	void add(Shape* s);
};

