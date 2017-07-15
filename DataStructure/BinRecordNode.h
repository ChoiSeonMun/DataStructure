#pragma once

#ifndef __BINRECORDNODE_H__
#define __BINRECORDNODE_H__

#include "Record.h"

class BinRecordNode : public Record {
public:
	BinRecordNode(char* word = "", char* meaning = "")
		: Record(word, meaning), left(nullptr), right(nullptr) { }

	void			setLeft(BinRecordNode* node) { left = node; }
	void			setRight(BinRecordNode* node) { right = node; }
	BinRecordNode*	getLeft() { return left; }
	BinRecordNode*	getRight() { return right; }
	bool			isLeaf() { return !left && !right; }
private:
	BinRecordNode*	left;
	BinRecordNode*	right;
};
#endif