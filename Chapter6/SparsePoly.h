#pragma once

#ifndef __SPARSEPOLY_H__
#define __SPARSEPOLY_H__

#include <iostream>
#include "TermList.h"

class SparsePoly {
public:
	SparsePoly() = default;

	void read();
	void add(SparsePoly& lhs, SparsePoly& rhs);
	void display(char* str = "SPoly = ");
private:
	TermList terms;
};

//Feature : to read data from console
inline void SparsePoly::read()
{
	int expon;
	float coeff;

	int num;
	std::cout << "Enter the number of polynomial : ";
	std::cin >> num;
	std::cout << "Enter coefficient and exponent(" << num << " from highest term, ex. 3, 12)\n";
	for (int i = 0; i != num; ++i)
	{
		std::cout << i + 1 << " Term : ";
		std::cin >> coeff >> expon;
		terms.insert(new TermNode(expon, coeff), i);
	}
}

//Feature : to add two sparsepoly
inline void SparsePoly::add(SparsePoly & lhs, SparsePoly & rhs)
{
	TermNode* lhsNode = lhs.terms.getHead();
	TermNode* rhsNode = rhs.terms.getHead();

	int index = 0;
	while (lhsNode && rhsNode)
	{
		if (lhsNode->expon == rhsNode->expon)
		{
			terms.insert(new TermNode(lhsNode->expon, lhsNode->coeff + rhsNode->coeff), index);
			lhsNode = lhsNode->getNext();
			rhsNode = rhsNode->getNext();
		}	
		else
		{
			if (lhsNode->expon > rhsNode->expon)
			{
				terms.insert(new TermNode(lhsNode->expon, lhsNode->coeff), index);
				lhsNode = lhsNode->getNext();
			}
			else
			{
				terms.insert(new TermNode(rhsNode->expon, rhsNode->coeff), index);
				rhsNode = rhsNode->getNext();
			}
		}
		++index;
	}

	//handle the rest value
	while (lhsNode)
	{
		terms.insert(new TermNode(lhsNode->expon, lhsNode->coeff), index);
		++index;
		lhsNode = lhsNode->getNext();
	}
	while (rhsNode)
	{
		terms.insert(new TermNode(rhsNode->expon, rhsNode->coeff), index);
		++index;
		rhsNode = rhsNode->getNext();
	}
}

inline void SparsePoly::display(char * str)
{
	TermNode* currentNode = terms.getHead();
	printf("%s (%d°³Ç×) = ", str, terms.size());
	while (currentNode->getNext())
	{
		printf("%2.1f x^%d + ", currentNode->coeff, currentNode->expon);
		currentNode = currentNode->getNext();
	}
	printf("%2.1f x^%d\n", currentNode->coeff, currentNode->expon);
}
#endif