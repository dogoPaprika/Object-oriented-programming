#pragma once
#pragma once
#include "Repository.h"
#include <vector>
#include <algorithm>
#include <assert.h>

class Controller {
private:
	Repository &repo;
public:
	Controller(Repository& repo) : repo{ repo } {  };
	int getSizeTeachers() { return this->repo.getSizeTeachers(); }
	std::vector<Teacher> getTeachers() { return this->repo.getTeachers(); }
	std::vector<Student> getStudents() { return this->repo.getStudents(); }
	std::vector<Student> getSortedStudents() { return this->repo.getSortedStudents(); }
	bool haveCoordinator(int pos)
	{
		return repo.haveCoord(pos);
	}
	//descr: this function adds a coordinator to a student
	//In: string - name of coordinator, int - position where the student is in the list
	//Out: -
	void setCoordinatorStudent(string name, int pos)
	{
		repo.setCoord(name, pos);
	}
	void testAddCoordinatorStudent()
	{
		Repository repo;
		Controller controller{ repo };

		controller.setCoordinatorStudent("Rapunzel", 4);
		assert(repo.getStudents()[4].getCoordinator() == "Rapunzel");
	}

	//descr: searches for a stutedn based on their name or id
	//In: string - name/id
	//Out: Student - the found Stundet if found
	//		Student - a Student with empty fiels if not found
	Student searchByIdByName(string s)
	{
		return repo.searchByIdByName(s);
	}
	void testSearch()
	{
		Repository repo;
		Controller ctrl{ repo };
		string name{ "Mihai" };

		Student a{ "fgf", "Mihai" , "email43",2004, "No title", "" };

		assert(ctrl.searchByIdByName(name) == a);
		Student c{};
		assert(ctrl.searchByIdByName("Eusebiu") == c);

		Student b{ "ghg","Vlad","email45",2019,"Teza","Gabi" };
		assert(ctrl.searchByIdByName("ghg") == b);
	}
	~Controller() {};
};