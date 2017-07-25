#pragma once

#ifndef HeapNode_H
#define HeapNode_H

#include <cstdio>

class HeapNode {
public:
    HeapNode() = default;
    HeapNode(int key, int vertex1, int vertex2)
        : key(key), vertex1(vertex1), vertex2(vertex2) { }

    void    setKey(int key) { this->key = key; }
    void    set(int k, int v1, int v2) { key = k; vertex1 = v1; vertex2 = v2; }
    int     getKey() { return key; }
    int     getVertex1() { return vertex1; }
    int     getVertex2() { return vertex2; }
private:
    int     key;
    int     vertex1;
    int     vertex2;
};
#endif // !HeapNode_H
