#ifndef NODESOURCE_HPP //���j�g �I�ܩ��u
#define NODESOURCE_HPP	//�w�q�榡

typedef struct node { 
int data ; 
struct node *next; } NODE;

//new node
NODE *getnode ();
//search node
NODE* search_node (NODE *p, int num );
//find nodes's length
int length (NODE *p );
//insert node
void insert(NODE *head ,NODE *item);
//delete node
NODE* delete_node(NODE* head);
//printf all node
void priall(NODE* head);
//sort node*s data
void sort(NODE* head);






#endif