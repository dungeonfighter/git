#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Tabu{
public:
    Tabu(const int s,const int t):tabulen(s),timetry(t){
        if(s<1)tabulen=10;
    }
    ~Tabu(){
        for(size_t i = 0; i < datacount; i++)
        {
            delete []citys[i];
            delete []range[i];
        }
        delete []citys;
        delete []range;
    }
    void print(){
        cout<<"tabulen = "<<tabulen<<" datacount = "<<datacount<<endl;
        cout<<"最佳路徑: ";
        for(size_t i = 0; i < datacount; i++){
            cout<<best[i]<<" ";
        }
        cout<<endl;
        cout<<"最佳長度: "<<bestlen<<endl;
    }
    bool read(const string &filename){//讀檔存座標
        ifstream input;
        input.open(filename.c_str());
        if(!input){
            cout<<"input file error"<<endl;  
            return false;
        }
        else{
            string temp;
            size_t i=0;//計數用
            int nouse;
            while(getline(input,temp)){//算資料筆數
                ++i;
            }
            datacount=i;//資料數量
            citys=new float*[datacount];//城市座標的陣列初始化
            for(size_t j=0;j<datacount;++j){
                citys[j]=new float[2];
            }
            input.clear();
            input.seekg(0);
            i=0;
            while(i<datacount){
                input>>nouse>>citys[i][0]>>citys[i][1];//存城市座標
                ++i;
            }
            return true;
        }
    }
    float findlen(const vector<int> &r){
        float len=0;
        //r[0]~r[1]...r[n]~r[0]
        for(size_t i = 0; i < datacount-1; i++) {
            len+=range[r[i]][r[i+1]];
        }
        len+=range[r[datacount-1]][r[0]];

        return len;
    }
    void solve(){
        initial();
        float templen;
        float tempneighbor;
        int tryt=timetry;
        float neibest;
        vector<int>best_neighbor;
        vector<int>temp(best);
        for(size_t k = 0; k < 500; k++)//做幾輪
        {
            listchange(temp);
                while(tryt>0){//連續找不到好鄰居的解小於best timetry次就跳出
                    templen=__FLT_MAX__;
                    //找鄰居中最好的
                    for(size_t i = 0; i < datacount-1; i++)
                    {
                        for(size_t j = i+1; j < datacount; j++)
                        {
                        swap(temp[i],temp[j]);
                        tempneighbor=findlen(temp);  
                        
                        if(tempneighbor<templen && check(temp)){
                                templen=tempneighbor;
                                best_neighbor.assign(temp.begin(),temp.end());
                        }
                        swap(temp[i],temp[j]);
                        }
                    }
                    listchange(best_neighbor);//加入禁忌表
                    //複製不在表中的最好鄰居給temp
                    temp.assign(best_neighbor.begin(),best_neighbor.end());
                    //最好的鄰居比best好就取代best
                    neibest=findlen(best_neighbor);
                    if(neibest<bestlen){
                        bestlen=neibest;
                        best.assign(best_neighbor.begin(),best_neighbor.end());
                        cout<<bestlen<<endl;
                        tryt=timetry;
                    }
                    else{
                        tryt--;      
                    }
                }
            ransolution(temp);
            //resetlist();
        }

    }
private:
    bool initial(){//根據城市座標初始化距離表
        if(!citys){
            cout<<"No city points"<<endl;
            return false;
        }
        else{
            srand(time(NULL));
            range=new float*[datacount];
            for(size_t j=0;j<datacount;++j){
                range[j]=new float[datacount];
            }
            
            float x2,y2,lan;
            for(size_t i = 0; i < datacount; i++)//建距離表
            {
                range[i][i]=0;//自己和自己
                for(size_t j = i+1; j < datacount; j++){
                    x2=citys[i][0]-citys[j][0]; 
                    y2=citys[i][1]-citys[j][1];
                    lan=sqrt(pow(x2,2)+pow(y2,2));
                    range[i][j]=lan;
                    range[j][i]=lan;
                }
            }
            best.resize(datacount);
            //預設1~N再隨機排列
            for(size_t i = 0; i < datacount; i++){
                best[i]=i;
            }
            ransolution(best);
            bestlen=findlen(best);
            tabulist.resize(tabulen);
            vector<int>a(datacount,0);
            for(size_t i = 0; i < tabulen; i++){
                tabulist[i].assign(a.begin(),a.end());
            }
            
            return true;
        }
    }
    void resetlist(){
        
        for(size_t i = 0; i < tabulen; i++)
        {
            tabulist[i].clear();
            
        }
        
    }
    void ransolution(vector<int> &a){ 
        size_t r=-1;
        for(size_t i = 0; i < a.size(); i++)
        {
            r=rand()%datacount;
            while(r==i){
                r=rand()%datacount;
            } 
                swap(a[i],a[r]);
            }
    }
    void listchange(const vector<int>&in){
    
        for(size_t i = 0; i < tabulen-1; i++)
        {
            //tabulist.at(i).assign(tabulist.at(i+1).begin(),tabulist.at(i+1).end());
            tabulist[i]=tabulist[i+1];
        }
        tabulist[tabulen-1].assign(in.begin(),in.end());
    }
    bool check(const vector<int>&in){
        size_t con;
        for(size_t i = 0; i < tabulen; i++)
        {
            con=0;
            for(size_t j = 0; j < datacount; j++)
            {
                if(tabulist[i]!=in){
                    break;
                }
                else{
                    con++;
                }
            } 
            if(con==datacount)return false;
        }
        return true;

    }
private:
    size_t datacount=0;//資料數
    size_t tabulen=0;//禁忌表長度
    vector<vector <int>>tabulist;//禁忌表
    vector<int>best;//最佳路徑
    float bestlen;//最佳路徑長
    float **citys;//城市座標
    float **range;//距離表
    int timetry=1000;//最多嘗試次數
};
int main(int argc, char const *argv[])
{
    Tabu a(2500,5000);
    a.read(argv[1]);
    a.solve();
    a.print();
    return 0;
}
