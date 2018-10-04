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

void Gauss_seidel(std::vector<std::vector<double>>& phi,const  std::vector<double>& a)
{
    double rms, err, prev;
    int i,j, N;
    err = 1e-7;
    rms = 1 + err;
    N = test::Nx * test::Ny;
    while(rms > err)
    {
        rms = 0;
        for (i = 1; i <= test::Ny - 1; i++)
        {
            for(j = 1; j <= test::Nx -1; j++)
            {
                prev = phi[i][j];
                phi[i][j] = (a[0] * phi[i][j+1] + a[1] * phi[i][j-1] + a[2] * phi[i+1][j] + a[3] * phi[i-1][j]) / a[5];
                rms = rms + (phi[i][j] - prev) * (phi[i][j] - prev);
            }
        }
        for(j = 1; j <= test::Nx -1; j++)
        {
                prev = phi[0][j];
                phi[0][j] = phi[1][j]; 
                rms = rms + (phi[0][j] - prev) * (phi[0][j] - prev);
                prev = phi[test::Ny][j];
                phi[test::Ny][j] = phi[test::Ny-1][j]; 
                rms = rms + (phi[test::Ny][j] - prev) * (phi[test::Ny][j] - prev);
        }
        rms = sqrt(rms/N);
        std::cout << rms << std::endl;
    }
}