#pragma once

#ifndef __NODE2_H__
#define __NODE2_H__

#include <cstdio>

class Node2 {
public:
	Node2(int val = 0)
		: prev(nullptr), next(nullptr), data(val) { }
	
	Node2*	getPrev() { return prev; }
	Node2*	getNext() { return next; }
	Node2*	remove();
	void	setPrev(Node2* prev) { this->prev = prev; }
	void	setNext(Node2* next) { this->next = next; }
	void	display() { printf(" <%2d>", data); }
	void	insertNext(Node2* node);
	bool	hasData(int val) { return data == val; }
private:
	Node2*	prev;
	Node2*	next;
	int		data;
};

//Feature : to remove this node from the list
//Return : this node
Node2 * Node2::remove()
{
	if (prev) { prev->setNext(next); }
	if (next) { next->setPrev(prev); }

	return this;
}

//Feature : if the node is valid, to insert that into next
void Node2::insertNext(Node2 * node)
{
	if (node)
	{
		node->setPrev(this);
		node->setNext(next);
		if (next)
			next->setPrev(node);
		setNext(node);
	}
}
#endif