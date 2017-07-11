#pragma once

#ifndef __TERM_H__
#define __TERM_H__

struct Term {
	Term(int ex, float co)
		:expon(ex), coeff(co) { }
	
	bool operator==(Term& other);
	bool operator!=(Term& other);
	bool operator<(Term& other);
	bool operator<=(Term& other);
	bool operator>(Term& other);
	bool operator>=(Term& other);

	int		expon = 0;
	float	coeff = 0.0;
};

inline bool Term::operator==(Term & other)
{
	return (expon == other.expon) && (coeff == other.coeff);
}

inline bool Term::operator!=(Term & other)
{
	return !(*this == other);
}

inline bool Term::operator<(Term & other)
{
	//compare exponent
	if (expon < other.expon)
		return true;
	else
		return false;

	if (coeff < other.coeff)
		return true;
	else
		return false;
}

inline bool Term::operator<=(Term & other)
{
	return (*this == other) || (*this < other);
}

inline bool Term::operator>(Term & other)
{
	return (*this != other) && !(*this < other);
}

inline bool Term::operator>=(Term & other)
{
	return (*this == other) || (*this > other);
}
#endif

