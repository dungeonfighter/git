#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;
class SA{
public:
  ~SA(){
    
    for(size_t i = 0; i < datacount; i++)
    {
      delete []citys[i];
      delete []range[i];
    }
    delete []citys;
    delete []range;
    delete []best;
    delete []ans;
  }
  void print(){
    cout<<"SA test: "<<"N="<<N<<" "<<"T="<<T<<" datacount="<<datacount<<endl;
    /*
    for(size_t i = 0; i < datacount; i++)
    {
      for(size_t j = 0; j < datacount; j++)
      {
        cout<<fixed<<setprecision(1)<<setw(6)<<range[i][j]<<" ";
      } 
      cout<<endl;
    }
    */
   cout<<"SA最佳路徑: ";
    for(size_t i = 0; i < datacount; i++)
    {
      cout<<best[i]+1<<" ";
    }
    cout<<endl;
    cout<<"SA最佳長度"<<bestlen<<endl;
  }
  //讀解答
  bool readans(string filename){
    fstream input;
    input.open(filename);
    if(!input){
      cout<<"ans file error"<<endl;  
      return false;
    }
    else{
      size_t i=0;
      ans=new int[datacount];
      while(i<datacount){
        input>>ans[i];
        ans[i]--;
        ++i;
      }
      cout<<"解答最佳路徑：";
      
      for(size_t j = 0; j < datacount; j++)
      {
        cout<<ans[j]<<" ";
      }
      cout<<endl;
      anslen=findlen(ans);
      cout<<"解答最佳長度"<<anslen<<endl;
      return true;
    }
  }
  bool read(string filename){
    fstream input;
    input.open(filename);
    if(!input){
      cout<<"input file error"<<endl;  
      return false;
    }
    else{
      string temp;
      size_t i=0;//計數用
      int nouse;
      while(getline(input,temp)){//算資料筆數
        ++i;
        //cout<<temp<<endl;
      }
      datacount=i;//資料數量
      citys=new float*[datacount];//存城市座標
      for(size_t j=0;j<datacount;++j){
        citys[j]=new float[2];
      }
      input.clear();
      input.seekg(0);
      i=0;
      while(i<datacount){
        input>>nouse>>citys[i][0]>>citys[i][1];
        //cout<<nouse<<": "<<citys[i][0]<<" "<<citys[i][1]<<endl;
        ++i;
      }
      return true;
    }
  }

  bool setvalue(int num,int tem){//設定迭代次數和溫度
    if(num<1 || tem<1){
      cout<<"N or T error set"<<endl;
      return false;
    }
    this->N=num;
    this->T=tem;
    return true;
  }

  void solve(){
    initial();
    int t=T;
    int n;
    int cur[datacount];//目前路徑
    int temp[datacount];//新路徑
    copy(best,cur);
    float templen;
    float curlen;
    float sub=0;
    bestlen=templen=curlen=findlen(cur);
    while(t>=0){
      n=0;
      while(n<N){
        curlen=findlen(cur);
        change(cur,temp);
        templen=findlen(temp);
        if(bestlen>templen){
          bestlen=templen;
          copy(temp,best);
        }
        sub=templen-curlen;

        if(sub<0 || exp(-(sub)/t)>((rand()-1)/(RAND_MAX)) ){
          copy(temp,cur);
        }

        ++n;
      }

      t=t*0.98;
    }

  }

public:

private:
  bool initial(){//根據城市座標初始化距離表
    if(!citys){
      cout<<"No city points"<<endl;
      return false;
    }
    else{
      srand(time(NULL));
      range=new float*[datacount];
      for(size_t j=0;j<datacount;++j){
        range[j]=new float[datacount];
      }
      
      float x2,y2,lan;
      for(size_t i = 0; i < datacount; i++)//建距離表
      {
        range[i][i]=0;//自己和自己
        for(size_t j = i+1; j < datacount; j++)
        {
          x2=citys[i][0]-citys[j][0]; 
          y2=citys[i][1]-citys[j][1];
          lan=sqrt(pow(x2,2)+pow(y2,2));
          range[i][j]=lan;
          range[j][i]=lan;
        }
      }
      best=new int[datacount];
      //預設1~N
      for(size_t i = 0; i < datacount; i++)
      {
        best[i]=i;
      }
      
      return true;
    }
  }
  void copy(int src[],int aim[]){//src複製到aim
    
    for(size_t i = 0; i < datacount; i++)
    {
      aim[i]=src[i];
    }
    
  }
  float findlen(int r[]){
    float len=0;
    //r[0]~r[1]...r[n]~r[0]
    for(size_t i = 0; i < datacount; i++)
    {
      if(i+1==datacount){
        len+=range[r[i]][r[0]];
      }
      else{
        len+=range[r[i]][r[i+1]];
      }
    }
    return len;
  }
  void change(int cur[],int temp[]){
    copy(cur,temp);
    int a,b;
    while(true){
      a=rand()%datacount;
      b=rand()%datacount;
      if(a!=b)break;
    }
    int indextemp=temp[a];
    temp[a]=temp[b];
    temp[b]=indextemp;

  }

private:
  int N=1;//次數
  int T=1;//溫度
  size_t datacount=1;
  float **citys;//城市座標
  float **range;//各城市距離
  int *best;//最佳路徑
  float bestlen;
  int *ans;
  float anslen;
};
int main(int argc , char const *argv[])
{

  SA w;
  w.read(argv[1]);
  w.setvalue(100,350);
  w.solve();
  w.print();
  w.readans(argv[2]);
  return 0;
}
