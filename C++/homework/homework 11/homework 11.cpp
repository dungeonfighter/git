/*****************************************************************
Name : 
Date : 2017/06/06
By   : Hui
Final: 2017/06/06
*****************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
/*==============================================================*/
class restore{
	
	class data{
	friend class restore;
	private:
		string name="***";//姓名
		string age="***";//年齡
		string height="***";//身高
		string income="***";//收入
		data *next=nullptr;
	public:
		void inputdata(){//CMD輸入資料
			cout<<"input:name,age,height,income"<<endl;
			cin>>name>>age>>height>>income;
		}
		
		void ofoutputdata(fstream &fout){//寫檔輸出資料
			fout<<name<<" "<<age<<" "<<height<<" "<<income<<endl;
		}
		void showdata(){//CMD顯示資料
			cout<<name<<"	"<<age<<"	"<<height<<"	"<<income<<endl;
			
		}
		void f_inp(string &s,int &num){//讀檔時利用計數依序放資料
			if(num%4==0)name=s;
			else if(num%4==3)age=s;
			else if(num%4==2)height=s;
			else if(num%4==1)income=s;
		}
	};
	
public:
	restore():head(getp()){
	}
	~restore(){
		data *p=this->head;
		while(p!=nullptr){
			delete p;
			p=p->next;
		}
	}

	data* getnewdata(){//CMD新增資料
		data* p=new data;
		p->inputdata();
		return p;
	}

	data* getp(){//單純得到節點，讀檔輸入資料時用到
		data* p=new data;
		return p;
	}

	void insert(data* item){//插入節點
		if(this->head->next==nullptr){
			this->head->next=item;
			item->next=nullptr;
		}
	//insert between head and head->next
		else{
			data* temp;
			temp=this->head->next;
			this->head->next=item;
			item->next=temp;
		}
	}

	int length(){//回報幾筆資料
		int num=0;
		data *q = this->head->next;
			while (q != NULL) {
				num ++;
				q = q->next; 
			}
		return(num);
	}
	void showalldata(){//CMD顯示所有資料
		cout<<endl;
		data *q = this->head->next;
		while (q != NULL) {
			q->showdata();
			q = q->next; 
		}
		cout<<endl;
	}

	void foutalldata(fstream &fout){//寫檔所有資料
		cout<<endl;
		data *q = this->head->next;
		while (q != NULL) {
			q->ofoutputdata(fout);
			q = q->next; 
		}
		
	}

	void sortbyage(){//年齡排序,由小至大
		
		int n=length();//n次巡迴表示氣泡排序所需最大次數
		for (int i = 0; i <=n; ++i)
		{
			data* p=head->next;//參考點
			data* pre=head;//p的前一點

			while(p->next!=nullptr){//巡迴每個點
				//需要交換時
				if(atoi((p->age).c_str()) >= atoi((p->next->age).c_str())){
					//順序示意: pre , p , p->next , temp
					data* temp=p->next->next;//p的下下一點
					pre->next=p->next;
					pre=p->next;
					p->next->next=p;
					p->next=temp;
				}    
				//不需要交換時  
				else{
					pre=p;
					p=p->next;
				}
			}
		}	
		cout<<"sort complete "<<endl;
	}
	void read( fstream &fin,int &num){//讀舊檔
		fin.open("HappyMan.txt",ios::in);
		string b;//資料暫存
		data* p;
		while(fin>>b){
			
			//cout<<num<<"::"<<b<<"	"; //num 真正的資料數
			//每四個資料產生一個節點，並依序放入
			if(num%4==0){
				p=getp();
				p->f_inp(b,num);
			}
			else if(num%4==1){
				cout<<endl;
				p->f_inp(b,num);
			}
			else if(num%4==2){
				p->f_inp(b,num);
			}
			else if(num%4==3){	
				p->f_inp(b,num);
				insert(p);
			}
			
			num--;	
			}
		
		fin.close();
	}
	void write(fstream &fin){//寫檔	
		foutalldata(fin);
		fin.close();
	}	
private:
	data* head;

};

int row(fstream &fin){//計算資料數
	int num=0;
	string b;
	while(fin>>b)num++;
	fin.close();
	return num;
}

int main(int argc, char const *argv[]){

	fstream fin;
	restore a;
	se:
	int sel=0;
	cout<<"input1:load old file 2:new file"<<endl;
	cin>>sel;
	//讀取舊檔
	if(sel==1){
		fin.open("HappyMan.txt",ios::in);
		int c=row(fin);
		a.read(fin,c);
		cout<<"old file data"<<endl;
		a.showalldata();
		fin.open("HappyMan.txt",ios::out);
	}
	//新增檔案
	else if(sel==2){
		fin.open("funnyMan.txt",ios::out);
	}
	else{
		cout<<"wrong num ,please input again"<<endl;
		goto se;
	}
	while(1){
		sy:
		int fun=0;
		cout<<"input1:new data 2:sort data 3:save and exit"<<endl;
		cin>>fun;
		if(fun==1){
			a.insert(a.getnewdata());
			a.showalldata();
		}
		else if(fun==2){
			a.sortbyage();
			a.showalldata();
		}
		else if(fun==3){
			a.write(fin);
			break;
		}
		else{
			cout<<"wrong num ,please input again"<<endl;
			goto sy;
		}

	}
	
	return 0;
}
/*==============================================================*/
