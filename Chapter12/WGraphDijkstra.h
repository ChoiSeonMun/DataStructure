#pragma once

#ifndef WGraphDijkstra_H
#define WGraphDijkstra_H

#include "WeightedGraph.h"

class WGraphDijkstra : public WeightedGraph {
public:
    int     chooseVertex();
    void    ShortestPath(int start);
    void    printDistance();
private:
    int     dist[MAX_VERTICE];
    bool    found[MAX_VERTICE];
};

inline int WGraphDijkstra::chooseVertex()
{
    int min = INF;
    int minPos = -1;
    for (int i = 0; i < size; ++i)
    {
        if (dist[i] < min && !found[i])
        {
            min = dist[i];
            minPos = i;
        }
    }
    return minPos;
}

inline void WGraphDijkstra::ShortestPath(int start)
{
    for (int i = 0; i < size; ++i)
    {
        dist[i] = getEdge(start, i);
        found[i] = false;
    }
    
    found[start] = true;
    dist[start] = 0;
    for (int i = 0; i < size; ++i)
    {
        printf("Step%2d:", i + 1);
        printDistance();
        int u = chooseVertex();
        found[u] = true;
        for (int w = 0; w < size; ++w)
        {
            if (!found[w])
            {
                if (dist[u] + getEdge(u, w) < dist[w])
                    dist[w] = dist[u] + getEdge(u, w);
            }
        }
    }
}

inline void WGraphDijkstra::printDistance()
{
    for (int i = 0; i < size; ++i)
        printf("%5d", dist[i]);
    puts("");
}
#endif // !WGraphDijkstra_H
