#include <iostream>
#include <fstream>
#include <vector>
#include <Cmath>
using namespace std;
using uch=unsigned char;

// �פJ�ɮ�
void read(string filename, vector<uch> & img_data) {
    // ##�G�i��Ҧ��}�ɴ���
    fstream img;
    img.open(filename, ios::in | ios::binary);
    // �p�G�}���ɮץ��ѡAfp��0�F���\�Afp���D0
    if(!img) {
        img.close();
        cout << "No file." << endl;
        exit(1);
    }
    else {
        // cout << "File ok." << endl;
    } img.close();
    // ##�G�i��Ҧ�Ū��
    // ���o�`��
    img.open(filename, ios::in | ios::binary);
    img.seekg(0, ios::end);
    ifstream::pos_type filesize;
    filesize = img.tellg();
    img.seekg(0, ios::beg);
    // Ū����
    img_data.vector::resize(filesize);
    img.read(reinterpret_cast<char*>(img_data.data()), filesize);
    img.close();
}
// �N�O�����ƶץX
void write(string filename, vector<uch> & img_data) {
    // �i��Ҧ��g��
    fstream img_file;
    img_file.open(filename, ios::out | ios::binary);
    img_file.write((char*)&img_data[0], img_data.size());
    img_file.close();
}

uch &read2D(int y ,int x , vector<uch> & img_data){
    
    return img_data[sqrt(img_data.size())*y+x];
}
/*==============================================================*/
int main(int argc, char const *argv[]){
	vector<uch> img_data;
    vector<uch> img_data1;
    read("IMG.raw", img_data);
    img_data1.resize(img_data.size()*4);
    cout << img_data1.size() << endl;
    cout << img_data.size() << endl;
    //�Ƭ��G���}�C�A���n�z��
    for(unsigned i = 0; i <sqrt(img_data.size()) ; ++i) {
        for(unsigned j= 0; j < sqrt(img_data.size()); ++j) {     
            int ni,nj;
            ni=i*2;
            nj=j*2;
            img_data1[ni*512+nj]=(int)img_data[i*256+j];//����I
            img_data1[ni*512+nj+1]=(int)img_data[i*256+j];
            img_data1[(ni+1)*512+nj]=(int)img_data[i*256+j];
            img_data1[(ni+1)*512+nj+1]=(int)img_data[i*256+j];
        }
    }
    
    
    write("IMG_out.raw", img_data1);
	return 0;
}
/*
    0 1
    2 3 

    0 0 1 1
    0 0 1 1
    2 2 3 3
    2 2 3 3
    X2 X2+1 X2+4 X2+4+1
    0-> 0   1   4   5
    1-> 2   3   6   7
    2-> 8   9   12  13
    3-> 10  11  14  15

    */