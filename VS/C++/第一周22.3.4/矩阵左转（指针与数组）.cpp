
#include <iostream>

using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	for (int l = 0; l < t; l++)
	{
		int a[2][3] = { '0' };
		int* p = a[0];
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> a[i][j];
			}
		}
		/*
		int** p = new int*[3];//三列
		for (int i = 0; i < 3; i++)
		{
			p[i] = new int[2];//两行
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> p[i][j];
			}
		}
		

		for (int i = 0; i < 2; i++)
		{
			for (int j = 2; j >= 0; j--)
			{
				
			}
			cout << endl;
		}
		*/
		for (int j = 2; j >= 0; j--)
		{
			for (int i = 0; i < 2; i++)
			{
				cout << *(p + i * 3 + j) << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}
