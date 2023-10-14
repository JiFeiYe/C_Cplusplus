/*
#include<stdio.h>
int main()
{
	int N = 0;
	scanf("%d", &N);
	int a[N + 1] = { 0 };
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	int x = 0;
	scanf("%d", &x);
	for (int i = 0; i < N; i++)
	{
		if (x <= a[i])
		{
			for (int j = N; j > i; j--)
			{
				a[j] = a[j - 1];
			}
			a[i] = x;
			break;
		}
	}
	for (int i = 0; i <= N; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
*/