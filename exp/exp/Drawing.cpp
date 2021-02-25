#include "Drawing.h"
#include <iostream>

Drawing::Drawing(const std::string& name) : Shape{ name }
{
}

Drawing::~Drawing()
{
	for (Shape* shape : this->shapes)
		delete shape;
}

void Drawing::draw()
{
	std::cout << "Drawing shape: " << this->name << std::endl;

	for (auto s : this->shapes)
		s->draw();
}

void Drawing::add(Shape * s)
{
	this->shapes.push_back(s);
}
