#pragma once
#include "Shape.h"
#include "Point.h"

using namespace std;

class Line : public Shape {
private:
	Point p1;
	Point p2;
public:
	Line(std::string _name, Point _p1, Point _p2) : Shape{ _name }, p1 { _p1 }, p2{ _p2 } { }

	void draw() override
	{
		cout << "Drawing line: " << this->name << endl;
	}

	~Line() {}
};
