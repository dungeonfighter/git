#include <iostream>
#include <vector>
using namespace std;
/*==============================================================*/
int main(int argc, char const *argv[]){
	//指標與動態陣列
	int arr[10]{1,2};//靜態
	arr[8]=34;
	int c=12;
	int* p;
	p=&c;
   
	int* b=new int(15) ; //小括號設定初值
	int* a=new int[10]{1,2,5};//動態要求陣列，大括號設定初值
	
	*p=55;
	cout << &p <<"    "<< p <<"    "<< &c <<" "<< *p <<endl<<endl;
	
	for(int i=0 ; i<10 ; ++i){
		cout<<a[i]<<" ";

	}
	cout <<endl<<endl;
	*b=17;
	cout<< *b << endl ;
	delete []a ; //釋放記憶體
    delete b ;
     cout <<endl;
    //vector 
    int l=7;
    vector<int>ap(l);//小括號可設定長度也可動態設定(自動初始化為零)
    
    for(int i=0 ; i<ap.size() ; ++i){
   		ap[i]=5;

    }
    
    //二維vector
    int d=3 , e=4 ;
    vector<vector<int> >ad(d);
    for(int i=0 ; i<d ; i++){
    	ad[i].resize(e);
    }

    cout<<ad[1][2]<<endl<<endl;






    //二維動態陣列
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

    //釋放
    for(int i = 0; i < y; i++)
        delete [] data[i];
    
    delete [] data; 

    // 1/19當天作業
    // 數值排序(創動態陣列並給於隨機值，排序)，地址排序:const int arr[]{1,2,3}
    // int* app[]{arr[0],arr[1],arr[2]}，排序app

	return 0;
}
/*==============================================================*/