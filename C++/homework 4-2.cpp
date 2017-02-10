#include <iostream>
using namespace std;
/*==============================================================*/
int main(int argc, char const *argv[]){
	
    int iy,ix;
	//輸入陣列的大小
	cout<<"input y for Array:";
	cin>>iy;
	cout<<"input x for Array:";
	cin>>ix;
	cout<<endl;
	
	//設定動態陣列
	int **a=new int*[iy];

    for(int i = 0; i < iy; i++)
        a[i] = new int[ix];

    //給予陣列所有元素0
    for (int i = 0; i < iy; ++i)
    {
    	for (int j = 0; j < ix; ++j)
    	{
    		a[i][j]=0;
    	}
    }

    //a[0][0]開使跑動，優先順序(右->下->左->上)
	int x=0;
	int y=0;
	a[0][0]=1;
	int count=2;
	int X,Y;
	
	X=ix;//X，Y陣列長寬值(不會變動)
	Y=iy;

		while(1){
			if (x+1<X && a[y][x+1]==0)//往右部分與次數處理
			{	
				if(x==0&&y==0){ //起點先跑過一次了，往右次數要少一
					for (int i = 0; i < ix-1; ++i)
					{
					x++;
					a[y][x]=count;
					count++;
					}
					iy--;
				}
				else{
					for (int i = 0; i < ix; ++i)
					{
						x++;
						a[y][x]=count;
						count++;
					}
					iy--;
				}
			}

			else if (y+1<Y && a[y+1][x]==0)//往下部分與次數處理
			{
				
				for (int i = 0; i < iy; ++i)
				{
					y++;
					a[y][x]=count;
					count++;
				}
				ix--;
			}

			else if (x-1>=0 && a[y][x-1]==0)//往左部分與次數處理
			{
				for (int i = 0; i < ix; ++i)
				{
					x--;
					a[y][x]=count;
					count++;
				}
				iy--;
			}

			else if (y-1>=0 && a[y-1][x]==0)//往上部分與次數處理
			{
				for (int i = 0; i < iy; ++i)
				{
					y--;
					a[y][x]=count;
					count++;
				}
				ix--;
			}
 			
 			else break; //沒有地方可以填數字了，離開
 		}

 	//顯示處理完的陣列
	for (int i = 0; i < Y; ++i)
	{
		for (int j = 0; j < X; ++j)
		{
			
			cout<<a[i][j]<<"	";
		}
		cout<<endl;
	}

	//歸還記憶體
	for(int i = 0; i < iy; i++)
        delete [] a[i];
    
    delete [] a; 



	return 0;
}
/*==============================================================*/