#pragma once

#ifndef __THREADTREE_H__
#define __THREADTREE_H__

#include "ThreadNode.h"
#include <cstdio>

template <typename T>
class ThreadTree {
public:
	ThreadTree()
		: root(nullptr) { }

	void		setRoot(ThreadNode* node) { root = node; }
	bool		isEmpty() { return !root; }
	void		threadInOrder();
	ThreadNode*	findSuccessor(ThreadNode* node);
private:
	ThreadNode*	root;
};
#endif

template<typename T>
void ThreadTree<T>::threadInOrder()
{
	if (!isEmpty())
	{
		printf("스레드 이진트리 : ");
		ThreadNode<T>* node = root;
		while (node->getLeft())
			node = node->getLeft();
		do {
			printf("%c ", node->getData());
			node = findSuccessor(node);
		} while (node);
		puts("");
	}
}

template<typename T>
ThreadNode<T> * ThreadTree<T>::findSuccessor(ThreadNode<T>* node)
{
	ThreadNode<T>* right = node->getRight();
	if (!right || node->isThread)
		return right;
	while (right->getLeft())
		right = right->getLeft();
	return right;
}
