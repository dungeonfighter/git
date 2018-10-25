#include <iostream>
#include "ninefouros.h"
using namespace std;

int main(int argc, char *argv[])
{
    argc=1;//消警告用
    string a=argv[0];
    NineFourOS test;
    //test.output_data();//沒測資再啟用
    while(argc){
        test.sel();//選擇(含執行)
        test.reset();//重置
    }
    return 0;
}
