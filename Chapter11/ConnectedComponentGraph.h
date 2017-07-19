#pragma once

#ifndef ConnectedComponentGraph_H
#define ConnectedComponentGraph_H

#include "SrchAMGraph.h"

class ConnectedComponentGraph : public SrchAMGraph {
public:
    void    labelDFS(int vertex, int color);
    void    findConnectedComponent();
    //Problem Program Project 1-3
    void    randomConnectedGraph(int numVertex);
    bool    isAllConnected();
private:
    int     label[MAX_VERTICE];
};

void ConnectedComponentGraph::labelDFS(int vertex, int color)
{
    visited[vertex] = true;
    label[vertex] = color;
    for (int i = 0; i < size; ++i)
    {
        if (isLinked(vertex, i) && !visited[i])
            labelDFS(i, color);
    }
}

void ConnectedComponentGraph::findConnectedComponent()
{
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (!visited[i])
            labelDFS(i, ++count);
    }
    printf("그래프 연결성분 갯수 : %d\n", count);
    for (int i = 0; i < size; ++i)
        printf("%c = %d ", getVertex(i), label[i]);
    puts("");
}

void ConnectedComponentGraph::randomConnectedGraph(int numVertex)
{
    srand(time(0));
    for (int i = 0; i < numVertex; ++i)
        insertVertex('A' + i);

    int startVertex = rand() % size;
    int endVertex;
    while (!isAllConnected())
    {
        endVertex = rand() % size;
        if (startVertex == endVertex)
            continue;
        
        if (!isLinked(startVertex, endVertex))
            insertEdge(startVertex, endVertex);
        
        startVertex = endVertex;
    }
}

bool ConnectedComponentGraph::isAllConnected()
{
    memset(visited, false, sizeof(bool) * MAX_VERTICE); 
    labelDFS(0, 1);
    int count = 0;
    for (int i = 0; i < size; ++i)
    {
        if (visited[i])
            ++count;
    }
    if (count == size)
        return true;
    else
        return false;
}
#endif