#include "BinaryTree.h"

int main()
{
	BinaryTree<int> tree1, tree2;
	
	BinaryNode<int>* n1 = new BinaryNode<int>(20, nullptr, nullptr);
	BinaryNode<int>* n3 = new BinaryNode<int>(30, nullptr, nullptr);
	BinaryNode<int>* n2 = new BinaryNode<int>(10, n1, n3);
	BinaryNode<int>* n4 = new BinaryNode<int>(10, nullptr, nullptr);
	
	tree1.setRoot(n2);
	tree2.setRoot(n4);
	if (tree1.isDisjointFrom(tree2))
		puts("ºÐ¸®µÊ");
	else
		puts("¾Æ´Ô");

	delete n1;
	delete n2;
	delete n3;
	delete n4;

	return 0;
}