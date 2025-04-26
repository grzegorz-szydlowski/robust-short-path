#include "Graph.h"

Graph::Graph(int numNodes) : numNodes(numNodes) {}

void Graph::addEdge(int u, int v, double cost) {
    edges.emplace_back(u, v, cost);
}

int Graph::getNumNodes() const {
    return numNodes;
}

const std::vector<std::tuple<int, int, double>>& Graph::getEdges() const {
    return edges;
}
