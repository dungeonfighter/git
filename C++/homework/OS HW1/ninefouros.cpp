
#include <deque>
#include <iostream>
#include <algorithm>
#include <time.h>
#include "ninefouros.h"
NineFourOS::NineFourOS()
{
    //select=1;

}

void NineFourOS::exec()
{
    sel();
    setdata();
    switch (select) {
    case FIFO:
        fifo();
        break;
    case OPT:
        opt();
        break;
    case ESC:

        break;
    default:
        break;
    }
}

void NineFourOS::reset()
{
    pf_num=0;//page fault num
    io_num=0;//interrupt num
    disk_write_num=0;
    //rs.clear();
    //std::vector<int> temp;
    //rs=temp;
}
void NineFourOS::sel(){
    std::cout<<"input for frame_num(1~100)(input -1 exit): ";
    int s;
    std::cin>>s;
    if(0<s&&s<=100)frame_num=s;
    else if(s==-1)exit(0);
    else{std::cout<<"invalid num "<<std::endl;}
    int mode;
    std::cout<<"input for algorithm(0~3): ";
    std::cin>>mode;

    switch (mode) {
    case FIFO:
        select=FIFO;
        break;
    case OPT:
        select=OPT;
        break;
    case ESC:
        select=ESC;
        break;
    default:
        break;
    }
}

void NineFourOS::fifo()
{

    std::deque<int> memory;
    int i=0;
    while(memory.size()<frame_num){
        std::deque<int>::iterator it;
        it = find(memory.begin(), memory.end(), rs[i]);
        if (it == memory.end()){
            memory.push_back(rs[i]);
        }
        ++i;
    }
    for(i;i<rs.size();++i){
        bool ex=false;
        for(size_t j=0;j<memory.size();++j){
            if(memory[j]==rs[i])ex=true;
        }
        if(!ex){
            memory.pop_front();
            memory.push_back(rs[i]);
            pf_num++;
        }

        //for(auto& it : memory){
        //    std::cout<<it<<" ";
        //}


    }
    std::cout<<pf_num<<std::endl;

}

void NineFourOS::opt(){
    std::vector<int> memory;
    memory.reserve(frame_num);
    int ini=0;
    while(memory.size()<frame_num){//先一次讀取frame數目的資料並填到memory裡
        std::vector<int>::iterator it;
        it = find(memory.begin(), memory.end(), rs[ini]);
        if (it == memory.end()){//不在memory內就放進去
            memory.push_back(rs[ini]);
        }
        ++ini;
    }
    std::vector<int>count;
    count.resize(501); 
    int victim=rand()%frame_num;//第一次隨機挑 victim是0~memory.size()的index，不代表實際被替換的page(1~500)

    for(size_t i = ini; i < rs.size(); i++)//ini到測資最末筆資料
    {
        //有沒有在memory裡
        bool in=false;
        for(size_t j = 0; j < memory.size(); j++)
        {
            if(memory[j]==rs[i]){
                in=true;
                break;
            }
        }
        if(!in){//不在memory內，發生pagefault;
            count[ memory[victim] ]=0;//清空victim的計數
            memory[victim]=rs[i];//把新進資料置換到victim位置的memory
            pf_num++;
        }

        //更新memory中每個page多久會再次會使用
        for(size_t j = 0; j < memory.size(); j++)//記憶體中每筆資料
        {
            int c=1;//計數多久後會用到
            for(size_t k = i+1; k < rs.size(); k++)//下一筆測資到最後一筆測資
            {
                if(memory[j]==rs[k]){//找到就跳出
                    count[memory[j]]=c;
                    break;
                }
                ++c;
            }
            
        }
        //根據count使用表更新victim
        int temp_count=0;//存最久沒被使用的次數
        for(size_t j = 0; j < memory.size(); j++)//記憶體中每筆資料
        {
            if(count[ memory[j] ] >= temp_count){//大於最久未使用數，取代並指定給victim
                temp_count=count[ memory[j] ];
                victim=j;
            }
        }


    }
    std::cout<<pf_num<<std::endl;
    

}

void NineFourOS::setdata()
{
    if(!rs_exist){
        rs.reserve(100000);
        //srand(time(NULL));
        for(int i=0;i<20000;++i){
            int r=rand()%496+1;
            for(int j=0;j<5;++j){
                rs.push_back(r+j);
            }
        }
        rs_exist=true;
    }

}
