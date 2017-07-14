#pragma once

#ifndef __BINARYNODE_H__
#define __BINARYNODE_H__

template <typename T>
class BinaryNode {
public:
	BinaryNode()
		: data(), left(nullptr), right(nullptr) { }
	BinaryNode(T data, BinaryNode* left, BinaryNode* right)
		: data(data), left(left), right(right) { }

	void		setData(T item) { data = item; }
	void		setLeft(BinaryNode* node) { left = node; }
	void		setRight(BinaryNode* node) { right = node; }
	T			getData() { return data; }
	BinaryNode*	getLeft() { return left; }
	BinaryNode*	getRight() { return right; }
	bool		isLeaf() { return !left && !right; }
	void		inOrder();
	void		preOrder();
	void		postOrder();
	int			getCount();
	int			getLeafCount();
private:
	T			data;
	BinaryNode*	left;
	BinaryNode*	right;
};
#endif

template<typename T>
void BinaryNode<T>::inOrder()
{
	if (left) left->inOrder();
	printf(" [%c] ", data);
	if (right) right->inOrder();
}

template<typename T>
void BinaryNode<T>::preOrder()
{
	printf(" [%c] ", data);
	if (left) left->preOrder();
	if (right) right->preOrder();
}

template<typename T>
void BinaryNode<T>::postOrder()
{
	if (left) left->postOrder();
	if (right) right->postOrder();
	printf(" [%c] ", data);
}

template<typename T>
inline int BinaryNode<T>::getCount()
{
	if (!this)
		return 0;
	else
		return 1 + left->getCount() + right->getCount();
}

template<typename T>
int BinaryNode<T>::getLeafCount()
{
	if (!this)
		return 0;

	if (isLeaf())
		return 1;
	else
		return left->getLeafCount() + right->getLeafCount();
}
