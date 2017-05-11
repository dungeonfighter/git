#include <iostream>
#include <Cstring>
using namespace std;


class Str{
public:
   
    Str(const char* t="\0"){//�Ū��w�]
        //cout<<t<<endl;
        s=new char[strlen(t)+1]{'\0'};
        strcpy(s,t);
    }
    /*Str(int l=3 ){// �Ū��w�],Str�P�e�@�غc�l�����D�ӿ��
        //cout<<t<<endl;
        s=new char[l];
        
    }*/
    Str(const Str & A ){ 
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
        if(this!=&a){
            char* temp ;
            temp=s;
            s=new char[strlen(a.s)+strlen(temp)+1]{};//�j�A�� �@�}�l\0 (��l��)
            strcat(s,temp);
            strcat(s,a.s);
            delete [] temp;
            len=strlen(s);
        }
        else{ //�ҥ~�B�z(a+=a)
            char* temp=new char[strlen(s)+1]{} ;
            strcpy(temp,s);
            delete []s;
            s=new char[strlen(a.s)+strlen(temp)+1]{};//�j�A�� �@�}�l\0 (��l��)
            strcat(s,temp);
            strcat(s,temp);
            delete [] temp;
            len=strlen(s);
        }
        return *this ;
    }

    Str &operator+=(char const rhs ){//�i�ର�k�ȡA����Ѧ�
        char* temp = s;
        size_t len = strlen(temp)+1;
        s=new char[len+1]{};
        strcat(s, temp);
        s[len-1]=rhs;
        delete [] temp;
        return *this ;
    }
    //�N�r��[�J����s
    Str &operator+=(char const rhs[] ){
        char* temp = s;
        size_t len = strlen(temp)+strlen(rhs)+1;
        s=new char[len+1]{};
        strcat(s, temp);
        strcat(s, rhs);
        delete [] temp;
        return *this ;
    }
    //�ƻs����
    Str &operator=(Str const &a ){
        if(this!=&a){
        this->~Str();//�Ѻc�l�ݭnthis�I�s
        s=new char[strlen(a.s)+1]{'\0'};
        strcpy(s,a.s);
        }
        return *this ;
    }
    //�N�ƭ��ন�r������
    char operator=(int a ){ 
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
    int number;
};
    Str const operator+(Str const &a,Str const &b ){//???
        return Str(a)+=b ;
    }

    ostream &operator << (ostream &s, Str &ob) { 
        s<<"pri s =  "<<ob.s<<endl;
        return s; 
    } 

    istream &operator>>(istream &s, Str &p) { 
    cout << "��J�Ʀr: "; 
    s >> p.number; 
    return s; 
} 
//================================================================
int main(int argc, char const *argv[]){
    cout<<endl;
    Str a="Hello World!";
    Str b=a;
    Str c;
    c=a+b; // c is "Hello World�I" x2
    // // print "Hello World�I" x2
    
    for (int i = 0; i < c.size(); ++i){
        cout << c[i];
        c[i]=(i+65);
    }
    cout << endl;
    c.pri();
    c+="YZ\0";
    //char e[]="YZ";
    //c += e;
    cout << endl;
    c.pri();

    c.resize(3);
    c.pri();
    c.resize(4);
    c+='D';
    cin>>c;
    cout<<c;
   
    return 0;
}
/*==============================================================*/