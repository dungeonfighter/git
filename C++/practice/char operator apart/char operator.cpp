/*****************************************************************
Name : 
Date : 2017/05/25
By   : Wun
Final: 2017/05/25
*****************************************************************/
#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include <vector>
#include "char.hpp"
//#include "char.cpp"
using namespace std;
int main(int argc, char const *argv[]) {
    Str a="Hello World!";
    Str b=a;
    Str c;
    c = a+b; // c is "Hello World!Hello World!"
    
    for(unsigned i = 0; i < c.size(); ++i) {
        cout << c[i];
        c[i] = (i+65);
    } c += "YZ\n\0";
    cout << endl;
    cout << c << endl;

    c.resize(3);
    cout << c << endl;
    c.resize(4);
    c += 'D';
    cout << c << endl;
    c += c;

    const Str& d=c;
    for(unsigned i = 0; i < d.size(); ++i) {
           cout << d[i];
    } cout << endl;
    
    //char* ss=(char*)a;
	system("pause");
    return 0;
}
//shift del 砍一整行
//shift+up/down 上下選行
//shift+home 游標回到該行最前面
//ctrl+x 剪下(一整行)
//ctrl+d 選一樣的
//強制轉型也是一種呼叫函式