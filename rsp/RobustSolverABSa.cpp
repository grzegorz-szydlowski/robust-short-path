#include "RobustSolverABSa.h"
#include <iostream>
#include <cmath>

RobustSolverABSa::RobustSolverABSa(Graph* g, Polytope* p)
    : graph(g), polytope(p), optimalValue(0.0) {}

bool RobustSolverABSa::isDuplicate(const std::vector<std::vector<double>>& PF_psi, const std::vector<double>& c_psi) {
    for (const auto& point : PF_psi) {
        bool same = true;
        for (size_t i = 0; i < point.size(); ++i) {
            if (fabs(point[i] - c_psi[i]) > 1e-6) {
                same = false;
                break;
            }
        }
        if (same) return true;
    }
    return false;
}

void RobustSolverABSa::solve() {
    int psi = 1;
    const int MAX_ITERATIONS = 50;
    std::vector<std::vector<double>> PF_psi;
    bool stop = false;

    while (!stop && psi <= MAX_ITERATIONS) {
        std::cout << "Iteracja: " << psi << std::endl;

        // Tu robimy bardzo uproszczone LP: minimalizujemy ³¹czn¹ wagê krawêdzi
        double z_psi = 11; // Symulowana sta³a wartoœæ
        std::vector<int> y_psi = { 1, 0, 1, 0, 1 }; // Przykladowe rozwiazanie

        std::vector<double> c_psi = polytope->solveAuxProblem(y_psi);
        double ub_psi = polytope->evaluate(c_psi, y_psi);

        std::cout << "z_" << psi << " = " << z_psi << ", ub_" << psi << " = " << ub_psi << std::endl;

        double min_ub = ub_psi;
        for (const auto& point : PF_psi) {
            double eval = polytope->evaluate(point, y_psi);
            if (eval < min_ub)
                min_ub = eval;
        }

        if (min_ub <= z_psi) {
            optimalValue = z_psi;
            solution = y_psi;
            stop = true;
            std::cout << "Warunek stopu osiagniety na iteracji " << psi << std::endl;
        }
        else {
            if (isDuplicate(PF_psi, c_psi)) {
                std::cout << "Nowy punkt taki sam jak stary. Koncze iteracje." << std::endl;
                break;
            }
            PF_psi.push_back(c_psi);
            psi++;
        }
    }

    if (psi > MAX_ITERATIONS) {
        std::cerr << "Przekroczono maksymalna liczbe iteracji! Algorytm moze nie konwergowac!" << std::endl;
    }
}

double RobustSolverABSa::getOptimalValue() const {
    return optimalValue;
}

std::vector<int> RobustSolverABSa::getSolution() const {
    return solution;
}
