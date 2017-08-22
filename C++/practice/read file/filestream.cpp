#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*==============================================================*/
int main(int argc, char const *argv[]){
	
	//cin.getline(name,10); //err name要為char[]
	/*
	getline(cin,name,'K');//存遇到K之前的
	cout<<name<<endl;
	*/
	ifstream input;
	input.open("file.txt",std::fstream::ate);//先到檔尾
	auto filelen=input.tellg();//auto 自動調整型態，接收檔案長度(檔案指標~頭位置)
	cout<<filelen<<endl;
	input.seekg (0,input.beg);//回到開頭+0個位置
	string s;
	int count=0;
	while(getline(input,s)){//讀整行，算有幾筆資料
		count++;
	}
	if(input.eof()==true)cout<<"over"<<endl;//讀完eof=true
	input.clear();//重置eof，沒有重置不能回到檔案頭
	input.seekg(0);//移到開頭
	cout<<count<<"datas"<<endl;
	
	string name[count] ,age[count],id[count];
	while(count>=1){// 3: 0 1 2
		input>>name[count-1]>>age[count-1]>>id[count-1];
		cout<<name[count-1]<<" "<<age[count-1]<<" "<<id[count-1]<<endl;
		cout<<"-------------"<<endl;
		count--;
	}
	
	input.close();
	
	return 0;
}
/*==============================================================*/