#pragma once

#ifndef __SPARSEPOLY_H__
#define __SPARSEPOLY_H__

#include <iostream>
#include "Term.h"

constexpr unsigned MAX_TERMS = 10;

class SparsePoly {
public:
	SparsePoly()
		: nTerms(0), terms() { }

	void read();
	void add(SparsePoly& lhs, SparsePoly& rhs);
	void display(char* str = "SPoly = ");
private:
	int nTerms;
	Term terms[MAX_TERMS];
};

inline void SparsePoly::read()
{
	std::cout << "Enter the number of polynomial : ";
	std::cin >> nTerms;
	for (int i = 0; i != nTerms; ++i)
	{
		std::cout << "Enter coefficient and exponent(ex. 3 2) : ";
		std::cin >> terms[i].coeff >> terms[i].expon;
	}
}

inline void SparsePoly::add(SparsePoly & lhs, SparsePoly & rhs)
{
	//���� �Ķ���Ϳ� ������ �Ķ������, ������ ������������ ������ Term�������� �迭 ����
	Term* pTerms[MAX_TERMS] = { nullptr };
	//���� �Ķ����, ������ �Ķ����, *this�� ���ͷ�����
	int lhsIter = 0, rhsIter = 0, iter = 0;
	//���ʰ� ������ ���ͷ����Ͱ� ��� ���� �������� �ʾҴٸ�
	while (!(rhsIter == rhs.nTerms && lhsIter == lhs.nTerms))
	{
		if (lhsIter == lhs.nTerms)
			pTerms[iter++] = &rhs.terms[rhsIter++];
		else if (rhsIter == rhs.nTerms)
			pTerms[iter++] = &lhs.terms[lhsIter++];
		else
		{
			if (lhs.terms[lhsIter].expon >= rhs.terms[rhsIter].expon)
				pTerms[iter++] = &lhs.terms[lhsIter++];
			else
				pTerms[iter++] = &rhs.terms[rhsIter++];
		}
	}

	//pTerms���� *this�� terms�� ������ �ű��.
	int currentIdx = 0, i = 0;
	while(i < iter - 1)
	{
		//���� ����Ű�� �ִ� ���� �� ���� ���� ������ ���ٸ�
		if (pTerms[i]->expon == pTerms[i + 1]->expon)
		{
			//�� ���� ������ ���� �����Ѵ�.
			terms[currentIdx].expon = pTerms[i]->expon;
			terms[currentIdx++].coeff = pTerms[i]->coeff + pTerms[i + 1]->coeff;
			i += 2;
		}
		else
		{
			terms[currentIdx].expon = pTerms[i]->expon;
			terms[currentIdx++].coeff = pTerms[i]->coeff;
			++i;
		}
		++nTerms;
	}
	//HACK :: ������ ���� ������ ���� ���� ������ �ٸ� ��, ó�����ش�.
	if (pTerms[i - 1]->expon != pTerms[i]->expon)
	{
		terms[currentIdx].expon = pTerms[i]->expon;
		terms[currentIdx].coeff = pTerms[i]->coeff;
		++nTerms;
	}
}

inline void SparsePoly::display(char * str)
{
	std::cout << str;
	for (int i = 0; i != nTerms - 1; ++i)
		std::cout << terms[i].coeff << " x^" << terms[i].expon << " + ";
	std::cout << terms[nTerms - 1].coeff << " x^" << terms[nTerms - 1].expon << std::endl;
}
#endif