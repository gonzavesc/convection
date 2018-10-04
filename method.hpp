#include <iostream>
#include <fstream>
#include <vector>
#include <string> 
#include <cmath>//std::pow abs
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

void Set_A(double& A, const double& P,const double& Method);
void Set_a(std::vector<double>& a, const std::vector<double>& D, const std::vector<double>& F, const std::vector<double>& P,const std::vector<double>& properties, const std::vector<double>& diff, const double Steady, const double Method);