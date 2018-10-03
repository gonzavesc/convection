
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

#ifndef INCLUDE_IN
	#include "initialize.hpp"
	#define INCLUDE_In
#endif

void Set_D(std::vector<double>& D,const std::vector<double>& properties, const std::vector<double>& diff)
{
    D.push_back(properties[1] * diff[1] / diff[0]); D.push_back(properties[1] * diff[1] / diff[0]);
    D.push_back(properties[1] * diff[0] / diff[1]); D.push_back(properties[1] * diff[0] / diff[1]);
}

void Set_F(std::vector<double>& F,const std::vector<double>& properties, const std::vector<double>& diff, const std::vector<double>& Vel)
{
    F.push_back(properties[0] * Vel[0] * diff[1]); F.push_back(properties[0] * Vel[0] * diff[1]);
    F.push_back(properties[0] * Vel[1] * diff[0]); F.push_back(properties[0] * Vel[1] * diff[0]);
}

void Set_P(std::vector<double>& P,const std::vector<double>& D, const std::vector<double>& F)
{
    for (int i = 0; i <= 3; i++)
    {
        P.push_back(F[i] / D[i]);
    }
}