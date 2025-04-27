#pragma once
#include <vector>

class Polytope {
public:
    Polytope();
    std::vector<double> solveAuxProblem(const std::vector<int>& y);
    double evaluate(const std::vector<double>& c, const std::vector<int>& y);

private:
    std::vector<std::vector<double>> extremePoints;
    int counter;
};
