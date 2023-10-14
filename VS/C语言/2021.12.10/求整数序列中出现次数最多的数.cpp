//�ݹ飿
/*
#include<stdio.h>

int main()
{
	int N = 0;
	int a[1000] = { 0 };
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &a[i]);
	}
	int count = 0, temp = a[0], max = 1;
	for (int i = 0; i < N; i++)
	{
		count = 0;
		for (int j = 0; j < N; j++)
		{
			if (a[i] == a[j])
			{
				count++;
			}
		}
		if (count > max)
		{
			temp = a[i];
			max = count;
		}
	}
	printf("%d %d", temp, max);
	return 0;
}
*/