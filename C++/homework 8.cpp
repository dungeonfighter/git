#include <iostream>
using namespace std;
/*==============================================================*/
int ta(int n){

	if(n==1){
		return 1;
	}
	else{
		return 2*ta(n-1)+1;
	}

}

int main(int argc, char const *argv[]){
	cout<<"ݔ��Ӄ�������:";
	int n;
	cin>>n;
	//f(1)=1,f(2)=3,f(3)=7,f(4)=15,
	cout<<"���Ƅ�"<<ta(n)<<"��"<<endl ;
	return 0;
}
/*==============================================================*/