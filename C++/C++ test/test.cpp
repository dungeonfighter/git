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
#include <time.h>
using namespace std;
size_t range = 100;

void func(int index, const vector<vector<double>> &data, vector<double> &result)
{
	//cout << "new thread :" << index << endl;

	for (size_t i = 0; i < range; i++)
	{
		result[index] += (data[index][i] / range)*2;
	}
	string name = to_string( index ) + "thread_out.txt";
	fstream file;
	file.open(name.c_str(), ios::out);
	if (!file)
	{
		cout << "error open" << endl;
	}
	else
	{
		for (size_t i = 0; i < range; i++)
		{
			file << data[index][i] << endl;
		}
		 file.close();
	}
}

void normal(const vector<vector<double>> &data, vector<double> &result)
{
	for (size_t i = 0; i < range; i++)
	{
		for (size_t j = 0; j < range; j++)
		{
			result[i] += (data[i][j] / range)*2;
		}
		string name = to_string(i) + "ordinary_out.txt";
		fstream file;
		file.open(name.c_str(), ios::out);

		if (!file)
		{
			cout << "error open" << endl;
		}
		else
		{
			for (size_t k = 0; k < range; k++)
			{
				file << data[i][k]<< endl;
			}
			file.close();
		}
	}
}

int main(int argc, char *argv[])
{
	double START, END;
	

	vector<vector<double>> data;
	data.resize(range);
	for (size_t i = 0; i < range; i++)
	{
		data[i].resize(range);
	}
	for (size_t i = 0; i < range; i++)
	{
		for (size_t j = 0; j < range; j++)
		{
			data[i][j] = i + (j + 1);
		}
	}

	vector<double> average;
	average.resize(range);
	
	vector<thread> threads;
	threads.reserve(range);
	for (size_t i = 0; i < range; i++)
	{
		threads.push_back(thread(func, i, ref(data), ref(average)));
	}
	START = clock();
	
	for (size_t i = 0; i < threads.size(); i++)
	{
		threads[i].join();
	}
	
	//normal(data, average);

	END = clock();
	

	for (size_t i = 0; i < range; i++)
	{
		//cout << average[i] << endl;
	}
	cout << endl
		 << "time comsuming ： " << (END - START) / CLOCKS_PER_SEC << " S" << endl;
	//system("vim data.txt");
	return 0;
}
