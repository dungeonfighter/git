#include <iostream>
using namespace std;
/*==============================================================*/
void tem::pri(int num){
	
	int count=0;
	
	
	while(count<=this->y){
		for (int i = 1; i < this->x+1 ; ++i)
		{
			for (int j = 1+count; j <num+1+count ; ++j)
			{
				if(j<=y){
					cout<<j<<"*"<<i<<"="<<j*i<<" ,";

				}
			}
			cout<<endl;
		}
		count += num ;
		cout<<endl;
	}


}

/*==============================================================*/


