#include <iostream>
#include "nodeclass.hpp"
#include <time.h>
using namespace std;

//�غc�l
singlenode::singlenode():head(getnode()){
	srand(time(NULL));
}
//�Ѻc�l
singlenode::~singlenode(){
	deleteallnode();
}





//���ͷs�`�I
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

//���ͽƼƸ`�I(�Q��getmode)
void singlenode:: multgetnode(int num){
	
	for (int i = 0; i < num; ++i)
	{
		insert(getnode());
	}
	cout<<"�`�I���ͧ���"<<endl;	
}

//����`�I
void singlenode:: freenode (NODE *p) {
	delete p;
}

//�M��`�I
singlenode::NODE* singlenode::search_node ( int num ){
	NODE *q;
	q =this->head->next;
	//data exist or not
	bool exist=false ; 
	while( q!= nullptr ){
		if(q->data==num){
			exist=true;
			break;
		}
		else{
			q = q->next; 
		}
	}
	if(exist==true){
		return(q);
	}
	return nullptr ;
}

//�M��`�I����
int singlenode:: length (){
	int num=0;
	NODE *q = this->head->next;
	while (q != NULL) {
		num ++;
		q = q->next; 
	}
	return(num);
}

//���J�`�I 
void singlenode:: insert(NODE *item){ 
	
	//insert when head->next=nullptr
	if(this->head->next==nullptr){
		this->head->next=item;
		item->next=nullptr;
	}
	//insert between head and head->next
	else{
		NODE* temp;
		temp=this->head->next;
		this->head->next=item;
		item->next=temp;
	}
	

}

//�R���`�I�ǥѸ�ƭ�
singlenode:: NODE* singlenode:: delete_node(){ 
	cout<<"input node's data for delete node:";
	int a;
	cin>>a;
    NODE* p;
    //find node by data
    p=search_node (a);
    //data doesn't exist
    if(p==nullptr){
    	cout<<"data does not exist"<<endl;
    	return nullptr;
    }
    //data exist
    else{
    	NODE* pre ;
    	pre = this->head;
		//find data's previous node
		while ( pre->next != p ){
			pre = pre->next;
		}
    
    	// delete node when it is node's tail
    	if(p->next==nullptr){  
    		pre->next=nullptr;
    	}
    	//dalete node when node between two nodes
    	else{
    		pre->next=p->next;
    	
    	}
    	freenode(p);
    	cout<<"delete complete"<<endl;
    	return pre;
	}
}

//�ƧǸ`�I
void singlenode:: sort(){
	//n=node's length
	int n=length();
	for (int i = 0; i < n; ++i)
	{
		NODE* p;
		p=this->head->next;
		int t;
		while(p->next!=nullptr){//data exchange
			if((p->data)>=(p->next->data)){
				t=p->data;
				p->data=p->next->data;
				p->next->data=t;
			}
			p=p->next;
		}
	}	
	cout<<"sort complete "<<endl;
}

//��ܩҦ��`�I
void singlenode:: priall(){
	cout<<"node: ";
	NODE* p=this->head->next;
	while(p!=nullptr){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

void singlenode:: deleteallnode(){
	NODE *p=this->head;
	while(p!=nullptr){
		freenode(p);
		p=p->next;
	}
}