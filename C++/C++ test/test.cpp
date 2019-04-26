#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <thread>
using namespace std;
size_t range = 10;

void func(int index, const vector< vector<double> >&data , vector<double>&result)
{
	cout << "new thread :" << index << endl;
	
	for (size_t i = 0; i < range; i++)
	{
		result[index] += data[index][i];
	}
	
	
}
int main(int argc, char *argv[])
{
	vector< vector<double> > data;
	data.resize(range);
	for (size_t i = 0; i < range; i++)
	{
		data[i].resize(range);
	}
	for (size_t i = 0; i < range; i++)
	{
		for (size_t j = 0; j < range; i++)
		{
			data[i][j] = i + j;
		}
	}

	vector<double> average ;
	average.resize(range);

	vector<thread> threads;
	for (size_t i = 0; i < range; i++)
	{
		threads.push_back(thread(func, i, ref(data) , ref(average) ));
	}
	for (size_t i = 0; i < threads.size(); i++)
	{
		threads[i].join();
	}

	for (size_t i = 0; i < range; i++)
	{
		cout<<average[i]<<endl;
	}
	
	//system("vim data.txt");
	return 0;
}
