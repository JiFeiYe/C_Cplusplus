/*
#include<stdio.h>

int main()
{
	int n = 0;
	scanf_s("%d", &n);
	getchar();
	char a[10][10] = {' '};
	char text = ' ';
	for (int i = 0; i < 2 * n; i++)//数组输入
	{
		for (int j = 0; j < 2 * n; j++)
		{
			scanf_s("%c", &a[i][j]);
			getchar();
		}
	}


	int k = 0;
	scanf_s("%d", &k);
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	int count = 0, count1 = 0;
	for (int l = 0; l < k; l++)
	{
		scanf_s("%d%d%d%d", &x1, &y1, &x2, &y2);//选择目标
		x1 = x1 - 1;
		y1 = y1 - 1;
		x2 = x2 - 1;
		y2 = y2 - 1;
		if (a[x1][y1] == a[x2][y2] && a[x1][y1] != '*' && a[x2][y2] != '*')//判断相等
		{
			a[x1][y1] = '*';
			a[x2][y2] = '*';
		}
		else
		{
			printf("Uh-oh\n");
			count++;
			continue;
		}


		count1 = 0;
		for (int i = 0; i < 2 * n; i++)//遍历数组判断是否全为'*'
		{
			for (int j = 0; j < 2 * n; j++)
			{
				if (a[i][j] == '*')
				{
					count1++;
				}
			}
		}
		if (count1 == 4 * n * n)
		{
			printf("Congratulations!");
			return 0;
		}
		else if (count == 3)
		{
			printf("Game Over");
			return 0;
		}


		for (int i = 0; i < 2 * n; i++)//输出当前数组内容
		{
			printf("%c", a[i][0]);
			for (int j = 1; j < 2 * n; j++)
			{
				printf(" %c", a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
*/