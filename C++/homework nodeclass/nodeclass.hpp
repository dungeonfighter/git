#ifndef NODECLASS_HPP //���j�g �I�ܩ��u
#define NODECLASS_HPP //�w�q�榡

class singlenode {

public:	
	struct NODE {
	int data ;
	NODE* next;
	};
public:
	singlenode();
    ~singlenode();
public: 
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
	//���ͽƼƸ`�I(�Q��getnode)
	void multgetnode(int num);

private:
	//����`�I
	void freenode (NODE *p);
	//���ͳ�@�s�`�I
	NODE *getnode ();
	//�R���Ҧ��`�I
	void deleteallnode();
private:
	NODE* head ;

};


#endif