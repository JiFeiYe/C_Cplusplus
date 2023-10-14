/*
#include<stdio.h>

//判断素数
int test(int a)
{
	if (a == 2)
	{
		return 1;
	}
	else if (a == 1)
	{
		return 0;
	}
	else
	{
		for (int i = 2; i * i <= a; i++)
		{
			if (a % i == 0)					//不是素数
			{
				return 0;
			}
		}
	}
	return 1;								//是素数
}

int main()
{
	int a = 0, M = 0, N = 0, count = 0, sum = 0, temp = 0;
	scanf_s("%d%d", &M, &N);
	for (a = M; a <= N; a++)
	{
		temp = test(a);
		if (temp == 1)
		{
			sum += a;
			count++;
		}
	}
	printf("%d %d", count, sum);
	return 0;
}
*/