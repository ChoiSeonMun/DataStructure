#include "LinkedQueue.h"

int main()
{
	LinkedQueue queue;
	queue.enqueue(new Node(2015130007, "홍길동", "컴퓨터공학과"));
	queue.enqueue(new Node(2015130100, "이순신", "기계공학과"));
	queue.enqueue(new Node(2015130135, "김냥이", "신소재공학과"));
	queue.display();

	Node* node = queue.dequeue();
	puts("[Pop 항목]");
	node->display();
	delete node;
	queue.display();

	return 0;
}