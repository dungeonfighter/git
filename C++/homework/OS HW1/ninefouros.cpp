#include "ninefouros.h"
#include <deque>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>
#include <time.h>
#include <fstream>
#include <iomanip>


NineFourOS::NineFourOS()
{
    srand(time(NULL));
}

void NineFourOS::exec()
{
    std::string name;
    setdata();
    clock_t t1 = clock();
    switch (select)
    {
    case FIFO:
        name = "fifo";
        fifo();
        break;
    case OPT:
        name = "opt";
        opt();
        break;
    case ESC:
        name = "esc";
        esc();
        break;
    case MY:
        name = "my";
        my();
        break;
    default:
        name = "fifo";
        fifo(); //例外預設
        break;
    }
    /*std::cout << "frame_num: " << frame_num << " "
              << "dataset: " << rs_sel << " "*/
    std::cout << "algothrim: " << std::setw(4) << name << "    ";
    std::cout << "page fault: " << pf_num << "    ";
    std::cout << "interrupt: " << std::setw(6) << io_num << "    ";
    std::cout << "disk write: "<< std::setw(6) << disk_write_num << "    ";
    std::cout << "clock cost: "<< std::setw(5) <<(clock() - t1) << std::endl;
   
}
void NineFourOS::output_data()
{
    int count = 0;
    //data 0
    std::ofstream out("data 0.txt");
    while (count < 100000)
    {

        int ar, ini;
        ar = rand() % 5 + 1;    //1~5
        ini = rand() % 500 + 1; //1~500
        for (int i = 0; i < ar; ++i)
        {
            if (count % 10 == 0)
                out << std::endl;
            out << ini << "\t";
            ++ini;
            if (ini > 500)
                ini -= 500;
            ++count;
        }
    }
    out.close();
    //data 1
    out.open("data 1.txt", std::ios_base::out);
    count = 0;
    while (count < 100000)
    {
        std::vector<short int> temp;
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
        int cou = rand() % 51 + 50; //取50~100個temp(亂數表)中的數
        for (int i = 0; i < cou; ++i)
        {
            if (count % 10 == 0)
                out << std::endl;
            int s;
            s = rand() % ar;
            out << temp[s] << "\t";
            ++count;
        }
        ar = rand() % 201 + 300; //夾在兩筆function call中的隨機資料(200~500)
        for (int i = 0; i < ar; ++i)
        {
            if (count % 10 == 0)
                out << std::endl;
            ini = rand() % 500 + 1;
            out << ini << "\t";
            ++count;
        }
    }
    out.close();

    //2. data 構成: 1成(休閒 1~150) 3成(作業 70~400) 3成(玩250~500) 2成(東摸西摸1~500) 1成(休閒1~150)
    //說明:模擬放假的一天電腦使用狀況
    out.open("data 2.txt", std::ios_base::out);
    count = 0;
    int temp;
    for (size_t i = 0; i < 10000; i++)
    {
        if (count % 10 == 0)
            out << std::endl;
        temp = rand() % 150 + 1;
        out << temp << "\t";
        ++count;
    }

    for (size_t i = 0; i < 30000; i++)
    {
        if (count % 10 == 0)
            out << std::endl;
        temp = rand() % 331 + 70;
        out << temp << "\t";
        ++count;
    }

    for (size_t i = 0; i < 30000; i++)
    {
        if (count % 10 == 0)
            out << std::endl;
        temp = rand() % 251 + 250;
        out << temp << "\t";
        ++count;
    }

    for (size_t i = 0; i < 20000; i++)
    {
        if (count % 10 == 0)
            out << std::endl;
        temp = rand() % 500 + 1;
        out << temp << "\t";
        ++count;
    }

    for (size_t i = 0; i < 10000; i++)
    {
        if (count % 10 == 0)
            out << std::endl;
        temp = rand() % 150 + 1;
        out << temp << "\t";
        ++count;
    }
    out.close();
}

