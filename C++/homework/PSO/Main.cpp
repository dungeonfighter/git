#include "PSO.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{ 
    //Rastrigin function
    PSO test(25 , 1.5 , 1.5 , 2 , 2);//粒子數 參數 維度
    test.run();
    test.print();
    return 0;
}
