#include "LinkedQueue.h"

int main()
{
	LinkedQueue queue;
	queue.enqueue(new Node(2015130007, "ȫ�浿", "��ǻ�Ͱ��а�"));
	queue.enqueue(new Node(2015130100, "�̼���", "�����а�"));
	queue.enqueue(new Node(2015130135, "�����", "�ż�����а�"));
	queue.display();

	Node* node = queue.dequeue();
	puts("[Pop �׸�]");
	node->display();
	delete node;
	queue.display();

	return 0;
}