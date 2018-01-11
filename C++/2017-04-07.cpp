#include <iostream>
using namespace std;
/*==============================================================*/
//練習物件中的重載([]、=)，複習指標、動態陣列、建構解構
class Arr {
public:
	int* v;
	int len;

	Arr(int len=3): len(len){
		v=new int[len];
		for (int i = 0; i < len; ++i)
		{
			v[i]=i;
		}
	}
	
	~Arr(){
		delete []v;
	}
	
	Arr & pri(){
		for (int i = 0; i < len; ++i)
		{
			cout<<v[i]<<" ";
		}
		cout<<endl;
		return *this;
	}
	
	int operator[](int i){
		return v[i];
	}
	Arr &operator=(Arr &rhs){ //A &operator 參考有無的差別?
		if(this!=&rhs){ //如果a=a時直接跳到return
			delete v;
			v=new int [rhs.len];
			len=rhs.len;
			for (int i = 0; i <rhs.len ; ++i)
			{
				v[i]=rhs[i];
			}
		}

		return *this;
	}
	
	
};


int main(int argc, char const *argv[]){
	Arr a(4);
	a.pri();
	
	Arr b(2);
	b.pri();
	
	b=a;
	b.pri();
	
	
	
	return 0;
}
/*==============================================================*/