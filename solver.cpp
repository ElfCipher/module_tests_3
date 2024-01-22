#include "solver.h"
#include <math.h>

const double Solver::e = 1e-5;

std::vector<double> Solver::Solve(double a, double b, double c)
{
    std::vector<double> result;
    if(abs(a) < e)
        throw std::exception();
    if(isnan(a) || isnan(b) || isnan(c) ||
       isinf(a) || isinf(b) || isinf(c))
        throw std::exception();

    double d = b*b - 4*a*c;

    if(d < 0.0)
        return result;
    else if(abs(d) < e) // равно 0
    {
        double root = -b/(2*a);
        result.push_back(root);
    }
    else if(d > 0.0)
    {
        double sqrD2a = sqrt(d)/(2*a);
        double b2a = -b/(2*a);
        
        double root = b2a + sqrD2a;
        result.push_back(root);
        root = b2a - sqrD2a;
        result.push_back(root);
    }
    
    return result;
}
