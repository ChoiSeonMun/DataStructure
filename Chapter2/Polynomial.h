#pragma once

#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include <iostream>

constexpr int MAX_DEGREE = 80;

class Polynomial {
public:
	Polynomial()
		: degree(0), coef() { }

	void read();
	void display(char* str = " Poly = ");
	void add(Polynomial& lhs, Polynomial& rhs);
	//Problem 1
	void sub(Polynomial& lhs, Polynomial& rhs);
	//Problem 2
	void mult(Polynomial& lhs, Polynomial& rhs);
	//Problem 3
	void trim();
	bool isZero() { return degree == 0; }
	void negate();
private:
	int degree;
	float coef[MAX_DEGREE];
};

inline void Polynomial::read()
{
	std::cout << "Enter the supreme degree of polynomial : ";
	std::cin >> degree;
	std::cout << "Enter each coefficient. (Total : " << degree + 1 << ") : ";
	for (int i = 0; i <= degree; ++i)
		std::cin >> coef[i];
}

inline void Polynomial::display(char * str)
{
	std::cout << '\t' << str;
	//Problem 4
	for (int i = 0; i != degree; ++i)
	{
		if (coef[i] == 0.0)
			continue;
		else if (coef[i] == 1.0)
			std::cout << "x^" << degree - i << " + ";
		else
			std::cout << coef[i] << " x^" << degree - i << " + ";
	}
	if (coef[degree] != 0.0)
		std::cout << coef[degree] << std::endl;
}

inline void Polynomial::add(Polynomial & lhs, Polynomial & rhs)
{
	if (lhs.degree > rhs.degree)
	{
		*this = lhs;
		for (int i = 0; i <= rhs.degree; ++i)
			coef[i + (degree - rhs.degree)] += rhs.coef[i];
	}
	else
	{
		*this = rhs;
		for (int i = 0; i <= lhs.degree; ++i)
			coef[i + (degree - lhs.degree)] += lhs.coef[i];
	}
}

inline void Polynomial::sub(Polynomial & lhs, Polynomial & rhs)
{
	if (lhs.degree < rhs.degree)
	{
		const int diff = rhs.degree - lhs.degree;
		degree = rhs.degree;
		int lhsIter = 0, rhsIter = 0, iter = 0;
		while(rhsIter != diff)
			coef[iter++] = -rhs.coef[rhsIter++];
		while(lhsIter <= lhs.degree)
			coef[iter++] = lhs.coef[lhsIter++] - rhs.coef[rhsIter++];
	}
	else
	{
		const int diff = lhs.degree - rhs.degree;
		degree = lhs.degree;
		int lhsIter = 0, rhsIter = 0, iter = 0;
		while (lhsIter != diff)
			coef[iter++] = lhs.coef[lhsIter++];
		while (rhsIter <= rhs.degree)
			coef[iter++] = lhs.coef[lhsIter++] - rhs.coef[rhsIter++];
	}
}

inline void Polynomial::mult(Polynomial & lhs, Polynomial & rhs)
{
	degree = lhs.degree + rhs.degree;
	for (int i = 0; i <= lhs.degree; ++i)
	{
		for (int j = 0; j <= rhs.degree; ++j)
		{
			coef[i + j] += lhs.coef[i] * rhs.coef[j];
		}
	}
}

inline void Polynomial::trim()
{
	while (coef[degree] == 0)
		--degree;
}

inline void Polynomial::negate()
{
	for (int i = 0; i != degree; ++i)
		coef[i] = -coef[i];
}
#endif