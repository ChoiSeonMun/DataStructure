#pragma once

#ifndef __CIRCULARLIST_H__
#define __CIRCULARLIST_H__

#include "Node.h"

//Problem Programming Project 2
class CircularList {
public:
	CircularList() = default;
	~CircularList() { clear(); }

	Node*	getHead() { return origin.getNext(); }
	Node*	remove(int pos);
	Node*	getEntry(int pos);
	Node*	find(char* content);
	int		size() { return index + 1; }
	bool	isEmpty() { return index == -1; }
	void	replace(int pos, Node* node);
	void	clear() { while (!isEmpty()) delete remove(0); }
	void	insert(int pos, Node* node);
	void	display();
	//Problem Program Project 1-2
	void	merge(CircularList* that);
protected:
	Node	origin;
	int		index = -1;
};

//Feature : to insert the node into pos.
void CircularList::insert(int pos, Node * node)
{
	if (pos <= index || index == -1)
	{
		Node* before = getEntry(pos - 1);
		before->insertNext(node);
		if (before->getNext()->getNext() == nullptr)
			before->getNext()->setNext(getHead());
		++index;
	}
	else
		puts("Invalid pos");
}

inline void CircularList::display()
{
	int i = 0;
	for (Node* currentNode = getHead(); i <= index && currentNode; currentNode = currentNode->getNext(), ++i)
	{
		currentNode->print();
		puts("");
	}
}

//Feature : to merge that list to this list
void CircularList::merge(CircularList * that)
{
	int endPosition = size();
	while (!that->isEmpty())
	{
		insert(endPosition, that->remove(0));
		++endPosition;
		++index;
	}
}

//Feature : to remove the item at pos from the list
//Return : if pos is invalid, return nullptr. or, return the item at pos
Node * CircularList::remove(int pos)
{
	if (pos > index)
		return nullptr;

	Node* before = getEntry(pos - 1);
	Node* removed = before->removeNext();
	before->setNext(getHead());
	--index;

	return removed;
}

//Feature : to get the item at pos in the list
//Return if pos is invalid, return nullptr. or, return the item
Node * CircularList::getEntry(int pos)
{
	Node* currentNode = &origin;
	for (int i = -1; i <= index && i < pos; ++i)
		currentNode = currentNode->getNext();

	return currentNode;
}

//Feature : to find the item in list
//Return : if item is in list, return the item. or, return nullptr
Node * CircularList::find(char* content)
{
	int i = 0;
	for (Node* currentNode = getHead(); i <= index && currentNode; currentNode = currentNode->getNext(), ++i)
	{
		if (currentNode->hasData(content))
			return currentNode;
	}

	return nullptr;
}

//Feature : to replace the item at pos with the node.
//			if pos is invaild, the list isn't changed
void CircularList::replace(int pos, Node * node)
{
	Node* before = getEntry(pos - 1);

	if (before)
	{
		delete before->removeNext();
		before->insertNext(node);
		if (before->getNext()->getNext() == nullptr)
			before->getNext()->setNext(getHead());
	}
}

#endif