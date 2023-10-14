/*
#include<stdio.h>
int main()
{
	int a[10][10] = { 0 };
	int T = 0;
	scanf_s("%d", &T);
	int R = 0, flag = 1;
	for (int t = 0; t < T; t++)
	{
		flag = 1;
		scanf_s("%d", &R);
		//输入二维数组
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < R; j++)
			{
				scanf_s("%d", &a[i][j]);
			}
		}
		//判断
		for (int i = R - 1; i > 0; i--)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				if (a[i][j] != 0)
					flag = 0;
			}
		}
		if (flag == 1)
			printf("YES\n");
		else if (flag == 0)
			printf("NO\n");
	}
	return 0;
}
*/