#include <vector>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>
#include "function.h"
using namespace std;

typedef std::vector<std::vector<double>> vec2;

bool ZDT1(vector<double> &s, vector<double> &r)
{ // solution and f1 f2

    if (s.size() < 2 || r.size() < 2)
        return false;

    double f1 = s[0];
    double g = 0;
    double temp = 0;
    for (size_t i = 1; i < s.size(); i++)
    {
        temp += s[i];
    }

    g = 1.0 + 9.0 / (s.size() - 1) * temp;
    double f2 = g * (1.0 - sqrt(f1 / g) );
    r[0] = f1;
    r[1] = f2;

    return true;
}