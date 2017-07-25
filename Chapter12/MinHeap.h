#pragma once

#ifndef __MINHEAP_H__
#define __MINHEAP_H__

#include "HeapNode.h"

constexpr int MAX_ELEMENT = 200;

class MinHeap {
public:
	MinHeap()
		: size(0) { }

	bool		isEmpty() { return size == 0; }
	bool		isFull() { return size == MAX_ELEMENT - 1; }
	HeapNode&	getParent(int i) { return node[i / 2]; }
	HeapNode&	getLeft(int i) { return node[i * 2]; }
	HeapNode&	getRight(int i) { return node[i * 2 + 1]; }
	void		insert(int key);
    void        insert(int key, int vertex1, int vertex2);
	HeapNode	remove();
	HeapNode	find() { return node[1]; }
private:
	int			size;
	HeapNode	node[MAX_ELEMENT];
};

void MinHeap::insert(int key)
{
	if (isFull())
		return;

	int idx = ++size;
	while (idx != 1 && key < getParent(idx).getKey())
	{
		node[idx] = getParent(idx);
		idx /= 2;
	}
	node[idx].setKey(key);
}

inline void MinHeap::insert(int key, int vertex1, int vertex2)
{
    if (isFull())
        return;

    int idx = ++size;
    while (idx != 1 && key < getParent(idx).getKey())
    {
        node[idx] = getParent(idx);
        idx /= 2;
    }
    node[idx].set(key, vertex1, vertex2);
}

HeapNode MinHeap::remove()
{
    if (isEmpty())
        return HeapNode();

	HeapNode removed = node[1];
	HeapNode last = node[size--];
	int parent = 1;
	int child = 2;
	while (child <= size)
	{
		if (child < size && getLeft(parent).getKey() > getRight(parent).getKey())
			++child;
		if (last.getKey() <= node[child].getKey())
			break;
		node[parent] = node[child];
		parent = child;
		child *= 2;
	}
	node[parent] = last;

	return removed;
}
#endif