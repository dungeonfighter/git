#ifndef __pfa_h__
#define __pfa_h__
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <random>
#include <time.h>
#include <math.h>
#include "function.h"
typedef std::vector<std::vector<double>> vec2  ;
class PFA
{
public:
	size_t dim = 0;  // dim of solutions
	size_t size = 0; // number of solutions
	size_t fit_dim;  // dim of fitness e.g multi-objective problem
	double max_bound = 0;
	double min_bound = 0;
	size_t iter;  // iteration
	size_t round; // rounds for average
public:
	vec2 solutions;// solutions 
	vec2 fitness;// fitness
	vec2 box;// store some good solutions

public:
	PFA(size_t dim, size_t size, size_t fit_dim, double max_bound, double min_bound, size_t iter, size_t round);
	void initialization();
	int add_to_box();

};

#endif