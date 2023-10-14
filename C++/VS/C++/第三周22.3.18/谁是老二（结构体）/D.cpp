#include <iostream>
using namespace std;

int count(int year, int month, int day)
{
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int sum = 365; int num = 0;
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)//Âú×ã¼´ÈòÄê
	{
		sum = 366; a[2] = 29;
	}
	for (int i = 0; i <= month; i++)
	{
		num += a[i];
	}
	num += day;
	return num;
}

int main()
{
	struct birthday
	{
		int year[50];
		int month[50];
		int day[50];
	}a;
	int t = 0;
	cin >> t;
	int* num = new int[t];
	for (int i = 0; i < t; i++)
	{
		cin >> a.year[i] >> a.month[i] >> a.day[i];
		*(num + i) = a.year[i]*1000 + count(a.year[i], a.month[i], a.day[i]);
	}
	
	/*
	//Ã°ÅİÅÅĞò
	int temp = 0;
	for (int j = 0; j < t - 1; j++)//t¸öÊı£¬¹²t-1ÂÖ
	{
		for (int i = 0; i < t - 1 - j; i++)
		{
			if (num[i] > num[i + 1])
			{
				temp = num[i];
				num[i] = num[i + 1];
				num[i + 1] = temp;
			}
		}
	}
	*/
	int min = num[0], minindex = 0, minindex1 = 0;
	for (int i = 0; i < t; i++)
	{
		if (min > num[i])
		{
			min = num[i];
			minindex = i;
		}
	}
	min = 99999999;
	for (int i = 0; i < t; i++)
	{
		if (i == minindex)
		{
			continue;
		}
		if (min > num[i])
		{
			min = num[i];
			minindex1 = i;//ÀÏ¶ş
		}
	}
	cout << a.year[minindex1] << "-" << a.month[minindex1] << "-" << a.day[minindex1] << endl;
	delete[] num;
	return 0;
}