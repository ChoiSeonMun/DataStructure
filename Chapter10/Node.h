#pragma once

#ifndef __NODE_H__
#define __NODE_H__

//Problem Program Project 2
class Node {
public:
	Node() = default;
	Node(int key)
		: key(key), next(nullptr) { }
	
	int		getKey() { return key; }
	Node*	getNext() { return next; }
	void	setKey(int k) { key = k; }
	void	setNext(Node* link) { next = link; }
	void	insertNext(Node* node);
private:
	int		key;
	Node*	next;
};

void Node::insertNext(Node * node)
{
	if (next)
		node->setNext(next);
	next = node;
}
#endif