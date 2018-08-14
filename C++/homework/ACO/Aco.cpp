#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include "Aco.h"
Aco::Aco(size_t ants,size_t it):antsnum(ants),iternum(it){}

bool Aco::read(const std::string &filename){//讀檔存座標
        std::ifstream input;
        input.open(filename.c_str());
        if(!input){
            std::cout<<"input file error"<<std::endl;  
            return false;
        }
        else{
            std::string temp;
            size_t i=0;//計數用
            int nouse;
            while(getline(input,temp)){//算資料筆數
                ++i;
            }
            datacount=i;//資料數量
            
            input.clear();
            input.seekg(0);
            i=0;
            citys.resize(datacount);
            
            for(size_t i = 0; i < datacount; i++)
            {
                citys[i].assign(2,0);
            }
            
            while(i<datacount){
                input>>nouse>>citys[i][0]>>citys[i][1];//存城市座標
                ++i;
            }
            return true;
        }
    }

void Aco::print(){
    //std::cout<<float((rand()-1))/float(RAND_MAX);
    std::cout<<"目前已經找到的最好解"<<bestlen<<std::endl;
}

bool Aco::initial(){//根據城市座標初始化距離表
    if(citys.empty()){
        std::cout<<"No city points"<<std::endl;
        return false;
    }
    else{
        srand(time(NULL));
        range.resize(datacount);
        for(size_t j=0;j<datacount;++j){
            range[j].assign(datacount,0);
        }
        float x2,y2,lan;
        for(size_t i = 0; i < datacount; i++)//建距離表
        {
            range[i][i]=0;//同一座城市
            for(size_t j = i+1; j < datacount; j++){
                x2=citys[i][0]-citys[j][0]; 
                y2=citys[i][1]-citys[j][1];
                lan=sqrt(pow(x2,2)+pow(y2,2));
                range[i][j]=lan;
                range[j][i]=lan;
            }
        }
        best.assign(datacount,0);//初始化最佳路徑
        //初始化費落蒙表
        phe.resize(datacount);
        for(size_t j=0;j<datacount;++j){
            phe[j].assign(datacount,0);
        }
        for(size_t i = 0; i < datacount; i++)///預設為1/datacount
        {  
            for(size_t j = 0; j < datacount; j++){
                phe[i][j]=1/float(datacount);
            }
        }
        //初始化機率表
        pro.resize(antsnum);
        for(size_t j=0;j<antsnum;++j){
            pro[j].assign(datacount,0);
        }
        //每支螞蟻的可選擇路徑表
        allow.resize(antsnum);
        for(size_t j=0;j<antsnum;++j){
            allow[j].assign(datacount,0);
        }
        //初始化每支螞蟻的路徑表
        antsway.resize(antsnum);
        for(size_t j=0;j<antsnum;++j){
            antsway[j].assign(datacount,0);
        }
        return true;
    }
}
void Aco::solve(){
    initial();

    
    for(size_t x = 0; x < iternum; x++)//走幾輪
    {
        getantsways();
        findbest_len();//計算長度
        updatephe();//更新費落蒙表
        resetallow();//重置allow;
    }
}

void Aco::getantsways(){
    
    for(size_t i = 0; i < antsnum; i++)//起點隨機
    {
        antsway[i][0]=rand()%datacount;
        allow[i][antsway[i][0]]=1;//加入tabu
    }
    
    for(size_t i = 0; i < antsnum ; i++)//每隻螞蟻
    {
        for(size_t j = 1; j < datacount; j++)//從第二點開始
        {
            setpro(i , j-1);//建第i隻螞蟻 j-1 ~ j 的機率表
            setposi(i , j);//根據機率表找下一點
        }
    }
    
}

void Aco::setpro(int index,int now){//第index隻螞蟻 antsway[index][now]--->才是現在的城市編號
    
    double dei=0;//分母     
    for(size_t j = 0; j < datacount; j++)
    {
        if(allow[index][j]==0){
            dei+=( (pow(phe[antsway[ index][now] ][j],alpha))*(pow((1/range[ antsway[index][now] ][j]),beta)) );
            
        }
    }
    
    for(size_t i = 0; i < datacount; i++)
    {
        if(allow[index][i]==1)pro[index][i]=0;
        else{
            pro[index][i]=(pow(phe[antsway[index][now]][i],alpha))*(pow((1/range[antsway[index][now]][i]),beta))/(dei);
        }
    }
    
}

void Aco::setposi(int index , int now){//index 第幾隻螞蟻 
    int select=1;
    double max=float((rand()-1))/float(RAND_MAX);//(rand()%10000)*(0.0001);
    double ad=0;
    
    for(size_t i = 0; i < datacount; i++)//保底
    {
        if(pro[index][i]>0){
            select=i;
            break;
        }
    }
       
    for(size_t i = 0; i < datacount; i++)
    {
        ad+=pro[index][i];
        if(ad>=max){
            select=i;
            break;
        }   
    }
    antsway[index][now]=select;
    allow[index][select]=1;
    //std::cout<<ad<<std::endl;
}

void Aco::resetallow(){
    
    for(size_t i = 0; i < antsnum; i++)
    { 
        for(size_t j = 0; j < datacount; j++)
        {
            allow[i][j]=0;
        }
    }
    
}

 void Aco::findbest_len(){

     temp=1000000;
     for(size_t i = 0; i < antsnum; i++)
     {
         float len=0;
         
         len+=range[ antsway[i][datacount-1] ][ antsway[i][0] ];
         for(size_t j = 0; j < datacount-1; j++)
         {
             len+=range[ antsway[i][j] ][ antsway[i][j+1] ];
         }

         if(len<bestlen){
             best.assign(antsway[i].begin(),antsway[i].end());
             bestlen=len;
             std::cout<<len<<std::endl;
         }
         if(len<temp){
             temp=len;
             tempbest.assign(antsway[i].begin(),antsway[i].end());
         }
     }
     
 }
 void Aco::updatephe(){
     //只將該輪最佳路徑用來更新費落蒙表
     for(size_t i = 0; i < datacount-1; i++)
     {
         phe[tempbest[i]][tempbest[i+1]]*=aho;
         phe[tempbest[i]][tempbest[i+1]]+=Q/temp;
     }
     phe[tempbest[datacount-1]][tempbest[0]]+=Q/temp;

 }