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
	#define INCLUDE_In
#endif

#ifndef INCLUDE_MET
    #include "method.hpp"
    #define INCLUDE_MET
#endif

void Gauss_seidel(std::vector<std::vector<double>>& phi,const  std::vector<double>& a, const int& Nx, const int& Ny);