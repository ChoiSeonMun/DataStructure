#include "SparsePoly.h"

int main()
{
	SparsePoly a, b, c;
	a.read();
	b.read();
	c.add(a, b);
	a.display("A = ");
	b.display("B = ");
	c.display("A + B = ");
	return 0;
}