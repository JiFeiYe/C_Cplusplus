/*
#include<stdio.h>

//ÅĞ¶ÏÇ×ºÍÊı
int judge(int A, int B)
{
	int sumA = 1, sumB = 1;
	if (A == B)
	{
		return 0;
	}
	else
	{
		for (int i = 2; i < A; i++)
		{
			if (A % i == 0)
			{
				sumA += i;
			}
		}
		for (int i = 2; i < B; i++)
		{
			if (B % i == 0)
			{
				sumB += i;
			}
		}
		if (sumA == B && sumB == A)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int t = 0, A = 0, B = 0, judge_ = 0;
	scanf_s("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		scanf_s("%d%d", &A, &B);
		judge_ = judge(A, B);
		if (judge_ == 1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
*/