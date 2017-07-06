#include "LinkedDeque.h"

int main()
{
	LinkedDeque deq;

	for (int i = 1; i < 10; ++i)
	{
		if (i % 2) { deq.addFront(i); }
		else { deq.addRear(i); }
	}
	deq.display();
	delete deq.deleteFront();
	delete deq.deleteRear();
	delete deq.deleteFront();
	deq.display();

	return 0;
}