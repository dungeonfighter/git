#include <iostream>
#include <initializer_list>
#include <vector>
using namespace std;
/*==============================================================*/
class Arr {
public:

	void pri() {

		for(int i = 0; i < v.size(); ++i)                                                                          
		{
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}

	Arr(initializer_list<int>i):v(i) {
		
	}

	vector<int>v;

	int & operator[](int idx) {
		
		return v[idx];
	}

	Arr & operator+=(Arr  &rhs) {
		for(unsigned i = 0; i < v.size(); ++i)
			(*this)[i] += rhs[i];
		return (*this);
	}

	Arr & operator+=(int r) {
		for(unsigned i = 0; i < v.size(); ++i)
			(*this)[i] += r;
		return (*this);
	}

};

Arr operator+(Arr  &lhs, Arr  &rhs) {
	Arr temp{0,0,0};
	temp+=lhs;
	temp+=rhs;
	return temp;
}
Arr operator+(Arr
  &lhs, int  r) {
	Arr temp{0,0,0};
	temp+=lhs;
	temp+=r;
	return temp;
}
Arr operator+(int const & r , Arr &lhs) {
	Arr temp{0,0,0};
	temp+=lhs;
	temp+=r;
	return temp;
}

int main(int argc, char const *argv[]) {
	Arr a{0,1,2};
	Arr b{2,2,3};

	Arr c=b+a;
	a.pri();
	b.pri();
	c.pri();

	c+=1;
	c.pri();
	c=a+1;
	c.pri();
	c=1+b;
	c.pri();
	return 0;
}
/*==============================================================*/
//https://charlottehong.blogspot.tw/2017/03/const.html 