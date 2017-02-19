#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
/*==============================================================*/
int main(int argc, char const *argv[]){
	
	srand(time(NULL));//�ɶ��H���ؤl


	const int arr[]{75,28,36};
	const int *app[3];
    app[2]=&arr[2];
    app[1]=&arr[1];
	app[0]=&arr[0];
	




    cout<<"**const int**"<<endl<<endl;

    cout<<"unsorted	";
   	
    for (int i = 0; i < 3; ++i)
    {
    	cout<<*app[i]<<" ";
    }

    cout<<endl<<endl;

    //��}�Ƨ�
    for (int i = 0; i < 3; ++i)
    {
    	for (int j = 0; j < 3; ++j)
    	{
    		if (*app[i]<*app[j])
    		{
    			const int* emp;
    			emp=app[i];
    			app[i]=app[j];
    			app[j]=emp;
    		}
    	}
    }
    cout<<"sort    	";
    for (int i = 0; i < 3; ++i)
    {
    	cout<<*app[i]<<" ";
    }

    cout<<endl<<endl;
	


	int* a=new int[5];
	for (int i = 0; i < 5; ++i)
	{
		a[i]=rand()%100; //�H������0~100���ƭ�
	}



    cout<<"**Dynamic array**"<<endl<<endl;
    //�ʺA�}�C�Ƨ�
    
    cout<<"unsorted	";
    for (int i = 0; i < 5; ++i)
   {
   		cout<<a[i]<<" ";
   }
   cout<<endl<<endl ; 

   cout<<"sort    	";
    






    for (int i = 0; i < 5; ++i)
    {
    	for (int j = 0; j < 5; ++j)
    	{
    		if (a[i]<a[j])
    		{
    			int temp;
    			temp=a[i];
    			a[i]=a[j];
    			a[j]=temp;
    		}
    	}
    }

   for (int i = 0; i < 5; ++i)
   {
   		cout<<a[i]<<" ";
   }
   cout<<endl ; 
	
	delete []a;






	return 0;
}
