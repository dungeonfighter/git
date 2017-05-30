#include <iostream>
#include <time.h>
#include <string>
using namespace std;

/*==============================================================*/
typedef struct node { 
int data ,scord ; 
string name;
struct node *next; } NODE;

NODE *headgetnode () { //generate new node 
NODE *p;
p = new NODE;
p->next=nullptr;

if ( p == NULL)
{
cout<<"error ,  insufficient memory "<<endl;
exit(1);
}
else{
	
}
return(p);//return node
}




NODE *getnode () { //generate new node 
NODE *p;
p = new NODE;
p->next=nullptr;

if ( p == NULL)
{
cout<<"error ,  insufficient memory "<<endl;
exit(1);
}
else{
	cout<<"input name,data,scord"<<endl;
	cin>>p->name>>p->data>>p->scord;
	cout<<"OK !"<<endl;
}
return(p);
}

void freenode (NODE *p) 
{
free(p);
}

NODE* search_node (NODE *p, int num ){
NODE *q;
q = p;
bool exist=false ;//data exist or not 
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

int length (NODE *p ) // ­find node's length
{
int num=0;
NODE *q = p;
while (q != NULL) {
num ++;
q = q->next; }
return(num);
}

void insert(NODE *head ,NODE *item){ //insert node after head
	if(head->next==nullptr){
		head->next=item;
		item->next=nullptr;
	}
	else{
		NODE* temp;
		temp=head->next;
		head->next=item;
		item->next=temp;
	}

}

NODE* delete_node(NODE* head){//delete node 
	cout<<"input node's data for delete node:";
	int a;
	cin>>a;
    NODE* p;
    p=search_node (head, a );//find node by data
    if(p==nullptr){
    	cout<<"data does not exist"<<endl;
    	return nullptr;
    }
    else{
    node* pre ;
    pre = head;
	
	while ( pre->next != p ){//the node behind  node be deleted ;
		pre = pre->next;
	}
    
    if(p->next==nullptr){  // delete node's tail

    	pre->next=nullptr;
    }
    else{
    	pre->next=p->next;
    	
    }
    freenode(p);
    cout<<"OK ! "<<endl;
    return pre;
	}
}

void priall(NODE* head){//show node
	cout<<"name: ";
	while(head!=nullptr){
		cout<<head->name<<" data:"<<head->data<<" scord:"<<head->scord<<endl;
		head=head->next;
	}
	cout<<endl;
}

void sort(NODE* head){
	int n=length(head);
	for (int i = 0; i < n; ++i)
	{
		NODE* p;
		p=head;
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


int main(int argc, char const *argv[]){
	srand(time(NULL));
	NODE *head ;
	head=headgetnode();
	int sel;
	while(1){
		cout<<" input new data:1 delete data:2 show data:3 exit:4 "<<endl;
		cin>>sel;
		if (sel==1)
		{
			insert(head,getnode());
		}
		else if (sel==2)
		{
			delete_node(head);
		}
		else if (sel==3)
		{
			priall(head->next);//show node
		}
		else if (sel==4)
		{
			exit(1);
		}
		else
		{ 
			cout<<"error number "<<endl;
			continue;
		}
	}
	
	return 0;
}
/*==============================================================*/