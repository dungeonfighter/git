#include <iostream>
#include <Cstring>
using namespace std;
/*==============================================================*/
#include <iostream>
using namespace std;

class Str{
public:
   
    Str(const char* t="\0"){//空的預設
    	//cout<<t<<endl;
    	s=new char[strlen(t)+1]{'\0'};
        strcpy(s,t);
    }
    /*Str(int l=3 ){// 空的預設,Str與前一建構子不知道該選誰
        //cout<<t<<endl;
        s=new char[l];
        
    }*/
    Str(const Str & A ){//why &
        
        s=new char[strlen(A.s)+1]{'\0'};
        strcpy(s,A.s);
    }
    ~Str(){
        delete []s;
    }
public:
    Str pri(){
        cout<<"pri s =  ";
        cout<<s<<endl;

        return *this;
    }
    
    Str resize(int l){
        len=l;
        char* temp ;
        temp=s;
        s=new char[l+1]{'\0'};
        for(int i = 0; i < l; ++i) {
            s[i]=temp[i];
        }
        delete [] temp;
        return *this;
    }
    
    Str &operator+=(Str const &a ){
        char* temp ;
        temp=s;
        s=new char[strlen(a.s)+strlen(temp)+1]{'\0'};//大括號 一開始\0 (初始化)
        strcat(s,temp);
        strcat(s,a.s);
        delete [] temp;
        len=strlen(a.s)+strlen(temp)+1;
        return *this ;
    }
    Str &operator+=(char a ){
        for(int i = 0; i < len; ++i) {
            if(s[i]==NULL){
                s[i]=a;
            }
        }
        
        return *this ;
    }

    Str &operator=(Str const &a ){
        this->~Str();//解構子需要this呼叫
        s=new char[strlen(a.s)+1]{'\0'};
        strcpy(s,a.s);
        return *this ;
    }
    char operator=(int a ){//???
        
        return char(a)  ;
    }

    char & operator[](size_t idx){
        return s[idx];
    }

    int size(){

        return(strlen(s));
    }

public:
    char* s;
    int len;
};
    Str operator+(Str const &a,Str const &b ){
        return Str(a)+=b ;
    }
//================================================================
int main(int argc, char const *argv[]){
    Str a="Hello World!";
    Str b=a;
    Str c;
    c=a+b; // c is "Hello World！" x2
    // print "Hello World！" x2
    
    for (int i = 0; i < c.size(); ++i){
        cout << c[i];
        c[i]=(i+65);
    }c += "\n\0";//???
    cout << endl;
    c.pri();

    c.resize(3);
    c.pri();
    c.resize(4);
    c+='D';
    c.pri();
    return 0;
}
/*==============================================================*/