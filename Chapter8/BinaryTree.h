#pragma once

#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include "BinaryNode.h"

template <typename T>
class BinaryTree {
public:
	BinaryTree()
		: root(nullptr) { }

	void			setRoot(BinaryNode<T>* node) { root = node; }
	BinaryNode<T>*	getRoot() { return root; }
	bool			isEmpty() { return !root;	}
	void			inOrder() { printf("\n  inorder: "); if(!isEmpty()) root->inOrder(); }
	void			preOrder() { printf("\n  preorder: "); if (!isEmpty()) root->preOrder();	}
	void			postOrder() { printf("\n  postorder: "); if (!isEmpty()) root->postOrder(); }
	void			levelOrder();
	int				getCount() { return isEmtpy() ? 0 : root->getCount(); }
	int				getLeafCount() { return isEmpty() ? 0 : root->getLeafCount(); }
	int				getHeight() { return isEmpty() ? 0 : getHeight(root); }
	int				evaluate() { return evaluate(root); }
	int				calcSize() { return calcSize(root); }
	//Problem Program Project 1-1
	bool			isFull() { return getLeafCount() == pow(2, getHeight() - 1); }
	//Problem Program Project 1-2
	int				level(BinaryNode<T>* node);
	//Problem Program Project 1-3
	bool			isBalanced();
	//Problem Program Project 1-4
	int				pathLength() { return isEmpty() ? 0 : pathLength(root) - 1; }
	//Problem Program Project 1-5
	void			reverse();
	//Problem Program Project 1-6
	bool			isDisjointFrom(BinaryTree& other);
	//Problem Program Project 1-7
	bool			isValid(BinaryTree& other) { return isDisjointFrom(other); }
private:
	int				getHeight(BinaryNode<T>* node);
	int				evaluate(BinaryNode<T>* node);
	int				calcSize(BinaryNode<T>* node);
	int				pathLength(BinaryNode<T>* node);

	BinaryNode<T>*	root;
};

template <typename T>
void BinaryTree<T>::levelOrder()
{
	printf("\nLevelOrder: ");
	if (!isEmpty())
	{
		std::queue<BinaryNode<T>*> q;
		q.push(root);
		while (!q.empty())
		{
			BinaryNode<T>* node = q.front();
			q.pop();
			if (node)
			{
				printf(" [%c] ", node->getData());
				q.push(node->getLeft());
				q.push(node->getRight());
			}

		}
	}
}

template<typename T>
int BinaryTree<T>::level(BinaryNode<T>* node)
{
	if (isEmpty())
		return 0;

	std::queue<BinaryNode<T>*> que;
	que.push(root);
	int level = 0;
	while (!que.empty())
	{
		BinaryNode<T>* nodeInTree = que.front();
		que.pop();
		++level;
		if (nodeInTree == node)
			return level;
		if (nodeInTree->getLeft())
			que.push(nodeInTree->getLeft());
		if (nodeInTree->getRight())
			que.push(nodeInTree->getRight());
	}

	return 0;
}

template<typename T>
bool BinaryTree<T>::isBalanced()
{
	return isEmpty() ? false : (abs(getHeight(root->getLeft()) - getHeight(root->getRight())) < 2);
}

template<typename T>
void BinaryTree<T>::reverse()
{
	if (isEmpty())
		return;

	std::queue<BinaryNode<T>*> que;
	que.push(root);
	BinaryNode<T>* nodeInTree;
	BinaryNode<T>* temp;
	while (!que.empty())
	{
		nodeInTree = que.front();
		que.pop();
		if (nodeInTree->getLeft()) que.push(nodeInTree->getLeft());
		if (nodeInTree->getRight()) que.push(nodeInTree->getRight());
		temp = nodeInTree->getLeft();
		nodeInTree->setLeft(nodeInTree->getRight());
		nodeInTree->setRight(temp);
	}
}

template<typename T>
bool BinaryTree<T>::isDisjointFrom(BinaryTree<T> & other)
{
	std::queue<BinaryNode<T>*> thisQue;
	std::queue<BinaryNode<T>*> otherQue;
	BinaryNode<T>* thisNode;
	BinaryNode<T>* otherNode;
	thisQue.push(root);
	otherQue.push(other.getRoot());
	while (!thisQue.empty() && !otherQue.empty())
	{
		thisNode = thisQue.front();
		thisQue.pop();
		otherNode = otherQue.front();
		otherQue.pop();
		if (thisNode != otherNode)
			return true;
		if (thisNode->getLeft()) thisQue.push(thisNode->getLeft());
		if (thisNode->getRight()) thisQue.push(thisNode->getRight());
		if (otherNode->getLeft()) otherQue.push(otherNode->getLeft());
		if (otherNode->getRight()) otherQue.push(otherNode->getRight());
	}
	
	return false;
}

template<typename T>
int BinaryTree<T>::getHeight(BinaryNode<T>* node)
{
	if (!node)
		return 0;
	else
		return 1 + std::max(getHeight(node->getLeft()), getHeight(node->getRight()));
}

template<typename T>
int BinaryTree<T>::evaluate(BinaryNode<T> * node)
{
	if (!node)
		return 0;
	if (node->isLeaf())
		return node->data;

	int lval = evaluate(node->left);
	int rval = evaluate(node->right);
	char op = node->data;
	switch (op) {
	case '+':	return lval + rval;
	case '-':	return lval - rval;
	case '/':	return lval / rval;
	case '*':	return lval * rval;
	}

	return 0;
}

template<typename T>
int BinaryTree<T>::calcSize(BinaryNode<T> * node)
{
	if (!node)
		return 0;
	else
		return node->data + calcSize(node->left) + calcSize(node->right);
}

template<typename T>
int BinaryTree<T>::pathLength(BinaryNode<T>* node)
{
	if (!node)
		return 0;
	return 1 + pathLength(node->getLeft()) + pathLength(node->getRight());
}
#endif