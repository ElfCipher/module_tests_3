#pragma once

#include <iostream>
#include <vector>

class Solver {
public:
    static const double e;
    // may throw exception
    static std::vector<double> Solve(double a, double b = 0.0, double c = 0.0);
};