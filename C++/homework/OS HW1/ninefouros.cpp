#include "ninefouros.h"
#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>

NineFourOS::NineFourOS()
{
}

void NineFourOS::exec()
{
    sel();
    setdata();
    switch (select)
    {
    case FIFO:
        fifo();
        break;
    case OPT:
        opt();
        break;
    case ESC:
        esc();
        break;
    default:
        break;
    }
}

void NineFourOS::reset()
{
    pf_num = 0; //page fault 次數
    io_num = 0; //interrupt 次數
    disk_write_num = 0;
}
void NineFourOS::sel()
{
    std::cout << "input for frame_num(1~100)(input -1 exit): ";
    int s;
    std::cin >> s;
    if (0 < s && s <= 200)
        frame_num = s;
    else if (s == -1)
        exit(0);

    std::cout << "input for kind of dataset(0~2): ";
    std::cin >> s;
    if (rs_exist == true && s != rs_sel)
    { //當測資已存在時，改變測資種類
        rs.clear();
        rs_dir.clear();
        std::vector<int> temp;
        std::vector<bool> temp1;
        rs_dir=temp1;
        rs = temp;
        rs_exist = false;
    }
    if (s > 2)
        s = 0;
    else
    {
        rs_sel = s;
    }

    int mode;
    std::cout << "input for algorithm(0~3): ";
    std::cin >> mode;

    switch (mode)
    {
    case FIFO:
        select = FIFO;
        break;
    case OPT:
        select = OPT;
        break;
    case ESC:
        select = ESC;
        break;
    case MY:
        select = MY;
        break;
    default:
        break;
    }
}

void NineFourOS::fifo()
{

    std::deque<int> memory;
    int co = 0;

    while (memory.size() < frame_num)//預先填滿frame數的page到memory
    {
        std::deque<int>::iterator it;
        it = find(memory.begin(), memory.end(), rs[co]);
        if (it == memory.end())
        {
            memory.push_back(rs[co]);
        }
        ++co;
    }
    for (size_t i = co; i < rs.size(); ++i)
    {
        bool ex = false;
        for (size_t j = 0; j < memory.size(); ++j)
        {
            if (memory[j] == rs[i]){//找到並跳出
                ex = true;
                break;
            }
        }
        if (!ex)
        {
            memory.pop_front();
            memory.push_back(rs[i]);
            pf_num++;
        }

        //for(auto& it : memory){
        //    std::cout<<it<<" ";
        //}
    }
    std::cout << pf_num << std::endl;
}

void NineFourOS::opt()
{
    std::vector<int> memory;
    memory.reserve(frame_num);
    int ini = 0;
    while (memory.size() < frame_num)
    { //先一次讀取frame數目的資料並填到memory裡
        std::vector<int>::iterator it;
        it = find(memory.begin(), memory.end(), rs[ini]);
        if (it == memory.end())
        { //不在memory內就放進去
            memory.push_back(rs[ini]);
        }
        ++ini;
    }
    std::vector<int> count;
    count.resize(501);
    int victim = rand() % frame_num; //第一次隨機挑 victim是0~memory.size()的index，不代表實際被替換的page(1~500)

    for (size_t i = ini; i < rs.size(); i++) //ini到測資最末筆資料
    {
        //有沒有在memory裡
        bool in = false;
        for (size_t j = 0; j < memory.size(); j++)
        {
            if (memory[j] == rs[i])
            {
                in = true;
                break;
            }
        }
        if (!in)
        {                           //不在memory內，發生pagefault;
            memory[victim] = rs[i]; //把新進資料置換到victim位置的memory
            pf_num++;
        }
        //更新memory中每個page多久會再次會使用
        for (size_t j = 0; j < memory.size(); j++) //記憶體中每筆資料
        {
            int c = 1;                                 //計數多久後會用到
            for (size_t k = i + 1; k < rs.size(); k++) //下一筆測資到最後一筆測資
            {
                if (memory[j] == rs[k])
                { //找到就跳出
                    count[memory[j]] = c;
                    break;
                }
                ++c;
            }
        }

        //根據count使用表選擇victim
        int temp_count = 0;                        //存最久沒被使用的次數
        for (size_t j = 0; j < memory.size(); j++) //記憶體中每筆資料
        {
            if (count[memory[j]] >= temp_count)
            { //大於最久未使用數，取代並指定給victim
                temp_count = count[memory[j]];
                victim = j;
            }
        }
    }
    std::cout << pf_num << std::endl;
}

