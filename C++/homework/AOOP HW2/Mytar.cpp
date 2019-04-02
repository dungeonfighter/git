#include "Mytar.h"

Mytar::Mytar(const char *file)
{
    ustrBlocksize = 512;
    input.open(file, ifstream::in | ifstream::binary);

    if (!input.is_open())//check file exist
    {
        cout << "Read file error , plz check file" << endl;
        exit(0);
    }
}

Mytar::~Mytar()
{
}

Mytar::state Mytar::is_UStar() //check is tar or not
{
    input.seekg(0, ios::end);
    int totalfilesize = input.tellg();
    if (totalfilesize % ustrBlocksize == 0)
    {
        input.seekg(257, ios::beg);
        char buffer[6];
        if (input.read(buffer, 6))
        {
            string str(buffer);
            if (str == "ustar ")
                return Mytar::is_Ustr;
        }
    }
    cout<<"Not a ustar file ."<<endl<<"File opening error ."<<endl;
    return Mytar::not_Ustr;
}

Mytar &Mytar::read()
{
    if (Mytar::is_Ustr != is_UStar()){
        exit(0);
        return *this;
    }
    filenum = 0;
    input.seekg(0, ios::beg);
    while (input)
    {
        struct TarHeader buffer;
        if (input.read((char *)&buffer, ustrBlocksize))
        {
            tarVector.push_back(buffer);
            int fileSize = oct2Dec(buffer.filesize, sizeof(buffer.filesize));
            int jumpBlock = ceil((double)fileSize / (double)ustrBlocksize);
            input.seekg(jumpBlock * ustrBlocksize, ios::cur);
        }
    }
    checkValidheader();
    filenum=tarVector.size();
    input.close();
    return *this;
}

int Mytar::oct2Dec(const char *array, int length) //8 to 10
{
    int ans = 0;
    int n = 0;
    for (int i = length - 2; i >= 0; --i)
    {
        int num = array[i] - '0';
        ans += num * pow(8, n);
        ++n;
    }

    return ans; //bytes
}

void Mytar::checkValidheader() //preserve valid header
{
    for (size_t i = 0; i < tarVector.size(); ++i)
    {
        bool valid = false;
        for (size_t j = 0; j < sizeof(tarVector[i].checksum); ++j)
        {
            if (tarVector[i].checksum[j] != 0x00)
            {
                valid = true;
                ++filenum;
                break;
            }
        }
        if (!valid)
            tarVector.erase(tarVector.begin() + i);
    }
}

void Mytar::showContent()
{
    cout<<"toal "<<tarVector.size()<<" files"<<endl;
    
    for (size_t i = 0; i < tarVector.size(); ++i)
    {
        struct TarHeader buffer = tarVector[i];
        cout << left << setw(13) << (buffer.type == '5' ? 'd' : '-')+filemode2string(atoi(buffer.filemode));
        cout << left << setw(11) << buffer.username;
        cout << left << setw(11) << buffer.groupname;
        cout << right << setw(11) << oct2Dec(buffer.filesize, sizeof(buffer.filesize));
        cout << "  " << left << setw(11) << buffer.filename << endl;
    }

    
    
}

string Mytar::filemode2string(int modeNum)//777 -> rwxrwxrwx
{

    int temp = 0;
    int n = 0;
    string mode[3];
    while (modeNum > 0)
    {
        temp = modeNum % 10;

        if (temp - 4 >= 0)
        {
            mode[n] += 'r';
            temp -= 4;
        }
        else
        {
            mode[n] += '-';
        }
        if (temp - 2 >= 0)
        {
            mode[n] += 'w';
            temp -= 2;
        }
        else
        {
            mode[n] += '-';
        }
        if (temp - 1 >= 0)
        {
            mode[n] += 'x';
            temp -= 1;
        }
        else
        {
            mode[n] += '-';
        }
        ++n;

        modeNum /= 10;
    }

    return mode[2] + mode[1] + mode[0];
}