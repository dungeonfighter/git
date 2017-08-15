#include <iostream>
using namespace std;
template <class T>
T Sum(const T* x  , int size){//總和
	T sum=0;
	for(int i = 0; i < size; ++i) {
		sum+=x[i];
	}
	return sum;
}

template <class T>
T squar(const T* x  , int size){//乘積
	T mul=1;
	for(int i = 0; i < size; ++i) {
		mul*=x[i];
	}
	return mul;
}

template <class T>
T squar_2(const T* x  , int size){//平方和
	T mul_2=0;
	for(int i = 0; i < size; ++i) {
		mul_2+=x[i]*x[i];
	}
	return mul_2;
}
/*==============================================================*/
int main(int argc, char const *argv[]){
	int a[3]={1,2,4};
	double b[4]={1.5,2.5,3.0,4.2};
	int sizea=sizeof(a)/sizeof(a[0]);//陣列長度
	int sizeb=sizeof(b)/sizeof(b[0]);
	cout<<Sum(a,sizea)<<" ";
	cout<<squar(a,sizea)<<" ";
	cout<<squar_2(a,sizea)<<endl;
	cout<<Sum(b,sizeb)<<" ";
	cout<<squar(b,sizeb)<<" ";
	cout<<squar_2(b,sizeb)<<endl;

	system("pause");
	return 0;
}
/*==============================================================*/