#include <iostream>
#include "Graph.h"
#include "Polytope.h"
#include "RobustSolver.h"

int main() {
    std::cout << "Robust Shortest Path Project Starting..." << std::endl;

    Graph g(5); // 5 wezlow
    g.addEdge(0, 1, 5.0);
    g.addEdge(1, 2, 3.0);
    g.addEdge(0, 3, 2.0);
    g.addEdge(3, 4, 1.0);
    g.addEdge(4, 2, 2.0);

    Polytope polytope;

    RobustSolver solver(g, polytope);
    solver.solve();

    return 0;
}
