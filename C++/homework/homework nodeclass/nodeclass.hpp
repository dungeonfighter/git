
#pragma once

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
	//尋找節點
	NODE* search_node ( int num );
	//找節點長度
	int length ();
	//插入節點
	void insert( NODE *item);
	//刪除節點
	NODE* delete_node();
	//排序節點
	void sort();
	//show node
	void priall();
	//產生複數節點(利用getnode)
	void multgetnode(int num);

private:
	//產生單一新節點
	NODE *getnode ();
	//刪除所有節點
	void deleteallnode();
private:
	NODE* head ;

};