void NineFourOS::esc()
{
    std::deque<int> memory;
    int co = 0;

    while (memory.size() < frame_num)
    { //預先填滿記憶體
        std::deque<int>::iterator it;
        it = find(memory.begin() , memory.end(), rs[co]);
        if (it == memory.end())
        {
            memory.push_back(rs[co]);
            dr[rs[co]][0]=rs_dir[co];
        }
        ++co;
    }
    int victim=rand()%20;
    for (size_t i = co; i < rs.size(); ++i)
    { //co到最後一筆測資
        bool ex = false;
        for (size_t j = 0; j < memory.size(); ++j)
        {
            if (memory[j] == rs[i]){
                ex = true;
                break;
            }
        }
        if (!ex)
        { //page fault
            dr[memory[victim]][0]=0;
            memory[victim] = rs[i];
            pf_num++;
        }
        dr[rs[i]][0]=rs_dir[i];

        //選擇victim
        std::vector<int> temp;//dirty bit = 0 填進選擇表
        for(size_t j = 0; j < memory.size(); ++j){
            if(dr[memory[j]][0]==0){
                temp.push_back(j);
            }
        }
        if(temp.size()>0){//從選擇表隨機挑
            int sel;
            sel=rand()%( temp.size() );
            victim=temp[sel];
        }
        else{
            victim=rand()%frame_num;
        }

    }
    std::cout << pf_num << std::endl;
}

void NineFourOS::my()
{
    std::deque<int> memory;
    int co = 0;

    while (memory.size() < frame_num)
    { //預先填滿記憶體
        std::deque<int>::iterator it;
        it = find(memory.begin() , memory.end(), rs[co]);
        if (it == memory.end())
        {
            memory.push_back(rs[co]);
            dr[rs[co]][0]=rs_dir[co];
        }
        ++co;
    }




}

void NineFourOS::setdata()
{
    if (!rs_exist)
    {
        rs.reserve(100000);
        dr.resize(501);
        for(size_t i = 0; i < dr.size(); ++i){
            dr[i].resize(2);

        }

        int count = 0;

        //srand(time(NULL));
        if (rs_sel == 0)
        {
            //1. data

            while (count < 100000)
            {
                int ar, ini;
                ar = rand() % 5 + 1;    //1~5
                ini = rand() % 500 + 1; //1~500
                for (int i = 0; i < ar; ++i)
                {
                    rs.push_back(ini);
                    ++ini;
                    if (ini > 500)
                        ini -= 500;
                    ++count;
                }
            }

            
        }
        else if (rs_sel == 1)
        {   //2. data
            while (count < 100000)
            {
                std::vector<int> temp;
                int ar, ini;
                ar = rand() % 26 + 25; //25~50
                temp.reserve(ar);
                ini = rand() % 500 + 1;
                for (int i = 0; i < ar; ++i)
                { //範圍內的亂數表
                    temp.push_back(ini);
                    ++ini;
                    if (ini > 500)
                        ini -= 500;
                }
                int cou = rand() % 101 + 50; //取50~150個temp(亂數表)中的數
                for (int i = 0; i < cou; ++i)
                {
                    int s;
                    s = rand() % ar;
                    rs.push_back(temp[s]);
                    ++count;
                }
                ar = rand() % 51 + 50; //夾在兩筆function call中的隨機資料(50~100)
                for (int i = 0; i < ar; ++i)
                {
                    ini = rand() % 500 + 1;
                    rs.push_back(ini);
                    ++count;
                }
            }
            for (int i = 10; i < 20; ++i)
            {
                for (int j = 0; j < 10; ++j)
                {
                    std::cout << rs[10 * i + j] << " ";
                }
                std::cout << std::endl;
            }
        }
        else
        { //2. data  1(休閒 0~100) 3(作業 70~350) 3(玩300~500) 2(東摸西摸0~500) 1(休閒0~100)
            while (count < 100000)
            {
                int ar, ini;
                ar = rand() % 5 + 1;
                ini = rand() % 500 + 1;
                for (int i = 0; i < ar; ++i)
                {
                    rs.push_back(ini);
                    ++ini;
                    if (ini > 500)
                        ini -= 500;
                    ++count;
                }
            }
        }
        //設定 rs寫入表(dirty bit)
        rs_dir.resize(rs.size());
        for(int i = 0; i < rs.size()-frame_num; ++i){
            rs_dir[i]=false;
            for(int j = 1; j < frame_num; ++j){//後面的frame數內有用到，設定為1
                if(rs[i]==rs[i+j]){
                    rs_dir[i]=true;
                    break;
                }
            }
        }
        rs_exist = true;
    }
}
