/*
#include<stdio.h>
int main()
{
	int n = 0;
	scanf_s("%d", &n);
	int a[6][6] = { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	int max = 0, min = 0, count = 0;
	int mem1 = 0, mem2 = 0;
	for (int i = 0; i < n; i++)
	{
		count = 0;
		max = a[i][0];
		mem1 = -1, mem2 = -1;
		for (int j = 0; j < n; j++)
		{
			if (max <= a[i][j])
			{
				max = a[i][j];
				mem1 = i; mem2 = j;
			}

		}
		for (int k = 0; k < n; k++)
		{
			if (max <= a[k][mem2])
			{
				count++;
			}
		}
		if (count == n)
		{
			break;
		}
		else
		{
			mem1 = -1; mem2 = -1;
		}
	}
	if (mem1 == -1 && mem2 == -1)
	{
		printf("NONE");
	}
	else
	{
		printf("%d %d", mem1, mem2);
	}
	return 0;
}
*/