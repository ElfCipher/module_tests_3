#include "solver.h"

const double Solver::e = 1e-5;

std::vector<double> Solver::Solve(double a, double b, double c)
{
    std::vector<double> result;
    if(a < e)
        throw std::exception();

    double d = b*b - 4*a*c;

    if(d < 0.0)
        return result;
    
    return result;
}
