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
    void exec();
    void reset();
private:
    void sel();
    void fifo();//先進先出
    void opt();//最佳法
    void esc();//強化二次交換
    void setdata();//設定測資

private:
    size_t frame_num=60;//20 40 60 80 100
    int datanum=100000;
    algorithm select=FIFO;
    int pf_num=0;//page fault 次數
    int io_num=0;//interrupt 次數
    int disk_write_num=0;
    bool rs_exist=false;
    int rs_sel=0;//測資種類
    std::vector<int> rs;//references string
};


#endif // NINEFOUROS_H
