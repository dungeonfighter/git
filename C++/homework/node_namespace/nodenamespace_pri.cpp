#include "nodenamespace.hpp"
#include <iostream>
using namespace std ;
namespace LL {

//產生新節點
singlenode::NODE* singlenode::getnode (){
	
	NODE *p;
	p = new NODE;
	p->next=nullptr;
	p->data=rand()%100+1;
	if ( p == NULL)
	{
		cout<<"error ,  insufficient memory "<<endl;
		exit(1);
	}
	//return node
	return(p);

}

void singlenode:: freenode (NODE *p) {
	delete []p;
}


void singlenode:: deleteallnode(){
	NODE *p=this->head;
	while(p!=nullptr){
		freenode(p);
		p=p->next;
	}
}



}