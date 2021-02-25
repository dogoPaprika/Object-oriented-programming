#pragma once
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <fstream>
#include <sstream>

class Repository {
private:
	vector<Student> students;
	vector<Teacher> teachers;
public:
	Repository() 
	{ 
		this->readStudentsFile(); 
		this->readTeachersFile(); 
	}
	void addStudent(Student s)
	{
		students.push_back(s);
	}
	void addTeacher(Teacher t)
	{
		teachers.push_back(t);
	}
	int getSizeTeachers() { return teachers.size(); }
	int getSizeStudents() { return students.size(); }
	vector<Teacher> getTeachers() { return teachers; }
	vector<Student> getStudents() { return students; }
	vector<Student> getSortedStudents() {
		for (int i = 0; i < students.size()-1;i++)
			for (int j = i+1; j < students.size();j++)
				if (students[i].getYear() < students[j].getYear())
				{
					Student aux = students[i];
					students[i] = students[j];
					students[j] = aux;
				}
		return students;
	}
	bool haveCoord(int pos)
	{
		if (students[pos].getCoordinator() == "")
			return false;
		return true;
	}
	void setCoord(string name, int pos)
	{
		students[pos].setCoordinator(name);
	}
	void readTeachersFile()
	{
		string name;
		std::ifstream f("teachers.txt");
		while (f >> name)
			teachers.push_back(Teacher{ name });
	}
	Student searchByIdByName(string s)
	{
		for (auto i : students)
			if ((i.getName() == s) || (i.getId() == s))
				return i;
		Student x{};
		return x;
	}
	void readStudentsFile()
	{
		Student s{};
		std::ifstream f("Students.txt");
		while (f >> s)
		{
			students.push_back(s);
			if (f.eof())
				break;
		}
	}
};