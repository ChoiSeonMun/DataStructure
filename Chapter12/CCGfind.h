#pragma once
#pragma once

#ifndef CCGfind_H
#define CCGfind_H

#include "Chapter11\ConnectedComponentGraph.h"

class CCGfind : public ConnectedComponentGraph {
public:
    CCGfind()
        : bridges(0), count(0), pre(), low() { }

private:
    void    dfs(int u, int v);

    int     bridges;
    int     count;
    int     pre[MAX_VERTICE];
    int     low[MAX_VERTICE];
};

void CCGfind::dfs(int u, int v)
{
    pre[v] = ++count;
    low[v] = pre[v];
    for (int w = 0; )
}
#endif // !CCGfind_H
