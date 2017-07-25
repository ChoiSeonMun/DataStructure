#pragma once

#ifndef WeightedGraph_H
#define WeightedGraph_H

#include "AdjMatGraph.h"

constexpr int INF = 9999;

struct WeightedGraph : public AdjMatGraph {
    void    insertEdge(int u, int v, int weight);
    bool    hasEdge(int r, int c) { return getEdge(r, c) < INF; }
    void    load(char* fileName) override;
};

void WeightedGraph::insertEdge(int u, int v, int weight)
{
    if (weight > INF)
        weight = INF;
    setEdge(u, v, weight);
    setEdge(v, u, weight);
}

void WeightedGraph::load(char * fileName)
{
    FILE* fp;
    fopen_s(&fp, fileName, "r");
    if (fp)
    {
        int num, val;
        fscanf_s(fp, "%d", &num);
        for (int i = 0; i < num; ++i)
        {
            char str[80];
            fscanf_s(fp, "%s", str, (unsigned)_countof(str));
            insertVertex(str[0]);
            for (int j = 0; j < num; ++j)
            {
                fscanf_s(fp, "%d", &val);
                insertEdge(i, j, val);
            }
        }
        fclose(fp);
    }
}
#endif