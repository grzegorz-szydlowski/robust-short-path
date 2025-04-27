#pragma once
#include <vector>
#include "Graph.h"

class LPSolver {
public:
    LPSolver(Graph* graph, const std::vector<std::vector<double>>& PF);
    void solve();
    double getObjectiveValue() const;
    std::vector<int> getBinarySolution() const;

private:
    Graph* graph;
    const std::vector<std::vector<double>>& PF;
    double objectiveValue;
    std::vector<int> binarySolution;
};
