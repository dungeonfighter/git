#include <iostream>
#include "nodenamespace.hpp"
#include "nodenamespace.cpp"
#include <time.h>
using namespace std;
using namespace LL;
/*==============================================================*/
int main(int argc, char const *argv[]){
	//���ͳ�V�쵲����a
	singlenode a ;
	//���ͤ��Ӹ`�I�ô��J
	a.multgetnode(5);
	//��ܩҦ��`�I
	a.priall();
	//�ƧǸ`�I
	a.sort();
	a.priall();
	//�R���`�I
	a.delete_node();	
	a.priall();
	a.multgetnode(2);
	a.priall();
	a.sort();
	a.priall();
	
	return 0;
}