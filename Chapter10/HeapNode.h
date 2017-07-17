#pragma once

#ifndef __HEAPNODE_H__
#define __HEAPNODE_H__

#include <cstdio>

class HeapNode {
public:
	HeapNode(int key = 0)
		: key(key) { }

	void	setKey(int key) { this->key = key; }
	int		getKey() { return key; }
	void	display() { printf("%4d", key); }
private:
	int		key;
};
#endif