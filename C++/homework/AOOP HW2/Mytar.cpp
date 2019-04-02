#include "Mytar.h"

Mytar::Mytar(const char *file)
{
    ustrBlocksize = 512;

    input.open(file, ifstream::in | ifstream::binary);
    //check file exist
    if (!input.is_open())
    {
        cout << "Read file error , plz check file" << endl;
        exit(0);
    }
}

Mytar::~Mytar()
{
}

Mytar::state Mytar::is_UStar()//check is tar or not
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
    return Mytar::not_Ustr;
}

Mytar &Mytar::read()
{
    if (Mytar::is_Ustr != is_UStar())
        return *this;
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
    cerr << "Number of valid file(header) : " <<filenum << endl << endl;
    for (size_t i = 0; i < tarVector.size(); i++)
        cerr << tarVector[i].filename << endl;
    input.close();
    return *this;
}

int Mytar::oct2Dec(const char *array, int length)//8 to 10
{
    int ans = 0;
    int n = 0;
    for (int i = length - 2; i >= 0; --i)
    {
        int num = array[i] >= '0' && array[i] <= '9' ? array[i] - '0' : 0;
        ans += num * pow(8, n);
        ++n;
    }

    return ans; //bytes
}

void Mytar::checkValidheader()//preserve valid header
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
        if (!valid)tarVector.erase(tarVector.begin() + i);
    }
}