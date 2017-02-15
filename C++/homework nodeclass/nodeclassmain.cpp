#include <iostream>
#include "nodeclass.hpp"
#include "nodeclass.cpp"
#include <time.h>
using namespace std;
/*==============================================================*/
int main(int argc, char const *argv[]){
	srand(time(NULL));
	singlenode a ;
	a.gethead();
	for (int i = 0; i < 5; ++i)
	{
		a.insert(a.getnode());
	}
	a.priall();
	a.sort();
	a.priall();
	a.delete_node();
	a.priall();
	for (int i = 0; i < 3; ++i)
	{
		a.insert(a.getnode());
	}
	a.priall();
	a.sort();
	a.priall();
	return 0;
}
/*==============================================================*/