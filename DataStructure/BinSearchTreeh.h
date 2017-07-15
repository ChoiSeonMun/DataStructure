#pragma once

#ifndef __BINSEARCHTREE_H__
#define __BINSEARCHTREE_H__

#include "BinaryTree.h"

template <typename T>
class BinSearchTree : public BinaryTree<T> {
public:
	BinSearchTree() = default;

	void		insert(BinaryNode* node) { root->insert(node); }
	void		remove(T key);
	BinaryNode*	search(T key) {	return root->search(key); }
private:
	void		insert(BinaryNode* node, BinaryNode* newNode);
	void		remove(BinaryNode* parent, BinaryNode* node);
	BinaryNode*	searchRecur(BinaryNode* node, T key);
	BinaryNode* searchIter(BinaryNode* node, T key);
};
#endif

//template<typename T>
//inline void BinSearchTree<T>::insert(BinaryNode<T> * node)
//{
//	if (!node)		return;
//	if (isEmpty())	root = node;
//	else			insert(root, node);
//}

template<typename T>
inline void BinSearchTree<T>::remove(T key)
{
	if (isEmpty())
		return;

	BinaryNode<T>* parent = nullptr;
	BinaryNode<T>* node = root;

	while (node && node->getData() != key)
	{
		parent = node;
		node = (key < node->getData()) ? node->getLeft() : node->getRight();
	}

	if (!node)
	{
		puts("Error : There is no key");
		return;
	}
	else
		remove(parent, node);
}

//template<typename T>
//inline BinaryNode<T> * BinSearchTree<T>::search(T key)
//{
//	BinaryNode<T>* node = searchRecur(root, key);
//	if (node)
//		printf("탐색 성공 : 키 값이 %d인 노드 = 0x%x\n", node->getData(), node);
//	else
//		printf("탐색 실패 : 키 값이 %d인 노드 없음\n", key);
//
//	return node;
//}

template<typename T>
inline void BinSearchTree<T>::insert(BinaryNode<T> * node, BinaryNode<T> * newNode)
{
	if (newNode->getData() == node->getData())
		return;

	if (newNode->getData() < node->getData())
	{
		if (!node->getLeft())
			node->setLeft(newNode);
		else
			insert(node->getLeft(), newNode);
	}
	else
	{
		if (!node->getRight())
			node->setRight(newNode);
		else
			insert(node->getRight(), newNode);
	}
}

template<typename T>
inline void BinSearchTree<T>::remove(BinaryNode<T> * parent, BinaryNode<T> * node)
{
	if (node->isLeaf())
	{
		if (node == root)
			root = nullptr;
		else
		{
			if (parent->getLeft() == node)
				parent->setLeft(nullptr);
			else
				parent->setRight(nullptr);
		}
	}
	else if (node->getLeft() || node->getRight())
	{
		BinaryNode<T>* child = node->getLeft() ? node->getLeft() : node->getRight();
		if (node == root)
			root = child;
		else
		{
			if (node == parent->getLeft())
				parent->setLeft(child);
			else
				parent->setRight(child);
		}
	}
	else
	{
		BinaryNode<T>* successorParent = node;
		BinaryNode<T>* successor = node->getRight();
		while (successor->getLeft())
		{
			successorParent = successor;
			successor = successor->getLeft();
		}

		if (successorParent->getLeft() == successor)
			successorParent->setLeft(successor->getRight());
		else
			successorParent->setRight(successor->getRight());

		node->setData(successor->getData());
		node = successor;
	}
	delete node;
}

template<typename T>
inline BinaryNode<T> * BinSearchTree<T>::searchRecur(BinaryNode<T> * node, T key)
{
	if (!node)
		return nullptr;
	if (key == node->getData()
		return node;
	else if (key < node->getData())
		return search(node->getLeft(), key);
	else
		return search(node->getRight(), key);
}

template<typename T>
inline BinaryNode<T> * BinSearchTree<T>::searchIter(BinaryNode<T> * node, T key)
{
	while (!node)
	{
		if (key == node->getData())
			return node;
		else if (key < node->getData())
			node = node->getLeft();
		else
			node = node->getRight();
	}
	
	return nullptr;
}
