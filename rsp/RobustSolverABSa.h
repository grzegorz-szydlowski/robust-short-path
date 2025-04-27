#pragma once
#include "Graph.h"
#include "Polytope.h"
#include <vector>

class RobustSolverABSa {
public:
    RobustSolverABSa(Graph* g, Polytope* p);
    void solve();
    double getOptimalValue() const;
    std::vector<int> getSolution() const;

private:
    Graph* graph;
    Polytope* polytope;
    double optimalValue;
    std::vector<int> solution;

    bool isDuplicate(const std::vector<std::vector<double>>& PF_psi, const std::vector<double>& c_psi);
};
