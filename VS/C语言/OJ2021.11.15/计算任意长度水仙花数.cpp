/*
#include<stdio.h>
#include<math.h>

//判断水仙花数
int judge(int n, int N)						//i->n,N->N
{
	int sum = 0 ,n1 = 0;
	n1 = n;									//赋值一个n
	for (int i = 1; i <= N; i++)
	{
		sum += pow(n % 10, N);
		n = n / 10;
	}
	if (sum == n1)
	{
		return 1;							//是水仙花数
	}
	return 0;								//不是水仙花数
}


int main()
{
	int N = 0, i = 0, judge_ = 0;
	scanf_s("%d", &N);
	for (i = pow(10, N - 1); i < pow(10, N); i++)
	{
		judge_ = judge(i, N);
		if (judge_ == 1)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
*/