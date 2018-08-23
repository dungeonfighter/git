
#include "GA.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{ 
    GA tsp(300,300);//人口 世代
    tsp.read(argv[1]);
    tsp.solve();
    tsp.print();
    return 0;
}
