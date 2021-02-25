#pragma once
#include "Shape.h"
#include "Point.h"

using namespace std;

class Circle : public Shape {
private:
	Point center;
	double radius;
public:
	Circle(std::string _name, Point _center, double _radius) : Shape{_name},center { _center }, radius{ _radius } {}
	Circle(double x, double y, double _radius) : center{ Point{x , y} }, radius{ _radius } {}

	void draw() override
	{
		cout << "Drawing circle: " << this->name << endl;
	}

	~Circle() {}
};
