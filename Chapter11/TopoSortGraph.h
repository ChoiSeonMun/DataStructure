#pragma once

#ifndef TopoSortGraph_H
#define TopoSortGraph_H

#include "AdjListGraph.h"
#include "ArrayStack.h"

class TopoSortGraph : public AdjListGraph {
public:
    void    insertDirEdge(int vertex1, int vertex2) { adj[vertex1] = new Node(vertex2, adj[vertex1]); }
    void    TopoSort();
private:
    int     inDeq[MAX_VERTICES];
};

void TopoSortGraph::TopoSort()
{
    for (int i = 0; i < size; ++i)
        inDeq[i] = 0;
    for (int i = 0; i < size; ++i)
    {
        Node* node = adj[i];
        while (node)
        {
            ++inDeq[node->getId()];
            node = node->getNext();
        }
    }

    ArrayStack stack;
    for (int i = 0; i < size; ++i)
    {
        if (!inDeq[i])
            stack.push(i);
    }

    while (!stack.isEmpty())
    {
        int vertex1 = stack.pop();
        printf(" %c ", getVertex(vertex1));
        Node* node = adj[vertex1];
        while (node)
        {
            int vertex2 = node->getId();
            --inDeq[vertex2];
            if (!inDeq[vertex2])
                stack.push(vertex2);
            node = node->getNext();
        }
        puts("");
    }
}
#endif