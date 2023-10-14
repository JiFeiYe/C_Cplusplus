/*
#include<stdio.h>

//判断素数
int judge(int a)
{
	int i = 0;
	if (a == 1)
	{
		return 0;							//不是素数
	}
	for (i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			return 0;						//不是素数
		}
	}
	return 1;								//是素数
}
int main()
{
	int b[16383] = {0}, n = 0, count = 0;				//b数组存素数，n用于判断，count计数器
	for (int a = 2; a <= 180500; a++)					/*****a是每一个待测数, ，从二开始，区间是条件二****
	{
		n = judge(a);
		if (n == 1)
		{
			b[count] = a;
			count++;
		}
	}
	for (int i = 0; i < 16383; i++)
	{
		printf("%d\t", b[i]);
	}
	return 0;
}
*/