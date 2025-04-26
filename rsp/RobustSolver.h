#pragma once

#include "Graph.h"
#include "Polytope.h"

class RobustSolver {
public:
    RobustSolver(const Graph& g, const Polytope& polytope);

    void solve();

private:
    const Graph& graph;
    const Polytope& polytope;
};
