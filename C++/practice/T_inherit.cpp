#include <iostream>
using namespace std;

template<class T>
class base{
public:
	base(T a):data(a){}
	virtual ~base(){}
public:
	T data;
public:
	base<T> pri(){
		cout<<this->data<<endl;
		return *this;
	}
	base<T> operator=(base<T> const a){
        this->data=a.data;
        return *this;
    }
    base<T> &operator+=(base<T> const &d){
        this->data=this->data+d.data;
        return *this;                
    }
    base<T> &operator-=(base<T> const &d){
        this->data=this->data-d.data;
        return *this;                
    }
    base<T> &operator*=(base<T> const &d){
        this->data=this->data*d.data;
        return *this;                
    }

    
};

template<class T2>
ostream &operator << (ostream &s, base<T2> &ob) {
    s<<ob.data;
    return s;
}

template<class T>
base<T> operator+(const base<T> &c,const base<T> &d){    
    return base<T>(c)+=d;                
}
template<class T>
base<T> operator-(const base<T> &c,const base<T> &d){    
    return base<T>(c)-=d;                
}
template<class T>
base<T> operator*(const base<T> &c,const base<T> &d){    
    return base<T>(c)*=d;                
}

class base_int:public base<int>{
public:
	base_int(int a):base(a){}
private:
	int data;
};

class base_double:public base<double>{
public:
	base_double(double a):base(a){}
private:
	double data;
};

/*==============================================================*/
int main(int argc, char const *argv[]){

	base_int a(5),b(88);
	
	base_int c = b;
	
	c.pri();
	
	return 0;
}
/*==============================================================*/