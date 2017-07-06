#pragma once

#ifndef __NODE_H__
#define __NODE_H__

#include "Line.h"

class Node : public Line {
public:
	Node(char* content = "")
		: Line(content), next(nullptr) { }

	Node*	getNext() { return next; }
	void	setNext(Node* next) { this->next = next; }
	void	insertNext(Node* item);
	Node*	removeNext();
private:
	Node*	next;
};

//Feature : to insert item into next node
void Node::insertNext(Node * item)
{
	if (item)
		item->next = next;
	
	next = item;
}

//Feature : to remove next node
//Return : if next node is null pointer, return nullptr
Node * Node::removeNext()
{
	if (!next)
		return nullptr;
	
	Node* nextItem = next;
	next = next->getNext();

	return nextItem;
}
#endif