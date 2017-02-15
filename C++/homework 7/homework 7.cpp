#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
/*==============================================================*/
string revise(){ //功能1
	
	string s ;
	cout<<"請輸入新字串:";
	cin>>s;
	cout<<"更改完成，字串已改成:"<<s<<endl;
	
	return s ;
}

string to_up(string s){ //功能2
	for (int i = 0; i < s.size(); ++i)
		{
			if(int(s[i])>=97 && int(s[i])<=122 ){
			s[i]=char(int(s[i])-32);
		}	
	}
	cout<<"更改大寫完成:"<<s<<endl;
	return s ;	

}

string to_low(string s){ //功能3
	for (int i = 0; i < s.size(); ++i)
	{
		if(int(s[i])>=65 && int(s[i])<=90 ){
			s[i]=char(int(s[i])+32);
		}
	}
	cout<<"更改小寫完成:"<<s<<endl;
	return s ;
}

void over(){ //功能4
cout<<"程式結束"<<endl;
exit(1) ;
}

string sungletrans(string s ){//功能5

	cout<<"請輸入欲更改大小寫的字元位置(0開始數起~):";
	int c;
	cin>>c ;
			
	if(int(s[c])>=97 && int(s[c])<=122 ){
		s[c]=char(int(s[c])-32);
	}
	else if(int(s[c])>=65 && int(s[c])<=90 ){
	s[c]=char(int(s[c])+32);
	}
	else{
	cout<<"該字元不為英文";
	}	

	return s;
}

int main(int argc, char const *argv[]){
	
	string s="eNkEsqonX";
	cout<<"原字串:"<<s<<" 字串範圍:"<<"0~"<<s.size()-1<<endl;
	
	while(1){
		cout<<"請選擇方式(輸入數字)"<<endl;
		cout<<"1:更改字串 2:轉換大寫 3:轉換小寫 4:離開 5:抓出單一字元做大小寫轉換"<<endl;
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
			cout<<"代碼輸入錯誤"<<endl; 
		}
		cout<<"現在字串為:"<<s<<" 字串範圍:"<<"0~"<<s.size()-1<<endl;
	}
	return 0;
}
/*==============================================================*/