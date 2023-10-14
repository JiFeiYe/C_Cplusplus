/*
//思路1：用字符串数组直接一个一个统计
//思路2：多数均可（scanf_s可将空格视为结束）
#include<stdio.h>
int main()
{
	int N = 0;
	scanf_s("%d", &N);
	int a = 0, a1 = 0;
	int count[10] = { 0 };
	int count1 = 0;
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &a);
		count1 = 1;
		a1 = a;
		while(1)//计数器
		{
			if (a1 / 10 != 0)
			{
				count1++;
				a1 = a1 / 10;
			}
			else
			{
				break;
			}
		}
		for (int j = 0; j < count1; j++)
		{
			count[a % 10]++;
			a = a / 10;
		}
	}
	//寻找最大数、记录下标count[0123456789]
	int max = 0, max1 = 0;
	max = count[0];
	for (int i = 1; i < 10; i++)
	{
		if (max < count[i])
		{
			max = count[i];
		}
	}
	printf("%d:", max);
	for (int i = 0; i < 10; i++)
	{
		if (count[i] == max)
		{
			printf(" %d", i);
		}
	}
	return 0;
}
*/