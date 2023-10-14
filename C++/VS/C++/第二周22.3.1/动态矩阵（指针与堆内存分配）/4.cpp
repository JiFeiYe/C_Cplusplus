#include <iostream>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int row = 0, column = 0;
		cin >> row >> column;
		int** a = new int* [row];
		for (int j = 0; j < row; j++)
		{
			a[j] = new int[column];
		}
		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < column; k++)
			{
				a[j][k] = 0;
			}
		}
		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < column; k++)
			{
				cin >> a[j][k];
			}
		}
		int max = a[0][0], min = a[0][0];
		for (int j = 0; j < row; j++)
		{
			for (int k = 0; k < column; k++)
			{
				if (max < a[j][k])
				{
					max = a[j][k];
				}
				if (min > a[j][k])
				{
					min = a[j][k];
				}
			}
		}
		cout << min << ' ' << max << endl;
		for (int j = 0; j < row; j++)
		{
			delete[] a[j];
		}
		delete[] a;
	}
	return 0;
}