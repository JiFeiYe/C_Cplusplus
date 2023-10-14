/*
#include<stdio.h>

//打印金字塔
void hollow_pyramid(int n)
{
	int j = 0, k = 0, l = 0;
	for (int i = 1; i <= n; i++)				//第i行
	{
		for (j = n - i; j != 0; j--)			//左侧空格
		{
			printf(" ");
		}
		if (i == 1)
		{
			printf("%d\n", i);
		}
		else if (i != n)
		{
			printf("%d", i);
			for (j = 1; j <= 2 * (i) - 3; j++)
			{
				printf(" ");
			}
			printf("%d\n", i);
		}
		else
		{
			for (j = 1; j <= 2 * (i) - 1; j++)
			{
				printf("%d", i);
			}
		}
	}
	return;
}

int main()
{
	int n = 0;
	scanf_s("%d", &n);
	hollow_pyramid(n);
	return 0;
}
*/