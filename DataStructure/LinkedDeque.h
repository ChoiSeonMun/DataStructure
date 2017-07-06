#pragma once

#ifndef __LINKEDDEQUE_H__
#define __LINKEDDEQUE_H__

#include "DoubleLinkedList.h"

class LinkedDeque : public DoubleLinkedList {
public:
	void	addFront(int data) { insert(0, new Node2(data)); }
	void	addRear(int data) { insert(size(), new Node2(data)); }
	Node2*	deleteFront() { return remove(0); }
	Node2*	deleteRear() { return remove(size() - 1); }
	Node2*	getFront() { return getEntry(0); }
	Node2*	getRear() { return getEntry(size() - 1); }
};
#endif