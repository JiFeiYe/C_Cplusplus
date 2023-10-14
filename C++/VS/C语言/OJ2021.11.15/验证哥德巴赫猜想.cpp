/*
#include<stdio.h>

//判断素数
int judge(int n)
{
	int i = 0;
	if (n == 1)
	{
		return 0;							//不是素数
	}
	if (n == 2)
	{
		return 1;							//是素数
	}
	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return 0;						//不是素数
		}
	}
	return 1;								//是素数
}

int main()
{
	int N = 0;
	scanf_s("%d", &N);
	for (int i = 1; i <= N/2; i++)
	{
		if (judge(i) && judge(N - i))
		{
			printf("%d = %d + %d", N, i, N - i);
			break;
		}
	}
	return 0;
}
*/