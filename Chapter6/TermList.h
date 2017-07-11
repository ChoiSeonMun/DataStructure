#pragma once

#ifndef __TERMLIST_H__
#define __TERMLIST_H__

#include "TermNode.h"

class TermList {
public:
	TermList() = default;
	~TermList() { clear(); }

	TermNode*	getHead() { return origin.getNext(); }
	TermNode*	remove(int pos);
	TermNode*	getEntry(int pos);
	int		size();
	bool	isEmpty() { return getHead() == nullptr; }
	void	clear() { while (!isEmpty()) delete remove(0); }
	void	insert(TermNode* node, int pos);
protected:
	TermNode	origin;
};

//Feature : to insert the node into pos
//			if pos is invalid, there is no change
void TermList::insert(TermNode * node, int pos)
{
	TermNode* before = getEntry(pos - 1);
	before->insertNext(node);
}

//Feature : to remove the item at pos from the list
//Return : if pos is invalid, return nullptr. or, return the item at pos
TermNode * TermList::remove(int pos)
{
	TermNode* currentNode = getEntry(pos);

	return currentNode->remove();
}

//Feature : to get the item at pos in the list
//Return if pos is invalid, return nullptr. or, return the item
TermNode * TermList::getEntry(int pos)
{
	TermNode* currentNode = &origin;
	for (int i = -1; currentNode && i < pos; ++i)
		currentNode = currentNode->getNext();

	return currentNode;
}

//Feature : to count the number of elements in list
//Return : the number of elements in list
int TermList::size()
{
	int count = 0;
	for (TermNode* currentNode = getHead(); currentNode; currentNode = currentNode->getNext())
		++count;

	return count;
}

#endif