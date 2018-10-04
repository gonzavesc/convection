#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <cmath>
#include <new>

#ifndef INCLUDE_READ
	#include "read.hpp"
	#define INCLUDE_READ
#endif

namespace test{
	extern int Nx, Ny;
}


void Set_Phi(std::vector<std::vector<double>>& phi);
void Set_Phip(std::vector<std::vector<double>>& phi_p, const std::vector<std::vector<double>>& phi);
void Set_D(std::vector<double>& D,const std::vector<double>& properties, const std::vector<double>& diff);
void Set_F(std::vector<double>& F,const std::vector<double>& properties, const std::vector<double>& diff, const std::vector<double>& Vel);
void Set_P(std::vector<double>& P,const std::vector<double>& D, const std::vector<double>& F);