void NineFourOS::reset()
{
    pf_num = 0; //page fault 次數
    io_num = 0; //interrupt 次數
    disk_write_num = 0;
}
void NineFourOS::sel()
{
    std::cout << "--- step by step 0 , run all 1  , -1 exit---: ";
    int e;
    std::cin >> e;
    if (e == -1)
        exit(0); //-1結束
    if (e != 1 && e != 0)
    {
        std::cout << "error,use 0 " << std::endl;
        e = 0;
    }
    if (e == 1)
    { //全部執行
        std::cout << std::endl;
        for (int i = 0; i < 3; ++i)
        {                            //data
            rs_sel = i;

            std::cout << "dataset = " << rs_sel << std::endl
                      << std::endl;
            for (int j = 0; j < 5; ++j)
            { //frame
                frame_num = 20 + 20 * j; //20 40 60 80 100
                std::cout << "frame num = " << frame_num << std::endl;
                for (int k = 0; k < 4; ++k)
                { //algorithm

                    switch (k)
                    {
                    case 0:
                        select = FIFO;
                        break;
                    case 1:
                        select = OPT;
                        break;
                    case 2:
                        select = ESC;
                        break;
                    case 3:
                        select = MY;
                        break;
                    default:
                        break;
                    }
                    exec();
                    reset();

                }

                //std::cout << std::endl;
            }
            std::cout << "data size = " << rs.size() << std::endl;
            clear_rs_dir();

            std::cout << std::endl;
        }
    }
    else if (e == 0)
    {
        //單步執行
        std::cout << "input for frame_num(1~100)(input -1 exit): ";
        int s;
        std::cin >> s;
        if (s > 0 && s <= 200)
        {
            frame_num = s;
        }
        else if (s == -1)
        {
            exit(0);
        }
        else
        {
            frame_num = 20; //防呆預設 20
        }

        std::cout << "input for kind of dataset(0~2): ";
        std::cin >> s;
        if (s > 2 || s < 0)
        { //防呆 預設 0
            s = 0;
        }
        if (rs_exist == true && s != rs_sel)
        { //當測資已存在時，改變測資種類，並清空rs,rs_dir
            clear_rs_dir();
        }
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
            select = FIFO; //防呆 預設 fifo
            break;
        }

        exec();
    }
}

void NineFourOS::fifo()
{
    std::deque<short int> memory;
    int co = 0;
    while (memory.size() < frame_num) //預先填滿frame數的page到memory
    {
        std::deque<short int>::iterator it;
        it = find(memory.begin(), memory.end(), rs[co]);
        if (it == memory.end())
        {
            pf_num++;
            io_num++;
            memory.push_back(rs[co]);
        }
        ++co;
    }
    for (size_t i = co; i < rs.size(); ++i)
    {
        bool ex = false;
        for (size_t j = 0; j < memory.size(); ++j)
        {
            if (memory[j] == rs[i])
            { //找到並跳出
                ex = true;
                break;
            }
        }
        if (!ex)
        {
            memory.pop_front();
            memory.push_back(rs[i]);
            pf_num++;
            io_num++;
            disk_write_num++;
        }
        //for(auto& it : memory){//巡迴用
        //    std::cout<<it<<" ";
        //}
    }
}

