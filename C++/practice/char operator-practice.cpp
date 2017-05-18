#include <iostream>
#include <Cstring>
using namespace std;


class Str {
public:

    Str(const char* t="\0") { //空的預設
        //cout<<t<<endl;
        s=new char[strlen(t)+1] {'\0'};
        strcpy(s,t);
    }
    /*Str(int l=3 ){// 空的預設,Str與前一建構子不知道該選誰
        //cout<<t<<endl;
        s=new char[l];

    }*/
    Str(const Str & A):s(new char[strlen(A.s)+1] {'\0'}) {
        //s=new char[strlen(A.s)+1]{'\0'};
        strcpy(s,A.s);
    }
    ~Str() {
        delete []s;
    }
public:
    Str pri() {
        cout<<"pri s =  ";
        cout<<s<<endl;
        return *this;
    }

    Str resize(int l) {
        len=l;
        char* temp ;
        temp=s;
        s=new char[l+1] {'\0'};
        for(int i = 0; i < l; ++i) {
            s[i]=temp[i];
        }
        delete [] temp;
        return *this;
    }

    Str &operator+=(Str const &a) {
        char* temp=s;
        if(this!=&a) {
            s=new char[strlen(a.s)+strlen(temp)+1] {}; //大括號 一開始\0 (初始化)
            strcat(s,temp);
            strcat(s,a.s);
             
        }
        else { //例外處理(a+=a)
            s=new char[2*strlen(temp)+1] {};
            strcpy(s,temp);
            strcat(s,temp);
        }
        len=strlen(s);
        delete [] temp;
        return *this ;
    }

    Str &operator+=(char const rhs) {//可能為右值，不能參考
        char* temp = s;
        size_t len = strlen(temp)+1;
        s=new char[len+1] {};
        strcat(s, temp);
        s[len-1]=rhs;
        delete [] temp;
        return *this ;
    }
    //將字串加入物件s
    Str &operator+=(char const rhs[]) {
        char* temp = s;
        size_t len = strlen(temp)+strlen(rhs)+1;
        s=new char[len+1] {};
        strcat(s, temp);
        strcat(s, rhs);
        delete [] temp;
        return *this ;
    }
    //複製物件
    Str &operator=(Str const &a) {
        if(this!=&a) {
            this->~Str();//解構子需要this呼叫
            s=new char[strlen(a.s)+1] {'\0'};
            strcpy(s,a.s);
        }
        return *this ;
    }
    //將數值轉成字元返還
    char operator=(int a) {
        return char(a)  ;
    }

    char & operator[](size_t idx) {
        return s[idx];
    }

    const char & operator[](size_t idx)const {//前面的const用來避免修改到值
        return s[idx];
    }

    size_t size() {
        return(strlen(s));
    }
    const size_t size() const {//後面的const是指const屬性呼叫const的函式
        return(strlen(s));
    }

public:
    char* s;
    int len;
    int number;
};
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
//================================================================
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
    return 0;
}
/*==============================================================*/