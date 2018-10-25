#ifndef NINEFOUROS_H
#define NINEFOUROS_H
#include <vector>
#include <stdlib.h>
class NineFourOS
{
public:
    enum algorithm{FIFO,OPT,ESC,MY};
public:
    NineFourOS();
    void sel();
    void reset();
    void output_data();
private:
    void exec();
    void fifo();//先進先出
    void opt();//最佳法
    void esc();//強化二次交換
    void my();
    void setdata();//讀檔並存進rs
    void clear_rs_dir();
    
private:
    size_t frame_num=20;//20 40 60 80 100
    int datanum=100000;
    algorithm select=FIFO;
    int pf_num=0;//page fault 次數
    int io_num=0;//interrupt 次數
    int disk_write_num=0;//寫回次數
    bool rs_exist=false;
    int rs_sel=0;//測資種類
    std::vector<int> rs;//references string
    std::vector<std::vector<int>> dr;//dirty bit
    std::vector<bool> rs_dir;//rs寫入表(dirty)
};


#endif // NINEFOUROS_H
