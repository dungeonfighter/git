#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include "PSO.h"
//P相關的功能
PSO::P::P(PSO &a){
    pso=&a;
    v.reserve(pso->D);
    now.reserve(pso->D);
    pbest.reserve(pso->D);
    
    for(size_t i = 0; i < pso->D; i++)
    {
        double v1=double(rand()-1)/double(RAND_MAX);
        double n1=(5.12 - (-5.12)) * rand() / (RAND_MAX + 1.0) + (-5.12);//-5.12~5.12
        v.push_back(v1);
        now.push_back(n1);
    }
    count();
}

void PSO::P::count(){
    double temp=0;
    for(size_t i = 0; i < pso->D; i++)
    {
        temp+=pow(now[i],2)-10*cos( 2*(PI)*(now[i]) );
    }
    temp+=10*(pso->D);
    if(temp<fitbest){
        fitbest=temp;
        pbest.assign(now.begin(),now.end());
    }
    if(temp<pso->fitness_best){
        pso->fitness_best=temp;
        pso->gbest.assign(now.begin(),now.end());
        
        
        std::cout<<std::setprecision(5)<<temp<<std::endl;
    }
}

void PSO::P::update(){
    
    for(size_t i = 0; i < pso->D; i++)
    {
        double r1=double(rand()-1)/(RAND_MAX);
        double r2=double(rand()-1)/(RAND_MAX);
        v[i]=(pso->w)*v[i]+(pso->c1)*r1*(pbest[i]-now[i])+(pso->c2)*r2*(pso->gbest[i]-now[i]);
        if(v[i]>5)v[i]=5;
        if(v[i]<-5)v[i]=-5;
        now[i]+=v[i];
        //解要在-5.12~5.12之間
        if(now[i]>5.12)now[i]=5.12;
        if(now[i]<-5.12)now[i]=-5.12;
    }

}

//PSO相關的功能
void PSO::initial(){
    srand(time(NULL));
    partical.reserve(Pnum);
    
    for(size_t i = 0; i < Pnum; i++)
    {
        partical.push_back(P(*this));
    }
}

void PSO::print(){
        std::cout<<"結束"<<std::endl;
}

void PSO::P_update(){
    for(size_t i = 0; i < Pnum; i++)
    {
        partical[i].update();
    }
}

void PSO::P_count(){  
    for(size_t i = 0; i < Pnum; i++)
    {
        partical[i].count();
    }
}

void PSO::run(){
    initial();
    size_t ge=200;
    while(ge>0){
        P_update();
        P_count();
        ge--;
    }
}