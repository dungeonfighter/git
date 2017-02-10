#include <iostream>
#include <time.h>
using namespace std;
/*==============================================================*/
int main(int argc, char const *argv[]){
	srand(time(NULL));
	int a[6][6];
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			a[i][j]=rand()%50+1 ;
		}
	}

	int *p=&a[0][0];

	cout<<"原陣列"<<endl;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			cout<<*(p+6*i+j)<<"	" ;
		}
		cout<<endl;
	}
	cout<<endl;

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

	cout<<"處理完後的新陣列"<<endl;
	for (int i = 0; i < 6; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			cout<<*(p+6*i+j)<<"	" ;
		}
		cout<<endl;
	}
	cout<<endl;


	return 0;
}
/*==============================================================*/