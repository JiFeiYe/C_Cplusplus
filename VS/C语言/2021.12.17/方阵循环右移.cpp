/*
#include<stdio.h>
int main()
{
	int m = 0, n = 0;
	scanf_s("%d%d", &m, &n);
	int a[6][12] = { 0 };
	m = m % n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= 0; j--)
		{
			a[i][j + m] = a[i][j];
		}
		for (int j = n; j <= n - 1 + m; j++)
		{
			a[i][j - n] = a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
*/