#include "Polytope.h"

Polytope::Polytope() {
    extremePoints.push_back({ 1.0, 2.0, 0.5, 1.5, 2.5 });
    extremePoints.push_back({ 2.0, 1.0, 1.5, 1.0, 1.5 });
    extremePoints.push_back({ 1.5, 1.5, 1.0, 2.0, 1.0 });
    extremePoints.push_back({ 2.5, 0.5, 2.0, 1.0, 2.0 });
    counter = 0;
}

std::vector<double> Polytope::solveAuxProblem(const std::vector<int>& y) {
    std::vector<double> point = extremePoints[counter % extremePoints.size()];
    counter++;
    return point;
}

double Polytope::evaluate(const std::vector<double>& c, const std::vector<int>& y) {
    double result = 0.0;
    for (size_t i = 0; i < c.size() && i < y.size(); ++i) {
        result += c[i] * y[i];
    }
    return result;
}
