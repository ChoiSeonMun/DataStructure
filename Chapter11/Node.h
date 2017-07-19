#pragma once

#ifndef __NODE_H__
#define __NODE_H__

class Node {
public:
    Node(int id, Node* link = nullptr)
        : id(id), next(link) { }
    ~Node() { if (next) delete next; }

    int     getId() { return id; }
    Node*   getNext() { return next; }
    void    setNext(Node* link) { next = link; }
private:
    int     id;
    Node*   next;
};
#endif