#include "SparsePoly.h"

int main()
{
	SparsePoly A, B, C;

	A.read();
	B.read();
	C.add(A, B);
	A.display("A = ");
	B.display("B = ");
	C.display("A + B = ");

	return 0;
}