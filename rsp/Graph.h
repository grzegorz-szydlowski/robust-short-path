#pragma once

#include <vector>
#include <tuple>

class Graph {
public:
    Graph(int numNodes);
    void addEdge(int u, int v, double cost);
    int getNumNodes() const;
    const std::vector<std::tuple<int, int, double>>& getEdges() const;

private:
    int numNodes;
    std::vector<std::tuple<int, int, double>> edges; // (u, v, cost)
};
