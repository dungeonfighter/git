#include <iostream>
#include <vector>
using namespace std;
/*==============================================================*/
int main(int argc, char const *argv[]){
	//���лP�ʺA�}�C
	int arr[10]{1,2};//�R�A
	arr[8]=34;
	int c=12;
	int* p;
	p=&c;
   
	int* b=new int(15) ; //�p�A���]�w���
	int* a=new int[10]{1,2,5};//�ʺA�n�D�}�C�A�j�A���]�w���
	
	*p=55;
	cout << &p <<"    "<< p <<"    "<< &c <<" "<< *p <<endl<<endl;
	
	for(int i=0 ; i<10 ; ++i){
		cout<<a[i]<<" ";

	}
	cout <<endl<<endl;
	*b=17;
	cout<< *b << endl ;
	delete []a ; //����O����
    delete b ;
     cout <<endl;
    //vector 
    int l=7;
    vector<int>ap(l);//�p�A���i�]�w���פ]�i�ʺA�]�w(�۰ʪ�l�Ƭ��s)
    
    for(int i=0 ; i<ap.size() ; ++i){
   		ap[i]=5;

    }
    
    //�G��vector
    int d=3 , e=4 ;
    vector<vector<int> >ad(d);
    for(int i=0 ; i<d ; i++){
    	ad[i].resize(e);
    }

    cout<<ad[1][2]<<endl<<endl;






    //�G���ʺA�}�C
    int y=3 , x=4 ;
    
    int **data=new int*[y];

    for(int i = 0; i < y; i++)
        data[i] = new int[x];

    for(int i=0;i < y; i++){
        for(int j=0;j < x; j++){
             data[i][j]=i*x + j;
             cout << data[i][j] << "\t";
        }     
        cout << endl;
    }

    //����
    for(int i = 0; i < y; i++)
        delete [] data[i];
    
    delete [] data; 

    // 1/19��ѧ@�~
    // �ƭȱƧ�(�аʺA�}�C�õ����H���ȡA�Ƨ�)�A�a�}�Ƨ�:const int arr[]{1,2,3}
    // int* app[]{arr[0],arr[1],arr[2]}�A�Ƨ�app

	return 0;
}
/*==============================================================*/