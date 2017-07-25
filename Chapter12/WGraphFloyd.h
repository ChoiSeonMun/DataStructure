#pragma once

#ifndef WGraphFloyd_H
#define WGraphFloyd_H

#include "WeightedGraph.h"

class WGraphFloyd : public WeightedGraph {
public:
    void    shortestPathFloyd();
    void    printA();
private:
    int     A[MAX_VERTICE][MAX_VERTICE];
};

inline void WGraphFloyd::shortestPathFloyd()
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            for (int k = 0; k < size; ++k)
            {
                if (A[i][k] + A[k][j] < A[i][j])
                    A[i][j] = A[i][k] + A[k][j];
                printA();
            }
        }
    }
}

inline void WGraphFloyd::printA()
{
    puts("=====================================");
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (A[i][j] == INF)
                printf("  INF  ");
            else
                printf("%4d ", A[i][j]);
        }
        puts("");
    }
}
#endif // !WGraphFloyd_H
