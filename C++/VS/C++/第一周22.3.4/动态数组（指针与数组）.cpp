/*
#include<iostream>

using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	char type = ' ';
	int n = 0;
	for (int i = 0; i < t; i++)
	{
		cin >> type >> n;
		if (type == 'I')
		{
			int* p = new int[n];
			int sum = 0;
			for (int j = 0; j < n; j++)
			{
				cin >> *(p + j);
				sum += *(p + j);
			}
			cout << sum / n << endl;
			delete[] p;
		}
		else if (type == 'C')
		{
			char* p = new char[n];
			char temp = 'A';
			for (int j = 0; j < n; j++)
			{
				cin >> *(p + j);
				if (*(p + j) >= temp)
				{
					temp = *(p + j);
				}
			}
			cout << temp << endl;
			delete[] p;
		}
		else if (type == 'F')
		{
			double* p = new double[n];
			int flag = 1;
			double temp = 0;
			for (int j = 0; j < n; j++)
			{
				cin >> *(p + j);
				if (flag == 1)
				{
					temp = *p;
					flag = 0;
				}
				if (*(p + j) <= temp)
				{
					temp = *(p + j);
				}
			}
			cout << temp << endl;
			delete[] p;
		}
	}
	return 0;
}
*/