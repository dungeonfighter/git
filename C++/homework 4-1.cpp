#include <iostream>
using namespace std;
/*==============================================================*/
int gcd(int& x , int& y){
	int GCD;
	for (int i = 1; i < ((x>y)?y:x); ++i)
	{
		if ( (x%i==0)&&(y%i==0) )
		{
			GCD=i;
		}
	}
	return GCD ;
}

int main(int argc, char const *argv[]){
	
	int x,y;

	cout<<"求x和y的最大公因數和最小公倍數"<<endl<<endl;
	cout<<"輸入x: "<<endl;
	cin>>x;
	cout<<"輸入y: "<<endl;
	cin>>y;
	cout<<endl;

	int GCD , LCM ;

	GCD=gcd(x,y);

	LCM=x*y/GCD ;

	cout<<"最大公因數:"<<GCD<<endl;
	cout<<"最小公倍數:"<<LCM<<endl;



	return 0;
}
/*==============================================================*/