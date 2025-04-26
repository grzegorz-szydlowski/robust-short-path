#pragma once

#include <vector>

class LPSolver {
public:
    LPSolver();

    double solveMaximization(const std::vector<std::vector<double>>& M, const std::vector<double>& b, const std::vector<double>& objective);

private:
    //Todo: zaimplementowac biblioteke solverowa jak np GLPK
};
