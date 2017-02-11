#include <iostream>
using namespace std;
/*==============================================================*/
int* iint(int p){
int *a=new int;
*a=p;
return a;
}
char* cchar(char p){
char *a=new char;
*a=p;
return a;
}

int main(int argc, char const *argv[]){
	
	void* p;
	p=new char('A');
	cout<<"p="<<*iint(*(int*)p)<<endl;
	cout<<"p="<<*cchar(*(char*)p)<<endl;
	cout << "p=" << *(int*)p << endl;
	cout << "p=" << *(char*)p << endl;
	return 0;
}
/*==============================================================*/