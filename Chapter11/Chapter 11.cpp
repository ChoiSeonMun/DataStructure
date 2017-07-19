#include "ConnectedComponentGraph.h"

int main()
{
    ConnectedComponentGraph graph;

    graph.randomConnectedGraph(5);
    graph.resetVisited();
    graph.findConnectedComponent();
    
    return 0;
}