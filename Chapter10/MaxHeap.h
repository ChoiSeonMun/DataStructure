#pragma once

#ifndef __MAXHEAP_H__
#define __MAXHEAP_H__

#include "HeapNode.h"

constexpr int MAX_ELEMENT = 200;

class MaxHeap {
public:
	MaxHeap()
		: size(0) { }

	bool		isEmpty() { return size == 0; }
	bool		isFull() { return size == MAX_ELEMENT - 1; }
	HeapNode&	getParent(int i) { return node[i / 2]; }
	HeapNode&	getLeft(int i) { return node[i * 2]; }
	HeapNode&	getRight(int i) { return node[i * 2 + 1]; }
	void		insert(int key);
	HeapNode	remove();
	HeapNode	find() { return node[1]; }
	void		display();
private:
	int			size;
	HeapNode	node[MAX_ELEMENT];
};

void MaxHeap::insert(int key)
{
	if (isFull())
		return;

	int idx = ++size;
	while (idx != 1 && key > getParent(idx).getKey())
	{
		node[idx] = getParent(idx);
		idx /= 2;
	}
	node[idx].setKey(key);
}

HeapNode MaxHeap::remove()
{
	if (isEmpty())
		return NULL;

	HeapNode removed = node[1];
	HeapNode last = node[size--];
	int parent = 1;
	int child = 2;
	while (child <= size)
	{
		if (child < size && getLeft(parent).getKey() < getRight(parent).getKey())
			++child;
		if (last.getKey() >= node[child].getKey())
			break;
		node[parent] = node[child];
		parent = child;
		child *= 2;
	}
	node[parent] = last;
	
	return removed;
}

void MaxHeap::display()
{
	for (int i = 1, level = 1; i <= size; ++i)
	{
		if (i == level)
		{
			puts("");
			level *= 2;
		}
		node[i].display();
	}
	printf("\n------------------------------------");
}
#endif