#include <iostream>
#include "Graph.h"
#include "Polytope.h"
#include "RobustSolverABSa.h"

int main() {
    std::cout << "Robust Shortest Path Project Starting..." << std::endl;

    Graph g(5);
    g.addEdge(0, 1, 5.0);
    g.addEdge(1, 2, 3.0);
    g.addEdge(0, 3, 2.0);
    g.addEdge(3, 4, 1.0);
    g.addEdge(4, 2, 2.0);

    Polytope polytope;

    RobustSolverABSa solver(&g, &polytope);
    solver.solve();

    std::cout << "Optymalna wartosc (z): " << solver.getOptimalValue() << std::endl;
    std::cout << "Optymalne rozwiazanie (y): ";
    for (int val : solver.getSolution()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Algorytm ABSa - zakonczono" << std::endl;
    return 0;
}
