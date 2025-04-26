#include "Polytope.h"

Polytope::Polytope() {}

void Polytope::addConstraint(const std::vector<double>& coefficients, double b) {
    M.push_back(coefficients);
    constraints.push_back(b);
}

const std::vector<std::vector<double>>& Polytope::getConstraints() const {
    return M;
}

const std::vector<double>& Polytope::getConstraintValue() const {
    return constraints;
}
