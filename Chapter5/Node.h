#pragma once

#ifndef __NODE_H__
#define __NODE_H__

#include "Location2D.h"

class Node : public Location2D {
public:
	Node(int row = 0, int col = 0)
		: Location2D(row, col) { }
	Node*	getLink() { return link; }
	void	setLink(Node* next) { link = next; }
private:
	Node*	link = nullptr;
};

#endif