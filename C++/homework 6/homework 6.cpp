#include <iostream>
#include <time.h>
using namespace std;
/*==============================================================*/
//�}�C�����H����
void arrayrandom(int *p){ 
for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			*(p+6*i+j)=rand()%50+1 ;
		}
	}
}
//��ܰ}�C
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
//�@�~�n�D�\��A�Ĥ@��[�ĤG�檺���G��J�ĤG��
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
	cout<<"��}�C"<<endl;
	arrayrandom(p);
	printarray(p);
	add(p);
	cout<<"�B�z���᪺�s�}�C"<<endl;
	printarray(p);


	return 0;
}
/*==============================================================*/