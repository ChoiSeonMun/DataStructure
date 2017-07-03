#pragma once

#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <cstring>
#include <cstdio>

constexpr unsigned MAX_NAME_SIZE = 20;
constexpr unsigned MAX_DEPT_SIZE = 20;

class Student {
public:
	Student(int ID, char* NAME, char* DEPT);

	void 	set(int ID, char* NAME, char* DEPT);
	void 	display();
private:
	int		id;
	char	name[MAX_NAME_SIZE];
	char	dept[MAX_DEPT_SIZE];
};

Student::Student(int ID, char* NAME, char* DEPT)
	: id(ID)
{
	strcpy_s(name, MAX_NAME_SIZE, NAME);
	strcpy_s(dept, MAX_DEPT_SIZE, DEPT);
}

void Student::set(int ID, char* NAME, char* DEPT)
{
	strcpy_s(name, MAX_NAME_SIZE, NAME);
	strcpy_s(dept, MAX_DEPT_SIZE, DEPT);
	id = ID;
}

void Student::display()
{
	printf("ID : %d, Name : %s, Dept : %s\n", id, name, dept);
}
#endif
