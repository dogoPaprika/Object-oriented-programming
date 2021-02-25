#pragma once
#include <string>

using namespace std;

class Student {
private:
	string id="";
	string name="";
	string email="";
	int year=0;
	string title="";
	string coordinator="";
public:
	Student() {}
	Student(string id, string n, string e, int year, string title, string coord) : id{ id }, name{ n }, email{ e }, year{ year }, title{ title }, coordinator{ coord }{}
	~Student() {}
	void setId(string s) { id = s; }
	void setName(string s) { name = s; }
	void setEmail(string s) { email = s; }
	void setTitle(string s) { title = s; }
	void setCoordinator(string s) { coordinator = s; }
	void setYear(int y) { year = y; }
	friend istream& operator>>(istream& is, Student& b);
	
	int getYear() { return year; }
	string getCoordinator() { return coordinator; }
	string getTitle() { return title; }
	string getName() { return name; }
	string getEmail() { return email; }
	string getId() { return id; }

	bool operator==(Student std)
	{
		return ((std.getCoordinator() == coordinator) && (std.getEmail() == email) && (std.getId() == id) && (std.getName() == name) &&
			(std.getTitle() == title) && (std.getYear() == year));
	}
};