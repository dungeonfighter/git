#ifndef NODENAMESPACE_HPP //全大寫 點變底線
#define NODENAMESPACE_HPP //定義格式

namespace LL{
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
	//釋放節點
	void freenode (NODE *p);
	//產生單一新節點
	NODE *getnode ();
	//刪除所有節點
	void deleteallnode();
private:
	NODE* head ;

};
}

#endif