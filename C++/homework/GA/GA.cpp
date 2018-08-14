#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include "GA.h"




GA::GA(size_t setp,size_t g):people(setp),gn(g) {

}

GA::tour::tour(GA & mas) {//初始化用 
	ga = &mas;
	s.resize(ga->datacount);
	for (size_t i = 0; i < s.size(); i++)
	{
		s[i] = i;
	}
	for (size_t i = 0; i < s.size(); i++)
	{
		int x = 0,y = 0;
		while (x==y)
		{
			x = rand() % ga->datacount;
			y = rand() % ga->datacount;
		}
		std::swap(s[x], s[y]);
	}	
}
GA::tour::tour(GA & mas,std::vector<int> chi){
    ga = &mas;
    s=chi;
    countlen();
}

void GA::print(){
	std::cout <<"結束"<< std::endl;
}

bool GA::read(const std::string filename){
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

void GA::initial(){
    srand(time(NULL));
    best.resize(datacount);
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

    for (size_t i = 0; i < people; i++)//初始化人口(隨機解)
	{
		population.push_back(tour(*this));
        population[i].countlen();
	}

}

double GA::tour::lengh(){
            
    return len;
}

void GA::tour::countlen(){
    len=0;
    for(size_t i = 0; i < (ga->datacount)-1; i++)
    {
       len+=ga->range[s[i]][s[i+1]];
    }
    len+=ga->range[s[(ga->datacount)-1]][s[0]];
}

void GA::tour::path(){
    
    for(size_t i = 0; i < s.size(); i++)
    {
        std::cout<<s[i]<<" ";
    }
    std::cout<<std::endl;
}

void GA::place_p_best(){//找最好 把目前最好換到第一個
    double templen=100000;
   
    int temp;
    for(size_t i = 0; i < people; i++)
    {
        if(population[i].lengh()<templen){
            templen=population[i].lengh();
            temp=i;
        }
    }
    if(population[temp].lengh()<bestlen){
        best.assign(population[temp].s.begin(),population[temp].s.end());
        bestlen=population[temp].lengh();
        std::cout<<bestlen<<std::endl;
        mt=0.18;
        //if(mt<0.18)mt=0.18;
    }
    else{
        mt+=0.034;
        if(mt>0.8)mt=0.8;
    }
    int s=double(rand()-1)/double(RAND_MAX);
    /*if(s<0.85)*/std::swap(population[temp],population[0]);
}

void GA::cross(){//第一個和所有其他配對
    
    std::vector<tour>new_G;//存所有的子
    for(size_t i = 1; i < people; i++)
    {
        std::vector<int>child;
        std::vector<int>child1;
        child.reserve(datacount);
        child1.reserve(datacount);
       
        std::vector<int>tabu(datacount,0);
        std::vector<int>tabu1(datacount,0);
        size_t r=(rand()%(datacount/2-5))+5;//複製長度
        double w=double(rand()-1)/double(RAND_MAX);
        size_t x=rand()%(datacount/2);//起點
        size_t x1=rand()%(datacount/2);
        while(x==x1){
            x=rand()%(datacount/2);//起點
            x1=rand()%(datacount/2);
        }
        //複製x~x+r , x1~x1+r 到 0~r
        for(size_t j = 0; j < r; j++)
        {
            child.push_back(population[0].s[j+x]);
            child1.push_back(population[i].s[j+x1]);
            tabu[population[0].s[j+x]]=1;
            tabu1[population[i].s[j+x1]]=1;
        }
        
        for(size_t k = 0; k < datacount; k++)
        {
            if(tabu[population[i].s[k]]==0){
                child.push_back(population[i].s[k]);
                tabu[population[i].s[k]]=1;
            }
            if(tabu1[population[0].s[k]]==0){
                child1.push_back(population[0].s[k]);
                tabu1[population[0].s[k]]=1;
            }          
        }
        
        //突變
        if(w<mt){
            int t1;
            int t2;
            for(size_t e = 0; e < 1; e++)
            {
                t1=rand()%datacount;
                t2=rand()%datacount;
                while(t1==t2){
                    t1=rand()%datacount;
                    t2=rand()%datacount;
                }
                std::swap(child[t1],child[t2]);
                std::swap(child1[t1],child1[t2]);
            }
            
        }

        new_G.push_back(tour(*this,child));
        new_G.push_back(tour(*this,child1));
    }

    select(new_G);
}

void GA::select(std::vector<tour>&new_G){
    
    double s=0;
    double ac=0;
    ac= ((5-(gn/50.0))*0.04) *(-1);
    
    //更新
    for(size_t i = 1; i < people; i++)
    {
        s=double(rand()-1)/double(RAND_MAX)+ac;
        for(size_t j = 0; j < new_G.size(); j++)
        {   
            if(new_G[j].lengh()<population[i].lengh() || s>0.75){//機率保留/取代
                population[i]=new_G[j];
                new_G.erase(new_G.begin()+j);
                break;
            }
        }
        
    }
    
}

void GA::solve(){
    initial();
       
    while(gn>0){
        place_p_best();//把世代中最好的放第一個
        cross();
        gn--;
    }
    place_p_best();

}

