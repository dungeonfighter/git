#include <iostream>
#include "ninefouros.h"
using namespace std;

int main(int argc, char *argv[])
{
    argc=1;
    string a=argv[0];
    NineFourOS test;
    //test.output_data();//沒測資再啟用
    while(argc){
        test.sel();
        test.reset();
    }
    return 0;
}
