#ifndef NODECLASS_HPP //���j�g �I�ܩ��u
#define NODECLASS_HPP //�w�q�榡

class singlenode {

public:	
	struct NODE {
	int data ;
	NODE* next;
	};

public:
	//���ͷs�`�I
	NODE *getnode ();
	//����`�I
	void freenode (NODE *p); 
	//�M��`�I
	NODE* search_node ( int num );
	//��`�I����
	int length ();
	//���J�`�I
	void insert( NODE *item);
	//�R���`�I
	NODE* delete_node();
	//�ƧǸ`�I
	void sort();
	//show node
	void priall();
	//�����Y�`�I
	void gethead();


public:
	NODE* head ;

};









#endif