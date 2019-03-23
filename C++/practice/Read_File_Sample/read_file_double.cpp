#include <iostream>
#include <string> 
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>
#include <stdlib.h>
using namespace std;
int main()
{
  vector<double> matrix;
  //readfile
  fstream file;
  file.open("data.txt");
  string line;
  while (getline( file, line))  //讀一整行放進line
	{
	  istringstream templine(line); // string(line) 轉換成 stringstream
	  string data;
	  while (getline( templine, data,',')) //切逗號放進data
	  {
	    matrix.push_back(atof(data.c_str()));  //string 轉換成數字 存進vector
	  }
	}
  file.close();
  
  for (size_t i=0;i<matrix. size();i++)
  {
    cout << matrix[i]<<" ";
  }	
  cout<<endl;
  return 0;
}