#pragma once
#include "Shape.h"
#include <vector>

using namespace std;

class Drawing : public Shape {
private:
	vector<Shape*> shapes;
public:
	Drawing(string _name) : Shape{ _name } {}

	void draw() override
	{
		std::cout << "Drawing shape: " << this->name << std::endl;

		for (auto s : this->shapes)
			s->draw();
	}

	void add(Shape* s)
	{
		this->shapes.push_back(s);
	}

	~Drawing() 
	{
		for (Shape* shape : this->shapes)
			delete shape;
	}
};