#include <iostream>
#include <time.h>
using namespace std;

/*==============================================================*/
typedef struct node { 
int data ; 
struct node *next; } NODE;

NODE *getnode () { //generate new node 
NODE *p;
p = new NODE;
p->next=nullptr;
p->data=rand()%50+1;
if ( p == NULL)
{
cout<<"error ,  insufficient memory "<<endl;
exit(1);
}
return(p);//return node
}

void freenode (NODE *p) //free node
{
free(p);
}

NODE* search_node (NODE *p, int num ){// search data num and return node
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
    return pre;
	}
}

void priall(NODE* head){//show node
	cout<<"node: ";
	while(head!=nullptr){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

void sort(NODE* head){
	int n=length(head);
	for (int i = 0; i < n*n; ++i)
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
	head=getnode();
	int sel;
	while(1){
		cout<<"select function 1:insert node 2:delete node 3:sort node 4:exit "<<endl;
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
			sort(head->next);
		}
		else if (sel==4)
		{
			exit(1);
		}
		priall(head->next);//show node
	}
	
	return 0;
}
/*==============================================================*/