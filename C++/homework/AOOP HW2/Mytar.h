#ifndef MYTAR_H
#define MYTAR_H
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct TarHeader
{
    char filename[100];
    char filemode[8];
    char userid[8];
    char groupid[8];
    char filesize[12];
    char mtime[12];
    char checksum[8];
    char type;
    char lname[100];
    /* USTAR Section */
    char USTAR_id[6];
    char USTAR_ver[2];
    char username[32];
    char groupname[32];
    char devmajor[8];
    char devminor[8];
    char prefix[155];
    char pad[12];
};
class Mytar{
public:
    enum state{is_Ustr,not_Ustr};
    Mytar(const char* file);
    ~Mytar();
    Mytar& read();
    int getFilenum();
    void showContent();
private:
    ifstream input;
    vector< TarHeader > tarVector;
    int ustrBlocksize;
    int filenum;
    state is_UStar();
    void checkValidheader();
    int oct2Dec(const char* array, int length);
};

#endif 