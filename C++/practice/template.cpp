#include <iostream>
using namespace std;
//利用樣板T來自動生成不同的型態(int 、 double..)
template<class T>
class Demo{
    
    public:
        Demo(T a):a(a){ 
        }
        ~Demo(){
            
        }

        T const get(){
            return this->a;
        }
        Demo<T> operator=(Demo<T> const a){
            this->a=a.a;
            return *this;
        }
        Demo<T> &operator+=(Demo<T> const &d){
            this->a=this->a+d.a;
            return *this;                
        }
        Demo<T> &operator+=(T const d){
            this->a=this->a+d;
            return *this;                
        }
        friend bool operator==(const Demo<T> &d,const Demo<T> &e){
            if(d.a==e.a){
                return true ;
            }              
            else return false ;
        }
        friend bool operator!=(const Demo<T> &d,const Demo<T> &e){
            if(d.a==e.a){
                return false ;
            }              
            else return true ;
        }
        friend ostream &operator << (ostream &s,Demo<T> &ob) {
        s<<ob.a;
        return s;
        }
        explicit operator T&(){
            return a;
        }
    
    private:
        T a;
};

template<class T1>
Demo<T1> operator+(const Demo<T1> &c,const Demo<T1> &d){    
    return Demo<T1>(c)+=d;                
}


int main(int argc, char const *argv[]){
    
    Demo<double> a(3.7),b(4.5);
    a+=b;
    cout<<"a="<<a<< endl;
    cout<<"b="<<b<< endl;
    Demo<double> c=a+b;
    cout<<"c="<<c<< endl;
    if(c==Demo<double>(12.7))
        cout<<"O"<<endl;
    if(c!=Demo<double>(8.2))
        cout<<"X"<<endl; 
    double dou=(double)c;
    cout<<"dou="<<dou<< endl;
    return 0;
}