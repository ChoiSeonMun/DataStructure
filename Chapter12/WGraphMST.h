#pragma once

#ifndef WGraphMST_H
#define WGraphMST_H

#include "MinHeap.h"
#include "WeightedGraph.h"
#include "VertexSets.h"

struct WGraphMST : public WeightedGraph {
    void    Kruskal();
    void    Prim(int s);
    int     getMinVertex(bool* selected, int* dist);
};

inline void WGraphMST::Kruskal()
{
    MinHeap heap;
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (hasEdge(i, j))
                heap.insert(getEdge(i, j), i, j);
        }
    }

    VertexSets set(size);
    int edgeAccepted = 0;
    while (edgeAccepted < size - 1)
    {
        HeapNode& e = heap.remove();
        int uset = set.findSet(e.getVertex1());
        int vset = set.findSet(e.getVertex2());
        if (uset != vset)
        {
            printf("간선 추가 : %c - %c (비용:%d)\n", getVertex(e.getVertex1()), getVertex(e.getVertex2()), e.getKey());
            set.unionSets(uset, vset);
            ++edgeAccepted;
        }
    }
}

inline void WGraphMST::Prim(int s)
{
    bool selected[MAX_VERTICE];
    int dist[MAX_VERTICE];

    for (int i = 0; i < size; ++i)
    {
        dist[i] = INF;
        selected[i] = false;
    }
    dist[s] = 0;

    for (int i = 0; i < size; ++i)
    {
        int u = getMinVertex(selected, dist);
        selected[u] = true;
        if (dist[u] == INF)
            return;
        printf("%c ", getVertex(u));
        for (int v = 0; v < size; ++v)
        {
            if (getEdge(u, v) != INF)
            {
                if (!selected[v] && getEdge(u, v) < dist[v])
                    dist[v] = getEdge(u, v);
            }
        }
    }
    puts("");
}

inline int WGraphMST::getMinVertex(bool * selected, int * dist)
{
    int minVertex = 0;
    int minDist = INF;
    for (int v = 0; v < size; ++v)
    {
        if (!selected[v] && dist[v] < minDist)
        {
            minDist = dist[v];
            minVertex = v;
        }
    }
    return minVertex;
}
#endif