
#include "Aco.h"
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{ 
    Aco tsp(15,100);
    tsp.read(argv[1]);
    tsp.solve();
    tsp.print();
    return 0;
}
