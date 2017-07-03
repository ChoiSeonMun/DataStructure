#pragma once

#ifndef __NODE_H__
#define __NODE_H__

#include "Student.h"

class Node : public Student {
public:
	Node(int id = 0, char* name = "", char* dept = "")
		: Student(id, name, dept) { }
	Node*	getLink() { return link; }
	void	setLink(Node* next) { link = next; }
private:
	Node*	link = nullptr;
};

#endif