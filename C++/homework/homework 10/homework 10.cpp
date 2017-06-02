#include <iostream>
#include <cmath>
using namespace std;
//完成初步的+，- 約分
class F{

public:
	
	F():num(0),den(1){	
	}
	
	F(int a):den(a){
		if(a<0){
			num=-1;
			den=-1*a;
		}	
	}
	
	F(const F &a){
		num=a.num;
		den=a.den;
	}

	F(int a,int b):num(a),den(b){
		if(b<0&&a>0){
			num=-1*a;
			den=-1*b;
		}
	}

	F( int c,int a,int b):num(a),den(b){
		if(a<0||b<0)exit(0);
		else if(c>=0){
			num=c*b+a;
		}
		else if(c<0){
			num=c*b-a;
		}
	}

public:
	F pri(){
		cout<<num<<"/"<<den<<endl;
		return *this;
	}

	void gcd(){	 
		 int r = 0; 
		 int uden=den;
		 int unum=num;
		 while(uden != 0) { 
		    r = unum % uden; 
		    unum = uden; 
		    uden = r; 
    	} 
   	r=unum;
   	num=num/r;
   	den=den/r;
	}	

public:
	F &operator=(F const &a){
		num=a.num;
		den=a.den;
		return *this;
	}

	F &operator*=(int const &a){
		this->num=this->num*a;
		this->den=this->den*a;
		return *this;
	
	}

	F &operator*=(F const &a){
		this->num=this->num*a.num;
		this->den=this->den*a.den;
		return *this;
	
	}

	F &operator/=(F const &a){
		this->num=this->num*a.den;
		this->den=this->den*a.num;
		return *this;
	}

	F &operator+=(F const &a){
		int tempnum;
		tempnum=(a.num)*(this->den);
		(*this)*=a.den;
		this->num+=tempnum;
		return *this;	
	}
	
	F &operator-=(F const &a){
		int tempnum;
		tempnum=(a.num)*(this->den);
		(*this)*=a.den;
		this->num-=tempnum;	
		return *this;
	}

	friend ostream &operator << (ostream &s,F &ob) {
        ob.gcd();
        s<<ob.num<<"/"<<ob.den;
		return s;
        }

private:
	int num;//分子
	int den;//分母

};

F &operator+(F const &a,F const &b){
		return F(a)+=b;
	}

F &operator-(F const &a,F const &b){
		return F(a)-=b;
	}	

F &operator*(F const &a,F const &b){
		return F(a)*=b;
	}

F &operator/(F const &a,F const &b){
		return F(a)/=b;
	}

int main(int argc, char const *argv[]){
	F a(-4,3);
	F b(1,4);
	cout<<a+b<<endl;
	cout<<a-b<<endl;
	cout<<a*b<<endl;
	cout<<a/b<<endl;
	
	return 0;
}
/*==============================================================*/
