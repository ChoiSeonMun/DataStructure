#pragma once

#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__

#include "Node2.h"

class DoubleLinkedList {
public:
	DoubleLinkedList()
		: origin(0) { }
	~DoubleLinkedList() { clear(); }

	Node2*	getHead() { return origin.getNext(); }
	Node2*	getEntry(int pos);
	Node2*	remove(int pos);
	Node2*	find(int val);
	void	replace(int pos, Node2* node);
	void	insert(int pos, Node2* node);
	void	display();
	void	clear() { while (!isEmpty()) delete remove(0); }
	//Problem Programming Project 1-1
	void	reverse();
	bool	isEmpty() { return getHead() == nullptr; }
	int		size();
private:
	Node2	origin;
};

//Feature : to get the item at pos in the list
//Return if pos is invalid, return nullptr. or, return the item
Node2 * DoubleLinkedList::getEntry(int pos)
{
	Node2* currentNode = &origin;
	for (int i = -1; currentNode && i < pos; ++i)
		currentNode = currentNode->getNext();

	return currentNode;
}

//Feature : to remove the item at next pos from the list
//Return : if pos is invalid, return nullptr. or, return the item at pos
Node2 * DoubleLinkedList::remove(int pos)
{
	Node2* before = getEntry(pos);

	return before->remove();
}

//Feature : to find the item in list
//Return : if item is in list, return the item. or, return nullptr
Node2* DoubleLinkedList::find(int item)
{
	for (Node2* currentNode = getHead(); currentNode; currentNode = currentNode->getNext())
	{
		if (currentNode->hasData(item))
			return currentNode;
	}

	return nullptr;
}

//Feature : to replace the item at pos with the node.
//			if pos is invaild, the list isn't changed
void DoubleLinkedList::replace(int pos, Node2 * node)
{
	Node2* before = getEntry(pos - 1);

	if (before)
	{
		delete before->getNext()->remove();
		before->insertNext(node);
	}
}

//Feature : to insert the node into next pos.
//			if pos is invaild, to insert the node into last.
void DoubleLinkedList::insert(int pos, Node2 * node)
{
	Node2* before = getEntry(pos - 1);

	before->insertNext(node);
}

//Feature : to display items in list
void DoubleLinkedList::display()
{
	printf("[the number of total items : %2d] : ", size());
	for (Node2* currentNode = getHead(); currentNode; currentNode = currentNode->getNext())
		currentNode->display();
	puts(" ");
}

//Feature : to reverse the nodes
void DoubleLinkedList::reverse()
{
	Node2* temp;
	getHead()->setPrev(nullptr);
	origin.setNext(getEntry(size() - 1));
	for (Node2* currentNode = getHead(); currentNode; currentNode = currentNode->getNext())
	{
		temp = currentNode->getNext();
		currentNode->setNext(currentNode->getPrev());
		currentNode->setPrev(temp);
	}
	getHead()->setPrev(&origin);
}

int DoubleLinkedList::size()
{
	int count = 0;
	for (Node2* currentNode = getHead(); currentNode; currentNode = currentNode->getNext())
		++count;

	return count;
}
#endif