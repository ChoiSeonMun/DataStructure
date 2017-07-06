#include "LinkedList.h"

int main()
{
	LinkedList list1, list2;

	list1.insert(0, new Node("Char"));
	list1.insert(0, new Node("Name"));
	list1.insert(1, new Node("Mun"));
	
	return 0;
}