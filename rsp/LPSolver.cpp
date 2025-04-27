#include "LPSolver.h"

LPSolver::LPSolver(Graph* graph, const std::vector<std::vector<double>>& PF)
    : graph(graph), PF(PF), objectiveValue(0.0) {}

void LPSolver::solve() {
    // Symulacja: wybierz "prymitywne" rozwi¹zanie
    binarySolution = { 1, 1, 0, 1, 1 }; // Wybrane "krawêdzie" aktywne
    objectiveValue = 11.0; // Symulowana wartoœæ funkcji celu (z)
}

double LPSolver::getObjectiveValue() const {
    return objectiveValue;
}

std::vector<int> LPSolver::getBinarySolution() const {
    return binarySolution;
}
