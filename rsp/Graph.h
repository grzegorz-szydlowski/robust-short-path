#pragma once
#include <vector>

class Graph {
public:
    Graph(int n);
    void addEdge(int u, int v, double cost);
    const std::vector<std::vector<std::pair<int, double>>>& getAdjacencyList() const;
    int getNumNodes() const;

private:
    int numNodes;
    std::vector<std::vector<std::pair<int, double>>> adjList;
};
