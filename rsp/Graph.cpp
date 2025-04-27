#include "Graph.h"

Graph::Graph(int n) : numNodes(n), adjList(n) {}

void Graph::addEdge(int u, int v, double cost) {
    adjList[u].emplace_back(v, cost);
}

const std::vector<std::vector<std::pair<int, double>>>& Graph::getAdjacencyList() const {
    return adjList;
}

int Graph::getNumNodes() const {
    return numNodes;
}
