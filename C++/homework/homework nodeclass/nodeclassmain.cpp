#include <iostream>
#include "nodeclass.hpp"
#include "nodeclass.cpp"
#include <time.h>
using namespace std;
/*==============================================================*/
int main(int argc, char const *argv[]){
	//產生單向鏈結物件a
	singlenode a ;
	//產生五個節點並插入
	a.multgetnode(5);
	//顯示所有節點
	a.priall();
	//排序節點
	a.sort();
	a.priall();
	//刪除節點
	a.delete_node();	
	a.priall();
	a.multgetnode(2);
	a.priall();
	a.sort();
	a.priall();
	
	return 0;
}
/*==============================================================*/