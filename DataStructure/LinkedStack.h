#pragma once

#ifndef __LINKEDSTACK_H__
#define __LINKEDSTACK_H__

#include "Node.h"

class LinkedStack {
public:
	LinkedStack()
		: top(nullptr) { }
	~LinkedStack()	{ while (!isEmpty()) delete pop(); }
	bool	isEmpty() { return top == nullptr; }
	void	push(Node* item);
	Node*	pop();
	Node*	peek() { return top; }
	void	display();
private:
	Node*	top;
};

void LinkedStack::push(Node * item)
{
	Node* next = top;
	top = item;
	item->setLink(next);
}

Node * LinkedStack::pop()
{
	if (isEmpty())	return nullptr;

	Node* result = top;
	top = top->getLink();

	return result;
}

void LinkedStack::display()
{
	puts("Stack Content");
	puts("--------------------");
	for (Node* link = top; link != nullptr; link = link->getLink())
		link->display();
	puts("");
}
#endif