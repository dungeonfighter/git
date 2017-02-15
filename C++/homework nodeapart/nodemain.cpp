#include <iostream>
#include <time.h>
#include "nodesource.hpp"
#include "nodesource.cpp"

using namespace std;



int main(int argc, char const *argv[]){
	srand(time(NULL));
	//generate head node
	NODE *head ;
	head=getnode();
	int sel;
	//select function
	while(1){
		cout<<"select function 1:insert node 2:delete node 3:sort node 4:exit "<<endl;
		cin>>sel;
		if (sel==1)
		{
			//generate new node and insert
			insert(head,getnode());
		}
		else if (sel==2)
		{
			//delete node by data
			delete_node(head);
		}
		else if (sel==3)
		{
			//sort nodes
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