#pragma once

#ifndef __SRCHAJGRAPH_H__
#define __SRCHAJGRAPH_H__

#include "AdjListGraph.h"
#include "CircularQueue.h"

class SrchAJGraph : public AdjListGraph {
public:
    void    resetVisited();
    bool    isLinked(int vertex1, int vertex2);
    void    DFS(int vertex);
    void    BFS(int vertex);
private:
    bool    visited[MAX_VERTICES];
};

void SrchAJGraph::resetVisited()
{
    for (int i = 0; i < size; ++i)
        visited[i] = false;
}

bool SrchAJGraph::isLinked(int vertex1, int vertex2)
{
    for (Node* current = adj[vertex1]; current; current = current->getNext())
    {
        if (current->getId() == vertex2)
            return true;
    }

    return false;
}

void SrchAJGraph::DFS(int vertex)
{
    visited[vertex] = true;
    printf("%c  ", getVertex(vertex));

    for (Node* current = adj[vertex]; current; current = current->getNext())
    {
        if (visited[current->getId()] == false)
            DFS(current->getId());
    }
}

void SrchAJGraph::BFS(int vertex)
{
    visited[vertex] = true;
    printf("%c  ", getVertex(vertex));

    CircularQueue que;
    que.enqueue(vertex);
    while (!que.isEmpty())
    {
        int vertex = que.dequeue();
        for (Node* current = adj[vertex]; current; current = current->getNext())
        {
            int id = current->getId();
            if (!visited[id])
            {
                visited[id] = true;
                printf("%c", getVertex(id));
                que.enqueue(id);
            }
        }
    }
}

#endif