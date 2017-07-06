#pragma once

#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "Node.h"

class LinkedList {
public:
	LinkedList()
		: origin(0) { }
	~LinkedList() { clear(); }

	Node*	getHead() { return origin.getNext(); }
	Node*	remove(int pos);
	Node*	getEntry(int pos);
	Node*	find(char* content);
	int		size();
	bool	isEmpty() { return getHead() == nullptr; }
	void	replace(int pos, Node* node);
	void	clear() { while (!isEmpty()) delete remove(0); }
	void	insert(int pos, Node* node);
protected:
	Node	origin;
};

//Feature : to insert the node into pos.
//			if pos is invaild, to insert the node into last.
void LinkedList::insert(int pos, Node * node)
{
	Node* before = getEntry(pos - 1);

	before->insertNext(node);
}

//Feature : to remove the item at pos from the list
//Return : if pos is invalid, return nullptr. or, return the item at pos
Node * LinkedList::remove(int pos)
{
	Node* before = getEntry(pos - 1);
	
	return before->removeNext();
}

//Feature : to get the item at pos in the list
//Return if pos is invalid, return nullptr. or, return the item
Node * LinkedList::getEntry(int pos)
{
	Node* currentNode = &origin;
	for (int i = -1; currentNode && i < pos; ++i)
		currentNode = currentNode->getNext();

	return currentNode;
}

//Feature : to find the item in list
//Return : if item is in list, return the item. or, return nullptr
Node * LinkedList::find(char* content)
{
	for (Node* currentNode = getHead(); currentNode; currentNode = currentNode->getNext())
	{
		if (currentNode->hasData(content))
			return currentNode;
	}

	return nullptr;
}

int LinkedList::size()
{
	int count = 0;
	for (Node* currentNode = getHead(); currentNode; currentNode = currentNode->getNext())
		++count;

	return count;
}

//Feature : to replace the item at pos with the node.
//			if pos is invaild, the list isn't changed
void LinkedList::replace(int pos, Node * node)
{
	Node* before = getEntry(pos - 1);
	
	if (before)
	{
		delete before->removeNext();
		before->insertNext(node);
	}
}
#endif