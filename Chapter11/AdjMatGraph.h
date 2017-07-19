#pragma once

#ifndef __ADJMATGRAPH_H__
#define __ADJMATGRAPH_H__

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>

constexpr int MAX_VERTICE = 256;

class AdjMatGraph {
public:
    AdjMatGraph()
        : size(0), vertices(), adj() { }

    bool    isEmpty() { return size == 0; }
    bool    isFull() { return size >= MAX_VERTICE; }
    char    getVertex(int idx) { return vertices[idx]; }
    int     getEdge(int row, int col) { return adj[row][col]; }
    void    setEdge(int row, int col, int val) { adj[row][col] = val; }
    void    insertVertex(char vertex);
    void    deleteVertex(int vertex);
    void    insertEdge(int u, int v);
    void    deleteEdge(int u, int v);
    int*    adjacent(int v);
    void    display(FILE* fp = stdout);
    void    reset();
    void    load(char* filaName);
    void    store(char* fileName);
    //Problem Program Project 1-1
    void    randomGraph(int numVetex, int numEdge);
protected:
    int     size;
    char    vertices[MAX_VERTICE];
    int     adj[MAX_VERTICE][MAX_VERTICE];
};

void AdjMatGraph::insertVertex(char vertex)
{
    if (!isFull())
        vertices[size++] = vertex;
    else
        perror("Error : 그래프 정점 갯수 초과");
}

void AdjMatGraph::insertEdge(int u, int v)
{
    setEdge(u, v, 1);
    setEdge(v, u, 1);
}

void AdjMatGraph::display(FILE* fp)
{
    fprintf(fp, "%d\n", size);
    for (int r = 0; r < size; ++r)
    {
        fprintf(fp, "%c  ", getVertex(r));
        for (int c = 0; c < size; ++c)
            fprintf(fp, " %3d", getEdge(r, c));
        fprintf(fp, "\n");
    }
}

void AdjMatGraph::reset()
{
    size = 0;
    memset(vertices, 0, sizeof(char) * MAX_VERTICE);
    memset(adj, 0, sizeof(int) * MAX_VERTICE * MAX_VERTICE);
}

void AdjMatGraph::load(char* fileName)
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

void AdjMatGraph::store(char * fileName)
{
    FILE* fp;
    fopen_s(&fp, fileName, "w");
    if (fp)
    {
        display(fp);
        fclose(fp);
    }
}

void AdjMatGraph::randomGraph(int numVertex, int numEdge)
{
    srand(time(0));
    for (int i = 0; i < numVertex; ++i)
        insertVertex('A' + i);
    
    int randomVertex1, randomVertex2;
    int i = 0;
    while (i != numEdge)
    {
        randomVertex1 = rand() % size;
        randomVertex2 = rand() % size;
        if (randomVertex1 != randomVertex2 && adj[randomVertex1][randomVertex2] == 0)
        {
            setEdge(randomVertex1, randomVertex2, 1);
            ++i;
        }
    }
}
#endif