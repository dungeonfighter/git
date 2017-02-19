#include <iostream>

using namespace std;
/*==============================================================*/
int main(int argc, char const *argv[]){
	cout<<"在輸入取捨方式時輸入0、1，2 以外的數字即可結束程式"<<endl;
	while(1){
		
		float in,sel;
		int u ;
	
		cout<<"輸入浮點數"<<endl;
		cin>>in;
		cout<<"輸入精度 1 or 0.1 or 0.01 or 0.001"<<endl;
		cin>>sel;
		cout<<"輸入取捨方式: 0:無條件捨去 1:無條件進位 2:四捨五入"<<endl;
		cin>>u;
	

		cout<<"結果:";
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
		cout<<"error，break"<<endl;
		break;	
		}
	

	

	cout<<endl;
	}
	return 0;
}
/*==============================================================*/