#ifndef GA_H
#define GA_H
#include <vector>
#include <string>

class GA {
public:
	GA(size_t setp,size_t g) ;
    bool read(const std::string filename);
private:
    void initial();
    void place_p_best();//把當前最好的放在第一個位置
    void cross();//產生子代
    

private:
	class tour {
	public:
		tour(GA & mas);//初始化用 
        tour(GA & mas,std::vector<int> chi);
		std::vector<int>s;
    public:
        double lengh();
        void countlen();
        void path();
        tour& operator =(tour a){
            s.assign(a.s.begin(),a.s.end());
            len=a.lengh();
            return *this;
        }
        
	private:
		double len=0;
		GA* ga;
	};

    void select(std::vector<tour>&new_G);
public:
	void print();
    void solve();



private:
	std::vector<tour>population;//人口群
    std::vector<std::vector<double>> citys;//城市座標
    std::vector<std::vector<double>> range;//距離表
    std::vector<int>best;
    double bestlen=100000;
    double mt=0.18;//突變率
    size_t people=5;//人口數
	size_t datacount=5;//資料數
    size_t gn=10;//世代數
};


#endif