#pragma once

#ifndef __ADJLISTGRAPH_H__
#define __ADJLISTGRAPH_H__

#include "Node.h"
#include <cstdio>

constexpr int MAX_VERTICES = 256;

class AdjListGraph {
public:
    AdjListGraph()
        : size(0), vertices(), adj() { }
    ~AdjListGraph() { reset(); }

    void    reset();
    bool    isEmpty() { return size == 0; }
    bool    isFull() { return size >= MAX_VERTICES; }
    char    getVertex(int idx) { return vertices[idx]; }
    void    insertVertex(char vertex);
    void    deleteVertex(int vertex);
    void    insertEdge(int vertex1, int vertex2);
    void    deleteEdge(int vertex1, int vertex2);
    Node*   adjacent(int vertex) { return adj[vertex]; }
    void    display();
    void    load(char* fileName);
protected:
    int     size;
    char    vertices[MAX_VERTICES];
    Node*   adj[MAX_VERTICES];
};

void AdjListGraph::reset()
{
    for (int i = 0; i < size; ++i)
    {
        if (adj[i])
            delete adj[i];
    }
    size = 0;
}

void AdjListGraph::insertVertex(char vertex)
{
    if (!isFull())
    {
        vertices[size] = vertex;
        adj[size++] = nullptr;
    }
    else
        perror("Error : 그래프 정점 갯수 초과");
}

void AdjListGraph::insertEdge(int vertex1, int vertex2)
{
    adj[vertex1] = new Node(vertex2, adj[vertex1]);
    adj[vertex2] = new Node(vertex1, adj[vertex2]);
}

void AdjListGraph::display()
{
    printf("%d\n", size);
    for (int i = 0; i < size; ++i)
    {
        printf("%c  ", getVertex(i));
        for (Node* vertex = adj[i]; vertex; vertex = vertex->getNext())
            printf("    %c", getVertex(vertex->getId()));
        puts("");
    }
}

void AdjListGraph::load(char * fileName)
{
    FILE* fp;
    fopen_s(&fp, fileName, "r");
    if (fp)
    {
        int num, val;
        fscanf_s(fp, "%d", &num, 1);
        for (int i = 0; i < num; ++i)
        {
            char str[80];
            fscanf_s(fp, "%s", str, (unsigned)_countof(str));
            insertVertex(str[0]);
            for (int j = 0; j < num; ++j)
            {
                fscanf_s(fp, "%d", &val, 1);
                if (val)
                    insertEdge(i, j);
            }
        }
        fclose(fp);
    }
}
#endif