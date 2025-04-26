#pragma once

#include <vector>
//M×c<=b - wzor ograniczenia (M - wspolczynnik, c - koszt polaczenia miedzy wezlami grafu, b - zadana maksymalna wartosc ograniczenia)
//Polytope - obszar spelniajacy nierownosci ograniczen
class Polytope {
public:
    Polytope();

    void addConstraint(const std::vector<double>& coefficients, double rhs);

    const std::vector<std::vector<double>>& getConstraints() const;
    const std::vector<double>& getConstraintValue() const;

private:
    std::vector<std::vector<double>> M; // Wspolczynniki
    std::vector<double> constraints;              // Wartosci b 
};
