#include <iostream>
using namespace std;
/*==============================================================*/
 class node {
 	public:
	int data ;
	node *next=NULL ;
};

node *head=NULL;
node *current=NULL;
node *pre=NULL;
int main(int argc, char const *argv[]){
		cout<<"�쵲�m��(��J0�����æL�X�Ҧ����)"<<endl;
		int a ;
		cout<<"��J�Ʀr���:";
		cin>>a;
		if(a==0){
			return 0 ;
		}
		current=new node ;
		current->data = a ;
		head=current;
		
		while(1){
			pre=current;

			cout<<"��J�Ʀr���:";
			int input ;
			cin>>input ;
			
			if(input==0){

				break;
			}
			current=new node ;
			current->data = input ;
			
			pre->next=current ;
		}

		while(head!=NULL){
			cout<<head->data<<"  ";
			head=head->next;
		}

	return 0;
}
/*==============================================================*/