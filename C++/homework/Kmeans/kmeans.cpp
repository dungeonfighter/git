#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;
int k=3;//預設三群
double sse=9999999;
int iter=5;
vector< vector<double> >datas;//原始資料
vector<int>center;//k個 center[k]
vector< vector<int> >group;//group[k][n]
bool read(const string filename,vector< vector<double> > &data){
    fstream input;
    input.open(filename.c_str());
    if(!input){
        cout<<"read error"<<endl;
        return false;
    }
    else{
        string temp;
        stringstream cul;
        int datanum=0;
        while(getline(input,temp)){//算筆數
            datanum++;
        }
        input.clear();//回歸到起始
        input.seekg(0);

        data.resize(datanum);//data[num][]
        for(int i = 0; i < datanum; i++)
        {
            data[i].resize(5);//data[num][5] -> group + 4d 
            getline(input,temp);//讀一整行再用stringstream處理
            cul<<temp;
            for(int j = 0; j < 5; j++)
            {
                cul>>data[i][j];
                
            }
            temp.clear();
            cul.str("");
            cul.clear();   
        }   
        return true;
    }
}

void initial(const string n,vector<int>&c,vector< vector<int> >&g){
    srand(time(NULL));
    k=std::stoi(n);//參數轉int
    c.resize(k);//k個中心點 1D
    g.resize(k);//k群 2D
    int index=0;
    if(datas.size()%k==0){
        index=(datas.size()/k)-1;
    }
    else{
        index=(datas.size()/k);
    }
    cout<<"---start"<<endl;
    
    for(int i = 1; i <= k; i++)
    {
        center[i-1]=index*i-(rand()%index);
        
    }
}

void findcenter(){
    for(int i = 0; i < k; i++)//各群
    {
        int index;
        double temp;
        double best=9999999;
        for(size_t j = 0; j < group[i].size(); j++)//群中每個點
        {
            temp=0;
            for(size_t l = 0; l < group[i].size(); l++)//和其他的點的距離
            {
                
                for(size_t r = 0; r < 4; r++)//4D
                {
                    temp+=pow(datas[ group[i][j] ][r+1]-datas[ group[i][l] ][r+1],2);
                }
     
            }
            if(temp<best){
                index=group[i][j];
                best=temp;
            }
        }
        sse+=best;
        center[i]=index;
    }
}

void run(){//分群 找中心
    //------分群-------
    sse=0;
    for(size_t i = 0; i < datas.size(); i++)//每個點
    {
        int index;
        double temp;
        double bestr=100000;
        for(int j = 0; j < k; j++)//和各個中心比較
        {
            temp=0;
            for(int l = 0; l < 4; l++)//4D range
            {
                temp+=pow( datas[ center[j] ][l+1]-datas[i][l+1] , 2 );
            }
            if(temp<bestr){        
                bestr=temp;
                index=j;       
            }
        }
        group[index].push_back(i);   
    }
    //----------------

    //------找中心-----
    findcenter();
    //----------------

    //---清空group
    
    for(int i = 0; i < k; i++)
    {
        vector<int>sp;
        group[i].clear();
        group[i].swap(sp);
    }
    
    //輸出sse
    cout<<sse<<endl;
}

int main(int argc , char const *argv[])
{
  if(read(argv[1],datas)){
      initial(argv[2],center,group);
	  while (iter>0 && sse>80) {
		  run();
		  iter--;
	  }
	  cout << "---over" << endl;
  }
  
}
