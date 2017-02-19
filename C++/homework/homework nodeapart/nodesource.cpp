#include <iostream>
using namespace std;

//generate new node
NODE *getnode () {  
NODE *p;
p = new NODE;
p->next=nullptr;
p->data=rand()%50+1;
if ( p == NULL)
{
	cout<<"error ,  insufficient memory "<<endl;
	exit(1);
}
//return node
return(p);
}

//free node
void freenode (NODE *p) 
{
	free(p);
}

// search data num and return node
NODE* search_node (NODE *p, int num ){
	NODE *q;
	q = p;
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

// ­find node's length
int length (NODE *p ) 
{
	int num=0;
	NODE *q = p;
	while (q != NULL) {
		num ++;
		q = q->next; 
	}
	return(num);
}

//insert node after head
void insert(NODE *head ,NODE *item){ 
	
	//insert when head->next=nullptr
	if(head->next==nullptr){
		head->next=item;
		item->next=nullptr;
	}
	//insert between head and head->next
	else{
		NODE* temp;
		temp=head->next;
		head->next=item;
		item->next=temp;
	}

}


//delete node
NODE* delete_node(NODE* head){ 
	cout<<"input node's data for delete node:";
	int a;
	cin>>a;
    NODE* p;
    //find node by data
    p=search_node (head, a );
    //data doesn't exist
    if(p==nullptr){
    	cout<<"data does not exist"<<endl;
    	return nullptr;
    }
    //data exist
    else{
    node* pre ;
    pre = head;
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
    return pre;
	}
}

//show node
void priall(NODE* head){
	cout<<"node: ";
	while(head!=nullptr){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

//sort nodes
void sort(NODE* head){
	//n=node's length
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
