/*****************************************************************
Name : STR������Y��
Date : 2017/05/25
By   : Wun
Final: 2017/05/25
*****************************************************************/
#ifndef CHAR_HPP
#define CHAR_HPP
//#include <iostream> hpp�ɶq���ninclude
//using namespace std;
class Str {
public:

    Str(const char* t="\0") ;
    /*Str(int l=3 ){// �Ū��w�],Str�P�e�@�غc�l�����D�ӿ��
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
    //�N�r��[�J����s
    Str &operator+=(char const rhs[]);
    //�ƻs����
    Str &operator=(Str const &a) ;
    //�N�ƭ��ন�r������
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
