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

void Set_D(std::vector<double>& D,const std::vector<double>& properties, const std::vector<double>& diff);
void Set_F(std::vector<double>& F,const std::vector<double>& properties, const std::vector<double>& diff, const std::vector<double>& Vel);
void Set_P(std::vector<double>& P,const std::vector<double>& D, const std::vector<double>& F);