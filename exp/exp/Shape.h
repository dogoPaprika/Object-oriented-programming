#pragma once
#include <string>

class Shape
{
protected:
	std::string name;

public:
	Shape(const std::string& n);
	virtual ~Shape();

	virtual void draw() = 0;
};

class Point
{
private:
	double x, y;

public:
	Point(double _x = 0, double _y = 0) : x{ _x }, y{ _y } {}
};

class Line : public Shape
{
private:
	Point x, y;

public:
	Line(const std::string& name, const Point& p1, const Point& p2);
	void draw() override;
};

class Circle : public Shape
{
private:
	Point center;
	double radius;

public:
	Circle(const std::string& name, const Point& c, double r);
	void draw() override;
};
