#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
/*==============================================================*/
string revise(){ //�\��1
	
	string s ;
	cout<<"�п�J�s�r��:";
	cin>>s;
	cout<<"��粒���A�r��w�令:"<<s<<endl;
	
	return s ;
}

string to_up(string s){ //�\��2
	for (int i = 0; i < s.size(); ++i)
		{
			if(int(s[i])>=97 && int(s[i])<=122 ){
			s[i]=char(int(s[i])-32);
		}	
	}
	cout<<"���j�g����:"<<s<<endl;
	return s ;	

}

string to_low(string s){ //�\��3
	for (int i = 0; i < s.size(); ++i)
	{
		if(int(s[i])>=65 && int(s[i])<=90 ){
			s[i]=char(int(s[i])+32);
		}
	}
	cout<<"���p�g����:"<<s<<endl;
	return s ;
}

void over(){ //�\��4
cout<<"�{������"<<endl;
exit(1) ;
}

string sungletrans(string s ){//�\��5

	cout<<"�п�J�����j�p�g���r����m(0�}�l�ư_~):";
	int c;
	cin>>c ;
			
	if(int(s[c])>=97 && int(s[c])<=122 ){
		s[c]=char(int(s[c])-32);
	}
	else if(int(s[c])>=65 && int(s[c])<=90 ){
	s[c]=char(int(s[c])+32);
	}
	else{
	cout<<"�Ӧr�������^��";
	}	

	return s;
}

int main(int argc, char const *argv[]){
	
	string s="eNkEsqonX";
	cout<<"��r��:"<<s<<" �r��d��:"<<"0~"<<s.size()-1<<endl;
	
	while(1){
		cout<<"�п�ܤ覡(��J�Ʀr)"<<endl;
		cout<<"1:���r�� 2:�ഫ�j�g 3:�ഫ�p�g 4:���} 5:��X��@�r�����j�p�g�ഫ"<<endl;
		int sel;
		cin>>sel;
		if (sel==1)
		{
			s=revise();
		}
		else if (sel==2)
		{
			s=to_up(s);
			
		}
		else if (sel==3)
		{
			s=to_low(s);	
		}
		else if (sel==4){	
			over();
		}
		else if (sel==5){
			s=sungletrans(s);
		}
		else{
			cout<<"�N�X��J���~"<<endl; 
		}
		cout<<"�{�b�r�ꬰ:"<<s<<" �r��d��:"<<"0~"<<s.size()-1<<endl;
	}
	return 0;
}
/*==============================================================*/