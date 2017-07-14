#pragma once

#ifndef __THREADNODE_H__
#define __THREADNODE_H__

#pragma once

#ifndef __BINARYNODE_H__
#define __BINARYNODE_H__

template <typename T>
class ThreadNode {
public:
	ThreadNode()
		: data(), left(nullptr), right(nullptr), isThread(false) { }
	ThreadNode(T dataVal, ThreadNode* leftVal, ThreadNode* rightVal, bool thread)
		: data(dataVal), left(leftVal), right(rightVal), isThread(thread) { }

	void		setData(T item) { data = item; }
	void		setLeft(ThreadNode* node) { left = node; }
	void		setRight(ThreadNode* node) { right = node; }
	T			getData() { return data; }
	ThreadNode*	getLeft() { return left; }
	ThreadNode*	getRight() { return right; }
	bool		isLeaf() { return !left && !right); }
	void		inOrder();
	void		preOrder();
	void		postOrder();
	int			getCount();
	int			getLeafCount();
private:
	T			data;
	ThreadNode*	left;
	ThreadNode*	right;
	bool		isThread;
};
#endif

template<typename T>
void ThreadNode<T>::inOrder()
{
	if (left) left->inOrder();
	printf(" [%c] ", data);
	if (right) right->inOrder();
}

template<typename T>
void ThreadNode<T>::preOrder()
{
	printf(" [%c] ", data);
	if (left) left->preOrder();
	if (right) right->preOrder();
}

template<typename T>
void ThreadNode<T>::postOrder()
{
	if (left) left->postOrder();
	if (right) right->postOrder();
	printf(" [%c] ", data);
}

template<typename T>
inline int ThreadNode<T>::getCount()
{
	if (!this)
		return 0;
	else
		return 1 + left->getCount() + right->getCount();
}

template<typename T>
int ThreadNode<T>::getLeafCount()
{
	if (!this)
		return 0;

	if (isLeaf())
		return 1;
	else
		return left->getLeafCount() + right->getLeafCount();
}
#endif