#include <iostream>
using namespace std;
/*==============================================================*/
int main(int argc, char const *argv[]){
	
	int x,y;

	cout<<"�Dx�My���̤j���]�ƩM�̤p������"<<endl<<endl;
	cout<<"��Jx: "<<endl;
	cin>>x;
	cout<<"��Jy: "<<endl;
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

	cout<<"�̤j���]��:"<<GCD<<endl;
	cout<<"�̤p������:"<<LCM<<endl;



	return 0;
}
/*==============================================================*/