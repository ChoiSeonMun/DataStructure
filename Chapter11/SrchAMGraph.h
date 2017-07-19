#pragma once

#ifndef __SRCHAMGRAPH_H__
#define __SRCHAMGRAPH_H__

#include "AdjMatGraph.h"
#include "CircularQueue.h"

class SrchAMGraph : public AdjMatGraph {
public:
    void    resetVisited();
    bool    isLinked(int vertex1, int vertex2) { return getEdge(vertex1, vertex2); }
    void    DFS(int vertex);
    void    BFS(int vertex);
protected:
    bool    visited[MAX_VERTICE];
};

void SrchAMGraph::resetVisited()
{
    for (int i = 0; i < size; ++i)
        visited[i] = false;
}

void SrchAMGraph::DFS(int vertex)
{
    visited[vertex] = true;
    printf("%c  ", getVertex(vertex));

    for (int i = 0; i < size; ++i)
    {
        if (isLinked(vertex, i) && visited[i] == false)
            DFS(i);
    }
}

void SrchAMGraph::BFS(int vertex)
{
    visited[vertex] = true;
    printf("%c   ", getVertex(vertex));

    CircularQueue que;
    que.enqueue(vertex);

    while (!que.isEmpty())
    {
        int vertex = que.dequeue();
        for (int i = 0; i < size; ++i)
        {
            if (isLinked(vertex, i) && !visited[i])
            {
                visited[i] = true;
                printf("%c   ", getVertex(i));
                que.enqueue(i);
            }
        }
    }
}
#endif