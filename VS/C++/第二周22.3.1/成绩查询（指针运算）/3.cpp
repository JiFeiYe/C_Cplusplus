#include <iostream>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		//动态数组存成绩
		int n = 0;
		cin >> n;
		int* p = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> *(p + j);
		}
		//中间元素
		int* mid = p;
		if (n % 2 == 0)
		{
			mid = p + (n / 2);
		}
		else
		{
			mid = p + ((n + 1) / 2) - 1;
		}
		//输出中间成绩的前一个与后一个成绩
		mid--;
		cout << *(mid) << ' ';
		mid++;
		mid++;
		cout << *(mid) << endl;
		//查询成绩
		int n1 = 0;
		cin >> n1;
		cout << *(p + n1 - 1) << endl;
		delete[] p;
	}
	return 0;
}