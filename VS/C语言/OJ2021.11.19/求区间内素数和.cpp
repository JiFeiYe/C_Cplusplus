/*
#include<stdio.h>

//判断素数
int prime(int p)
{
	if (p == 1)
	{
		return 0;						//否
	}
	if (p == 2)
	{
		return 1;						//是
	}
	for (int i = 2; i * i <= p; i++)
	{
		if (p % i == 0)
		{
			return 0;					//否
		}
	}
	return 1;							//是
}

//素数求和
int prime_sum(int m,int n)
{
	int sum = 0;
	printf("Sum of ( ");
	for (int p = m; p <= n; p++)			//p是待测数
	{
		if (prime(p) == 1)					//是
		{
			printf("%d ", p);
			sum += p;
		}
	}
	printf(") = ");
	return sum;
}

int main()
{
	int m = 0, n = 0, prime_sum_ = 0;
	scanf_s("%d%d", &m, &n);
	prime_sum_ = prime_sum(m, n);
	printf("%d", prime_sum_);
	return 0;
}
*/