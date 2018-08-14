#ifndef ACO_H
#define ACO_H
#include <vector>
#include <string>


class Aco{
public:
    Aco(size_t ants,size_t it);
    bool read(const std::string &filename);
    void solve();
    void print();
private:
    bool initial();
    void getantsways();
    void setpro(int index,int now);
    void setposi(int index,int now);
    void resetallow();
    void findbest_len();
    void updatephe();


private:
    size_t datacount;//資料數
    size_t antsnum=20;//螞蟻數
    size_t iternum=50;//迭代次數
    float alpha=2;
    float beta=3;
    float aho=0.9;//揮發率
    float Q=20;
    int bestlen=INT32_MAX;
    float temp;//每一輪裡最好的長度
    std::vector<std::vector<double>> phe;//費落蒙表
    std::vector<std::vector<float>> pro;//每支螞蟻的機率表
    std::vector<std::vector<int>> allow;//每支螞蟻的可選擇路徑表
    std::vector<std::vector<int>> antsway;//每支螞蟻的路徑表
    std::vector<std::vector<float>> citys;//城市座標
    std::vector<std::vector<float>> range;//距離表
    std::vector<int>best;//找到的最佳解
    std::vector<int>tempbest;//每一輪裡最好的路徑



};


#endif