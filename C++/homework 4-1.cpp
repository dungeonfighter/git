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

	cout<<"��x��y������򔵺���С������"<<endl<<endl;
	cout<<"ݔ��x: "<<endl;
	cin>>x;
	cout<<"ݔ��y: "<<endl;
	cin>>y;
	cout<<endl;

	int GCD , LCM ;

	GCD=gcd(x,y);

	LCM=x*y/GCD ;

	cout<<"�����:"<<GCD<<endl;
	cout<<"��С������:"<<LCM<<endl;



	return 0;
}
/*==============================================================*/