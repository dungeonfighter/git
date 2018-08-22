#ifndef PSO_H
#define PSO_H
#include <vector>
#include <string>
#define PI (3.14159265)
class PSO {
public:
    PSO(size_t a,double b,double c,double d,size_t e):Pnum(a),w(b),c1(c),c2(d),D(e){}
    void print();
    void run();
private:
    void initial();
    void P_update();
    void P_count();
//---------粒子部份
private:
    class P{
    public:
    friend class PSO;
        P(PSO &a);
        void count();
        void update();
    private:
        std::vector<double> v;//各維度的速度
        std::vector<double> now;//現在各維度位置
        std::vector<double> pbest;//目前各維度的最佳值
        double fitbest=1000;
        PSO *pso;
    };
//---------
private:
    size_t Pnum;//粒子數
    double w;
    double c1;
    double c2;
    size_t D;//維度
    double fitness_best=1000;//最佳適應值
    std::vector<double> gbest;//各維度綜合最佳的位置
    std::vector<P> partical;//粒子向量
};


#endif