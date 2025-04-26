#include "RobustSolver.h"
#include <iostream>

RobustSolver::RobustSolver(const Graph& g, const Polytope& polytope)
    : graph(g), polytope(polytope) {}

void RobustSolver::solve() {
    std::cout << "Solving robust shortest path" << std::endl;
    // Todo: implementacja algorytm�w ABSa ABSb i RD
}
