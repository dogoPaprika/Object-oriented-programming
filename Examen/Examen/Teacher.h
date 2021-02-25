#pragma once
#include <iostream>
#include <string>

using namespace std;

class Teacher {
private:
	string name;
public:
	Teacher(string name) : name{ name } {}
	string getName() { return name; }
	~Teacher() {}
};