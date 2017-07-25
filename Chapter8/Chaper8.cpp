#include "BinaryTree.h"

int main()
{
    BinaryTree<int> tree;
    
    BinaryNode<int>* F = new BinaryNode<int>(0, nullptr, nullptr);
    BinaryNode<int>* D = new BinaryNode<int>(0, nullptr, nullptr);
    BinaryNode<int>* C = new BinaryNode<int>(0, nullptr, nullptr);
    BinaryNode<int>* B = new BinaryNode<int>(0, C, D);
    BinaryNode<int>* E = new BinaryNode<int>(0, nullptr, F);
    BinaryNode<int>* A = new BinaryNode<int>(0, B, E);

    tree.setRoot(A);
    printf("%d", tree.pathLength());
	return 0;
}