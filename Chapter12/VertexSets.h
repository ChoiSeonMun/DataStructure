#pragma once

#ifndef VertexSets_H
#define Vertexsets_H

constexpr int MAX_VERTICES = 256;

class VertexSets {
public:
    VertexSets(int numSet);

    bool    isRoot(int idx) { return parent[idx] < 0; }
    int     findSet(int vertex);
    void    unionSets(int set1, int set2);
private:
    int     parent[MAX_VERTICES];
    int     nSets;
};

inline VertexSets::VertexSets(int numSet)
    : nSets(numSet)
{
    for (int i = 0; i < nSets; ++i)
        parent[i] = -1;
}

inline int VertexSets::findSet(int vertex)
{
    while (!isRoot(vertex))
        vertex = parent[vertex];

    return vertex;
}

inline void VertexSets::unionSets(int set1, int set2)
{
    parent[set1] = set2;
    --nSets;
}
#endif