void NineFourOS::opt()
{
    std::vector<short int> memory;
    memory.reserve(frame_num);
    int ini = 0;
    while (memory.size() < frame_num)
    { //先一次讀取frame數目的資料並填到memory裡
        std::vector<short int>::iterator it;
        it = find(memory.begin(), memory.end(), rs[ini]);
        if (it == memory.end())
        { //不在memory內就放進去
            pf_num++;
            io_num++;
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
            io_num++;
            disk_write_num++;
        }
        //更新memory中每個page多久會再次會使用
        io_num++;                                  //計算表要一次interrupt
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
}

void NineFourOS::esc()
{
    std::deque<short int> memory;
    int co = 0;

    while (memory.size() < frame_num)
    { //預先填滿記憶體
        std::deque<short int>::iterator it;
        it = find(memory.begin(), memory.end(), rs[co]);
        if (it == memory.end())
        {
            pf_num++;
            io_num++;
            memory.push_back(rs[co]);
            dr[rs[co]][0] = rs_dir[co];
        }
        ++co;
    }
    int victim = rand() % 20;
    for (size_t i = co; i < rs.size(); ++i)
    { //co到最後一筆測資
        bool ex = false;
        dr[rs[i]][0] = rs_dir[i];
        for (size_t j = 0; j < memory.size(); ++j)
        {
            if (memory[j] == rs[i])
            {
                ex = true; 
                break;
            }
        }
        if (!ex)
        { //page fault

            disk_write_num++;
            //dr[memory[victim]][0] = 0;
            memory[victim] = rs[i];
            
            io_num++;
            pf_num++;
        }

        //選擇victim
        io_num++;                    //計算表要一次interrupt
        std::vector<short int> temp; //dirty bit = 0 填進選擇表
        temp.reserve(100);
        for (size_t j = 0; j < memory.size(); ++j)
        {
            if (dr[memory[j]][0] == 0)
            {
                temp.push_back(j);
            }
        }
        if (temp.size() > 0)
        { //從選擇表隨機挑
            int sel;
            sel = rand() % (temp.size());
            victim = temp[sel];
        }
        else
        {
            victim = rand() % frame_num;
        }
    }
}

void NineFourOS::my()
{
    std::deque<short int> memory;
    int co = 0;
    int victim = rand() % 20;
    std::vector<double> phe(frame_num, 3);
    while (memory.size() < frame_num)
    { //預先填滿記憶體
        std::deque<short int>::iterator it;
        it = find(memory.begin(), memory.end(), rs[co]);
        if (it == memory.end())
        {
            memory.push_back(rs[co]);
            dr[rs[co]][0] = rs_dir[co];
            pf_num++;
            io_num++;
        }
        ++co;
    }

    //co~最後一筆資料
    for (size_t i = co; i < rs.size(); ++i)
    {
        bool ex = false;
        dr[rs[i]][0] = rs_dir[i];
        for (size_t j = 0; j < memory.size(); ++j)
        {
            if (memory[j] == rs[i])
            {
                ex = true;
                
                phe[j] *= 1.5; //存在，增加濃度
                if (phe[j] > 10000)
                    phe[j] = 10000;
                break;
            }
        }
        if (!ex)
        { //page fault
            

            disk_write_num++;

            //dr[memory[victim]][0] = 0;
            memory[victim] = rs[i];
            phe[victim] = 0.8; //剛進來的預設濃度
            io_num++;
            pf_num++;
        }
        
        //根據dirty bit並更新濃度
        io_num++; //計算表要一次interrupt
        for (size_t j = 0; j < memory.size(); ++j)
        {
            if (dr[memory[j]][0] == 1)
            {
                phe[j] *= 2.5;
                phe[j] += 5;
                if (phe[j] > 10000)
                    phe[j] = 10000;
            }
            else
            {
                phe[j] *= 0.8; //衰退
            }
        }
        //根據濃度算機率表
        std::vector<double> pro(frame_num, 0);
        double dei = 0; //分母
        for (size_t j = 0; j < phe.size(); j++)
        {
            dei += (1.0 / phe[j]); //要倒數 因為濃度越高，越不選擇
        }
        for (size_t j = 0; j < pro.size(); j++)
        {
            pro[j] = (1.0 / phe[j]) / dei;
        }
        //根據機率表選擇victim
        double max = (double)(rand() - 1) / (double)(RAND_MAX);
        double ad = 0;
        //victim = rand() % frame_num; //保底
        double temp = 1.1;
        for (size_t j = 0; j < pro.size(); ++j)
        {
            if (pro[j] < temp)
            {
                temp = pro[j];
                victim = j;
            }
        }
        for (size_t j = 0; j < pro.size(); j++)
        {
            ad += pro[j];
            if (ad > max)
            {
                victim = j;
                break;
            }
        }
    }
}

void NineFourOS::setdata()
{
    if (!rs_exist)
    {
        rs.reserve(100000);
        dr.resize(501);
        for (size_t i = 0; i < dr.size(); ++i)
        {
            dr[i].resize(2);
        }

        //int count = 0;

        if (rs_sel == 0)
        {
            //0. data
            std::ifstream in("data 0.txt");
            if (!in)
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                short int temp;
                while (in >> temp)
                {
                    rs.push_back(temp);
                }
            }
        }
        else if (rs_sel == 1)
        { //1. data

            std::ifstream in("data 1.txt");
            if (!in)
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                short int temp;
                while (in >> temp)
                {
                    rs.push_back(temp);
                }
            }
        }
        else
        { //2. data  1(休閒 0~100) 3(作業 70~350) 3(玩300~500) 2(東摸西摸0~500) 1(休閒0~100)
            std::ifstream in("data 2.txt");
            if (!in)
            {
                std::cout << "error" << std::endl;
            }
            else
            {
                short int temp;
                while (in >> temp)
                {
                    rs.push_back(temp);
                }
            }
        }
        //設定 rs寫入表(dirty bit)
        rs_dir.resize(rs.size());
        for (size_t i = 0; i < rs.size() - 150; ++i)
        {
            rs_dir[i] = false;
            for (size_t j = 1; j < 150; ++j)
            { //後面的frame數內有用到，設定為true
                if (rs[i] == rs[i + j])
                {
                    rs_dir[i] = true;
                    break;
                }
            }
        }
        for (size_t i = 1; i < 1000; ++i){//1000個
            rs_dir[datanum-i*10]=true;
        }
        rs_exist = true;
    }
}

void NineFourOS::clear_rs_dir() //清空rs和rs_dir
{
    rs.clear();
    rs_dir.clear();
    std::vector<short int> temp;
    std::vector<bool> temp1;
    rs_dir = temp1;
    rs = temp;
    rs_exist = false;
}
