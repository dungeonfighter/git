#include <iostream>
using namespace std;
/*==============================================================*/
int main(int argc, char const *argv[]){
	
	int x,y;

	cout<<"―x㎝y程そ计㎝程そ计"<<endl<<endl;
	cout<<"块x: "<<endl;
	cin>>x;
	cout<<"块y: "<<endl;
	cin>>y;
	cout<<endl;

	int GCD , LCM ;

	for (int i = 1; i < ((x>y)?y:x); ++i)
	{
		if ( (x%i==0)&&(y%i==0) )
		{
			GCD=i;
		}
	}

	LCM=x*y/GCD ;

	cout<<"程そ计:"<<GCD<<endl;
	cout<<"程そ计:"<<LCM<<endl;



	return 0;
}
/*==============================================================*/