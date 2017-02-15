#include <iostream>
#include <time.h>
using namespace std;
/*==============================================================*/
//陣列產生隨機值
void arrayrandom(int *p){ 
for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			*(p+6*i+j)=rand()%50+1 ;
		}
	}
}
//顯示陣列
void printarray (int *p){
	
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			cout<<*(p+6*i+j)<<"	" ;
		}
		cout<<endl;
	}
	cout<<endl;
}
//作業要求功能，第一行加第二行的結果放入第二行
void add(int *p){
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (j%2==0)
			{
				int a=0;
				a=*(p+6*i+j)+*(p+6*i+j+1);
				*(p+6*i+j+1)=a;
			}
		}
		
	}
}

int main(int argc, char const *argv[]){
	srand(time(NULL));
	int a[6][6];
	int *p=&a[0][0];
	cout<<"原陣列"<<endl;
	arrayrandom(p);
	printarray(p);
	add(p);
	cout<<"處理完後的新陣列"<<endl;
	printarray(p);


	return 0;
}
/*==============================================================*/