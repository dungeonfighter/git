#include <iostream>

using namespace std;
/*==============================================================*/
int main(int argc, char const *argv[]){
	cout<<"�b��J���ˤ覡�ɿ�J0�B1�A2 �H�~���Ʀr�Y�i�����{��"<<endl;
	while(1){
		
		float in,sel;
		int u ;
	
		cout<<"��J�B�I��"<<endl;
		cin>>in;
		cout<<"��J��� 1 or 0.1 or 0.01 or 0.001"<<endl;
		cin>>sel;
		cout<<"��J���ˤ覡: 0:�L����˥h 1:�L����i�� 2:�|�ˤ��J"<<endl;
		cin>>u;
	

		cout<<"���G:";
		if (u==0)
		{
			cout<<float(int(in/sel))*sel<<endl;
		}
		else if (u==1){
			cout<<float(int(in/sel)+1)*sel<<endl;
		}
		else if (u==2){
		
			cout<<(int)(in / sel + .5) * sel<<endl;
		
		}
		else{
		cout<<"error�Abreak"<<endl;
		break;	
		}
	

	

	cout<<endl;
	}
	return 0;
}
/*==============================================================*/