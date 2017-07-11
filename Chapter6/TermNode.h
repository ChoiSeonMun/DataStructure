#pragma once

#ifndef __TERMNODE_H__
#define __TERMNODE_H__

#include "Term.h"

class TermNode : public Term {
public:
	TermNode(int expon = 0, float coeff = 0.0 )
		: Term(expon, coeff), prev(nullptr), next(nullptr) { }

	bool		operator==(TermNode other) { return static_cast<Term>(*this) == static_cast<Term>(other); }
	bool		operator!=(TermNode other) { return static_cast<Term>(*this) != static_cast<Term>(other); }
	bool		operator>(TermNode other) { return static_cast<Term>(*this) > static_cast<Term>(other); }
	bool		operator>=(TermNode other) { return static_cast<Term>(*this) >= static_cast<Term>(other); }
	bool		operator<(TermNode other) { return static_cast<Term>(*this) < static_cast<Term>(other); }
	bool		operator<=(TermNode other) { return static_cast<Term>(*this) <= static_cast<Term>(other); }

	TermNode*	getNext() { return next; }
	TermNode*	getPrev() { return prev; }
	void		setNext(TermNode* link) { next = link; }
	void		setPrev(TermNode* link) { prev = link; }
	TermNode*	remove();
	void		insertNext(TermNode* node);
	void		insertPrev(TermNode* node);
private:
	TermNode*	prev;
	TermNode*	next;
};

//Feature : to remove this node
//Return : removed node. if next node is nonexistent, return nullptr
TermNode * TermNode::remove()
{
	if (next)
		next->setPrev(prev);
	if (prev)
		prev->setNext(next);
	prev = next = nullptr;
	
	return this;
}

//Feature : to insert the node into next
void TermNode::insertNext(TermNode * node)
{
	if (node)
	{
		node->setNext(next);
		node->setPrev(this);
		if (next)
			next->setPrev(node);
		next = node;
	}
}

//Feature : to insert the node into prev
void TermNode::insertPrev(TermNode * node)
{
	if (node)
	{
		node->setNext(this);
		node->setPrev(prev);
		if (prev)
			prev->setNext(node);
		prev = node;
	}
}
#endif