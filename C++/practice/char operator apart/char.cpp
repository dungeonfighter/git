/*****************************************************************
Name : str物件實作 
Date : 2017/05/25
By   : Wun
Final: 2017/05/25
*****************************************************************/
#include <iostream>
#include "char.hpp"
#include <cstring>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;


    Str::Str(const char* t) { //空的預設
        //cout<<t<<endl;
        s=new char[strlen(t)+1] ;//{'\0'}
        strcpy(s,t);
    }
    /*Str(int l=3 ){// 空的預設,Str與前一建構子不知道該選誰
        //cout<<t<<endl;
        s=new char[l];
    }*/
    Str::Str(const Str & A):s(new char[strlen(A.s)+1] ) {//{'\0'}
        //s=new char[strlen(A.s)+1]{'\0'};
        strcpy(s,A.s);
    }
    Str::~Str() {
        delete []s;
    }

    Str Str::pri() {
        cout<<"pri s =  ";
        cout<<s<<endl;
        return *this;
    }

    Str Str::resize(int l) {
        
        char* temp ;
        temp=s;
        s=new char[l+1] ;
        s[l]='\0';
        for(int i = 0; i < l; ++i) {
                s[i]=temp[i];
        }
        delete [] temp;
        len=l;
        return *this;
    }

    Str &Str::operator+=(Str const &a) {
        char* temp=s;
        len=strlen(a.s)+strlen(temp);
        s=new char[len+1] ; 
        s[len]='\0';
        strcpy(s,temp);//第一次不要用接的，會有垃圾值
        this!=&a?strcat(s,a.s):strcat(s,temp);           
        len=strlen(s);
        delete [] temp;
        return *this ;
    }

    Str &Str::operator+=(char const rhs) {
        char* temp = s;
        size_t len = strlen(temp)+1;
        s=new char[len] ;
        //s[len-1]='\0';
        strcpy(s, temp);
        s[len-1]=rhs;
        delete [] temp;
        return *this ;
    }
    //將字串加入物件s
    Str &Str::operator+=(char const rhs[]) {
        char* temp = s;
        size_t len = strlen(temp)+strlen(rhs)+1;
        s=new char[len+1] {};
        strcat(s, temp);
        strcat(s, rhs);
        delete [] temp;
        return *this ;
    }
    //複製物件
    Str &Str::operator=(Str const &a) {
        if(this!=&a) {
            this->~Str();//解構子需要this呼叫
            s=new char[strlen(a.s)+1] {'\0'};
            strcpy(s,a.s);
        }
        return *this ;
    }
    //將數值轉成字元返還
    char Str::operator=(int a) {
        return char(a)  ;
    }

    char & Str::operator[](size_t idx) {
        return s[idx];
    }

    const char & Str::operator[](size_t idx)const {//前面的const用來避免修改到值
        return s[idx];
    }

    size_t Str::size() {
        return(strlen(s));
    }
    const size_t Str::size() const {//後面的const是指const屬性呼叫const的函式
        return(strlen(s));
    }

    
    

    Str const operator+(Str const &a,Str const &b) {//???
        return Str(a)+=b ;
    }

ostream &operator << (ostream &s,Str &ob) {
    s<<"pri s =  "<<ob.s<<endl;
    return s;
}

istream &operator>>(istream &s, Str &p) {
    cout << "輸入數字: ";
    s >> p.number;
    return s;
}