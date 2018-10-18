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
    void fifo();
    void opt();
    void setdata();

private:
    size_t frame_num=5;//20 40 60 80 100
    int datanum=100000;
    algorithm select=FIFO;
    int pf_num=0;//page fault num
    int io_num=0;//interrupt num
    int disk_write_num=0;
    bool rs_exist=false;
    int rs_sel=0;//kind of dataset
    std::vector<int> rs;//references string
};


#endif // NINEFOUROS_H
