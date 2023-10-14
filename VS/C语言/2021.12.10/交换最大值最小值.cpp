/*
#include<stdio.h>
int main()
{
	int N = 0;
	scanf_s("%d", &N);
	int a[N] = { 0 };
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &a[i]);
	}
	int min = 0, min1 = 0;
	min = a[0];
	for (int i = 1; i < N; i++)
	{
		if (min >= a[i])
		{
			min = a[i];
			min1 = i;
		}
	}
	int temp = 0;
	temp = a[0];
	a[0] = min;
	a[min1] = temp;

	int max = 0, max1 = 0;
	max = a[1];
	for (int i = 1; i < N; i++)
	{
		if (max <= a[i])
		{
			max = a[i];
			max1 = i;
		}
	}
	temp = a[N-1];
	a[N - 1] = max;
	a[max1] = temp;
	for (int i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
*/