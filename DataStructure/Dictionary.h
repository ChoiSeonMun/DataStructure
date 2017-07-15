#pragma once

#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

#include "SrchRecordTree.h"

struct Dictionary : public SrchRecordTree {
	Dictionary() = default;

	void			printAllWords();
	void			searchWord(const char* word);
	void			searchMeaning(const char* meaning);
	BinRecordNode*	searchMeaning(BinRecordNode* node, const char* meaning);
};

void Dictionary::printAllWords()
{
	printf("    >> ���� �ܾ��� : \n");
	if (!isEmpty()) inorder(root);
}

void Dictionary::searchWord(const char * word)
{
	BinRecordNode* node = search(word);
	if (node)
	{
		printf("    >> ");
		node->display();
	}
	else
		printf("    >> ��ϵ��� ���� �ܾ� : %s\n", word);
}

void Dictionary::searchMeaning(const char * meaning)
{
	BinRecordNode* node = isEmpty() ? nullptr : searchMeaning(root, meaning);
	if (node)
	{
		printf("    >> ");
		node->display();
	}
	else
		printf("    >> ��ϵ��� ���� �ǹ� : %s\n", meaning);
}

BinRecordNode * Dictionary::searchMeaning(BinRecordNode * node, const char * meaning)
{
	if (!node || !node->compareMeaning(meaning))
		return node;
	BinRecordNode* theNode = searchMeaning(node->getLeft(), meaning);
	if (theNode)
		return theNode;
	return searchMeaning(node->getRight(), meaning);
}
#endif