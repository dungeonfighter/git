#include <iostream>
#include <ninefouros.h>
using namespace std;

int main(int argc, char *argv[])
{
    NineFourOS test;
    while(1){
        test.exec();
        test.reset();
    }
    return 0;
}
