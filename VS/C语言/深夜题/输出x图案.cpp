#include<stdio.h>

void print(int n)
{
	//上面的x
	int temp1 = 0;
	for (int i = n; i >= 1; i--)
	{
		temp1 = i;
		while (temp1 != n)
		{
			printf(" ");//头空格
			temp1++;
		}
		printf("x");
		for (int j = 1; j <= i * 2 - 1; j++)
		{
			printf(" ");//中间空格
		}
		printf("x\n");
	}
	
	//正中间的x
	for (int i = 1; i <= n; i++)
	{
		printf(" ");//头空格
	}
	printf("x\n");

	//下面的x
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n - i; j++)
		{
			printf(" ");//头空格
		}
		printf("x");
		for (int j = 1; j <= 2 * i - 1; j++)
		{
			printf(" ");//中间空格
		}
		printf("x\n");
	}
	return;
}

int main()
{
	int T = 0, n = 0;
	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf_s("%d", &n);
		print(n);
		printf("END\n");
	}
	return 0;
}