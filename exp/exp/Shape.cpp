#include "Shape.h"
#include <iostream>

using namespace std;

Shape::Shape(const std::string& n) : name{ n }
{
}


Shape::~Shape()
{
}

Line::Line(const std::string & name, const Point & p1, const Point & p2) :
	Shape{ name }, x{ p1 }, y{ p2 }
{
}

void Line::draw()
{
	cout << "Drawing line: " << this->name << endl;
}

Circle::Circle(const std::string & name, const Point & c, double r) :
	Shape{ name }, center{ c }, radius{ r }
{
}

void Circle::draw()
{
	cout << "Drawing circle: " << this->name << endl;
}

