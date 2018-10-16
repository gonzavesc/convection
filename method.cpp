#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <cmath>
#include <new>
#include <algorithm>  //std::max
#ifndef INCLUDE_READ
	#include "read.hpp"
	#define INCLUDE_READ
#endif

#ifndef INCLUDE_IN
	#include "initialize.hpp"
	#define INCLUDE_IN
#endif

#ifndef INCLUDE_MET
    #include "method.hpp"
    #define INCLUDE_MET
#endif

void Set_A(double& A, const double& P,const double& Method)
{
    if (Method == 0) //central difference
    {
        A = 1 - 0.5 * std::abs(P);

    }
    if (Method == 1) //Upwind
    {
        A = 1;

    }
    if (Method == 2) //hybrid
    {
        A = std::max(0.0, 1 - 0.5 * std::abs(P));

    }
    if (Method == 3) //Power Law
    {
        A = std::max(0.0, std::pow(1 - 0.1 * std::abs(P), 5));

    }
    if (Method == 4) //Exponential
    {
        A = std::abs(P) / (exp(std::abs(P)) - 1);
        if (P == 0)
        {
            A=1;
        }

    }
}
void Set_a(std::vector<double>& a, const std::vector<double>& D, const std::vector<double>& F, const std::vector<double>& P,const std::vector<double>& properties, const std::vector<double>& diff, const double Steady, const double Method)
{
    double A;
    Set_A(A, P[0], Method); a.push_back(D[0] * A + std::max(0.0, -F[0]));
    Set_A(A, P[1], Method); a.push_back(D[1] * A + std::max(0.0, F[1]));
    Set_A(A, P[2], Method); a.push_back(D[2] * A + std::max(0.0, -F[2]));
    Set_A(A, P[3], Method); a.push_back(D[3] * A + std::max(0.0, F[3]));
    a.push_back(properties[0] * diff[0] * diff[1] / diff[2]);
    a.push_back(a[0] + a[1] + a[2] + a[3] + (1.0-Steady) * a[3]);
}