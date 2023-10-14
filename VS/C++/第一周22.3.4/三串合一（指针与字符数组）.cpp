/*
#include <iostream>

using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	char a1[10] = { ' ' }, a2[10] = { ' ' }, a3[10] = { ' ' };
	
	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> a1[j];
		}
		for (int j = 0; j < 10; j++)
		{
			cin >> a2[j];
		}
		for (int j = 0; j < 10; j++)
		{
			cin >> a3[j];
		}
		int temp = 0, sum = 0, a = 0, b = 0,c = 0;
		char* p = new char[30];
		for (int k = 0; k < 3; k++)
		{
			cin >> a >> b;
			c = a;
			if (k == 0)
			{
				for (c--; c < b; c++)
				{
					*(p + temp) = a1[c];
					temp++;
				}
				sum += (b - a + 1);
			}
			else if (k == 1)
			{
				for (c--; c < b; c++)
				{
					*(p + temp) = a2[c];
					temp++;
				}
				sum += (b - a + 1);
			}
			else if (k == 2)
			{
				for (c--; c < b; c++)
				{
					*(p + temp) = a3[c];
					temp++;
				}
				sum += + (b - a + 1);
			}
		}
		for (int l = 0; l < sum; l++)
		{
			cout << *(p+l);
		}
		cout << endl;
		delete[] p;
	}
	
	return 0;
}
*/