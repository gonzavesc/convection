#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <cmath> //std::pow abs
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

#ifndef INCLUDE_GAUSS
    #include "gauss.hpp"
    #define INCLUDE_GAUSS
#endif

#ifndef INCLUDE_EXP
    #include "export.hpp"
    #define INCLUDE_EXP
#endif

int main()
{
    std::vector<double> v, Vel, D, F, P, a;
    std::vector<double> properties,diff;
    double Steady, Method;
    int Nx, Ny;
    v = readfiledat();
    properties.push_back(v[0]); properties.push_back(v[1]);
    diff.push_back(v[6]); diff.push_back(v[7]); diff.push_back(v[8]);
    Nx = v[4] / diff[0]; Ny = v[5] / diff[1];
    std::vector<std::vector<double>> phi(Ny + 1, std::vector<double>(Nx +1, 0));
    std::vector<std::vector<double>> phi_p(Ny + 1, std::vector<double>(Nx +1, 0));
    Vel.push_back(v[2]); Vel.push_back(v[3]);
    Steady = v[10]; Method = v[11];
    Set_Phi(phi, Nx, Ny);
    Set_Phip(phi_p,phi,Nx,Ny);
    Set_D(D, properties, diff);
    Set_F(F, properties, diff, Vel);
    Set_P(P, D, F);
    Set_a(a, D, F, P, properties, diff, Steady, Method);
    if (Steady == 0){

    }
    if (Steady == 1){
        Gauss_seidel(phi,a, Nx,Ny);
    }
    exportarMatriu(phi, Nx, Ny);
    return 0;
}
