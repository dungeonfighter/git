/*****************************************************************
Name : STR物件標頭檔
Date : 2017/05/25
By   : Wun
Final: 2017/05/25
*****************************************************************/
#ifndef CHAR_HPP
#define CHAR_HPP
//#include <iostream> hpp盡量不要include
//using namespace std;
class Str {
public:

    Str(const char* t="\0") ;
    /*Str(int l=3 ){// 空的預設,Str與前一建構子不知道該選誰
        //cout<<t<<endl;
        s=new char[l];
    }*/
    Str(const Str & A) ;
    ~Str() ;
public:
    Str pri() ;

    Str resize(int l) ;

    Str &operator+=(Str const &a) ;

    Str &operator+=(char const rhs) ;
    //將字串加入物件s
    Str &operator+=(char const rhs[]);
    //複製物件
    Str &operator=(Str const &a) ;
    //將數值轉成字元返還
    char operator=(int a);

    char & operator[](size_t idx) ;

    const char & operator[](size_t idx)const ;

    size_t size() ;
    const size_t size() const ;

public:
    char* s;
    int len;
    int number;
};
Str const operator+(Str const &a,Str const &b);

std::ostream &operator << (std::ostream &s,Str &ob);

std::istream &operator>>(std::istream &s, Str &p);


#endif // CHAR_HPP
