/*****************************************************************
Name : str�����@ 
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


    Str::Str(const char* t) { //�Ū��w�]
        //cout<<t<<endl;
        s=new char[strlen(t)+1] ;//{'\0'}
        strcpy(s,t);
    }
    /*Str(int l=3 ){// �Ū��w�],Str�P�e�@�غc�l�����D�ӿ��
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
        strcpy(s,temp);//�Ĥ@�����n�α����A�|���U����
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
    //�N�r��[�J����s
    Str &Str::operator+=(char const rhs[]) {
        char* temp = s;
        size_t len = strlen(temp)+strlen(rhs)+1;
        s=new char[len+1] {};
        strcat(s, temp);
        strcat(s, rhs);
        delete [] temp;
        return *this ;
    }
    //�ƻs����
    Str &Str::operator=(Str const &a) {
        if(this!=&a) {
            this->~Str();//�Ѻc�l�ݭnthis�I�s
            s=new char[strlen(a.s)+1] {'\0'};
            strcpy(s,a.s);
        }
        return *this ;
    }
    //�N�ƭ��ন�r������
    char Str::operator=(int a) {
        return char(a)  ;
    }

    char & Str::operator[](size_t idx) {
        return s[idx];
    }

    const char & Str::operator[](size_t idx)const {//�e����const�Ψ��קK�ק���
        return s[idx];
    }

    size_t Str::size() {
        return(strlen(s));
    }
    const size_t Str::size() const {//�᭱��const�O��const�ݩʩI�sconst���禡
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
    cout << "��J�Ʀr: ";
    s >> p.number;
    return s;
}