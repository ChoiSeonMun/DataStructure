#pragma once

#ifndef __RECORDTREE_H__
#define __RECORDTREE_H__

#include "BinRecordNode.h"

class RecordTree {
public:
	RecordTree()
		: root(nullptr) { }

	bool			isEmpty() { return !root; }
	void			inorder(BinRecordNode* node);
protected:
	BinRecordNode*	root;
};

void RecordTree::inorder(BinRecordNode* node)
{
	if (node)
	{
		inorder(node->getLeft());
		node->display();
		inorder(node->getRight());
	}
}
#endif