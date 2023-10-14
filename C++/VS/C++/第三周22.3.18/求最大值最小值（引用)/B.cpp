#include <iostream>
using namespace std;

void find(int* num, int n, int& minIndex, int& maxIndex)
{
	int min = *num, max = *num;
	for (int i = 0; i < n; i++)
	{
		if (min > *(num + i))
		{
			min = *(num + i);
			minIndex = i;
		}
		if (max < *(num + i))
		{
			max = *(num + i);
			maxIndex = i;
		}
	}
	return;
}
int main()
{
	int t = 0;
	cin >> t;
	while (t--)
	{
		int minIndex = 0, maxIndex = 0;
		int n = 0;
		cin >> n;
		int* num1 = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> num1[i];
		}
		find(num1, n, minIndex, maxIndex);
		cout << "min=" << num1[minIndex] << " minindex=" << minIndex << endl;
		cout << "max=" << num1[maxIndex] << " maxindex=" << maxIndex << endl;
		cout << endl;
		delete[] num1;
	}
	return 0;
}