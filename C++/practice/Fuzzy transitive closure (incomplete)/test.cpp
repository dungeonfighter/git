#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

//fuzzy : transitive closure

double matrix[7][7] = {
	//origin
	{1, 0, 0.8, 0, 0.6, 0.8, 0},
	{0, 1, 0, 0.6, 0, 0.5, 0},
	{0.8, 0, 1, 0.8, 0, 0, 0},
	{0, 0.6, 0.8, 1, 0, 0, 0.8},
	{0.6, 0, 0, 0, 1, 0.6, 0},
	{0.8, 0.5, 0, 0, 0.6, 1, 0},
	{0, 0, 0, 0.8, 0, 0, 1},

};
double matrix_0[7][7]; //MR
double matrix_1[7][7]; //R'
double find_max(double temp[])
{
	double max = temp[0];
	for (size_t i = 0; i < 7; i++)
	{
		if (temp[i] > max)
		{
			max = temp[i];
		}
	}
	return max;
}
int main()
{
	for (size_t i = 0; i < 7; i++)
	{
		for (size_t j = 0; j < 7; j++)
		{
			matrix_0[i][j] = matrix[i][j];
			matrix_1[i][j] = matrix[i][j];
		}
	}

	while (true)
	{
		bool eq = true;
		//o
		for (size_t i = 0; i < 7; i++)
		{

			for (size_t j = 0; j < 7; j++)
			{
				double temp[7] = {0};

				for (size_t k = 0; k < 7; k++)
				{
					temp[k] = (matrix_0[i][k] < matrix_0[k][j]) ? matrix_0[i][k] : matrix_0[k][j];
				}

				matrix_1[i][j] = find_max(temp);
			}
		}
		//U
		for (size_t i = 0; i < 7; i++)
		{

			for (size_t j = 0; j < 7; j++)
			{

				matrix_1[i][j] = (matrix_1[i][j] > matrix[i][j]) ? matrix_1[i][j] : matrix[i][j];
			}
		}
		//R' == R ??
		for (size_t i = 0; i < 7; i++)
		{

			for (size_t j = 0; j < 7; j++)
			{

				if (matrix_1[i][j] != matrix_0[i][j])
				{
					eq = false;
					break;
				}
			}
		}

		if (eq)
			break;
		else
		{
			for (size_t i = 0; i < 7; i++)
			{
				for (size_t j = 0; j < 7; j++)
				{
					matrix_0[i][j] = matrix_1[i][j];
					
				}
			}
		}
	}

	for (size_t i = 0; i < 7; i++)
	{
		for (size_t j = 0; j < 7; j++)
		{
			cout << matrix_1[i][j] << "	";
		}
		cout << endl;
	}

	cout << endl;

	for (size_t i = 0; i < 7; i++)
	{
		for (size_t j = 0; j < 7; j++)
		{
			if(matrix_1[i][j] >= 0.6)
				cout << "1" << "	";
			else{
				cout << "0" << "	";
			}
		}
		cout << endl;
	}

	cout << endl;

	for (size_t i = 0; i < 7; i++)
	{
		for (size_t j = 0; j < 7; j++)
		{
			if(matrix_1[i][j] >= 0.8)
				cout << "1" << "	";
			else{
				cout << "0" << "	";
			}
		}
		cout << endl;
	}

	cout << endl;

	for (size_t i = 0; i < 7; i++)
	{
		for (size_t j = 0; j < 7; j++)
		{
			if(matrix_1[i][j] >= 1)
				cout << "1" << "	";
			else{
				cout << "0" << "	";
			}
		}
		cout << endl;
	}

	return 0;
}
