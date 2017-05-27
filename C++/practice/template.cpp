#include <iostream>
using namespace std;

template<class T>
class Demo{
    
    public:
        Demo(T a):a(a){ 
        }
        ~Demo(){
            
        }

        T const pri(){
            return this->a;
        }
        Demo operator=(Demo const a){
            this->a=a.a;
            return *this;
        }
        Demo &operator+=(Demo const &d){
            this->a=this->a+d.a;
            return *this;                
        }
        Demo &operator+=(T const d){
            this->a=this->a+d;
            return *this;                
        }
    private:
        T a;
};

template<class T>
//為什麼可以?
T const operator+(T const &c,T const &d){    
    return T(c)+=d;                
}

/* 
為什麼不行?
Demo operator+(Demo &c , Demo &d){
            return Demo(c)+d;                
        }
*/

int main(int argc, char const *argv[]){
    
    Demo<double> a(30);
    Demo<double> b(40);
    a=a+b;
    cout<<"a=" <<a.pri() << endl;
    a+=50;
    cout<<"a=" <<a.pri() << endl;
    a+=a;
    cout<<"a=" <<a.pri() << endl;
    return 0;
}