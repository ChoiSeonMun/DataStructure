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
	//왼쪽 파라미터와 오른쪽 파라미터의, 지수의 내림차순으로 저장할 Term포인터의 배열 선언
	Term* pTerms[MAX_TERMS] = { nullptr };
	//왼쪽 파라미터, 오른쪽 파라미터, *this의 이터레이터
	int lhsIter = 0, rhsIter = 0, iter = 0;
	//왼쪽과 오른쪽 이터레이터가 모두 끝에 도달하지 않았다면
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

	//pTerms에서 *this의 terms로 값들을 옮긴다.
	int currentIdx = 0, i = 0;
	while(i < iter - 1)
	{
		//현재 가리키고 있는 값과 그 다음 값의 지수가 같다면
		if (pTerms[i]->expon == pTerms[i + 1]->expon)
		{
			//두 값을 더해준 다음 대입한다.
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
	//HACK :: 마지막 값의 지수가 이전 값의 지수와 다를 때, 처리해준다.
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