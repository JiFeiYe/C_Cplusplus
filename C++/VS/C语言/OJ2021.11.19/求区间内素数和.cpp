/*
#include<stdio.h>

//�ж�����
int prime(int p)
{
	if (p == 1)
	{
		return 0;						//��
	}
	if (p == 2)
	{
		return 1;						//��
	}
	for (int i = 2; i * i <= p; i++)
	{
		if (p % i == 0)
		{
			return 0;					//��
		}
	}
	return 1;							//��
}

//�������
int prime_sum(int m,int n)
{
	int sum = 0;
	printf("Sum of ( ");
	for (int p = m; p <= n; p++)			//p�Ǵ�����
	{
		if (prime(p) == 1)					//��
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