#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

class Shape {
protected:
	std::string name;
public:
	Shape(const std::string& _name) : name{ _name } {}
	Shape() {}
	
	virtual void draw() = 0;
	
	virtual ~Shape() =0 {};
};