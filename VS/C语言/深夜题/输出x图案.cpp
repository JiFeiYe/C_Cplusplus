#include<stdio.h>

void print(int n)
{
	//�����x
	int temp1 = 0;
	for (int i = n; i >= 1; i--)
	{
		temp1 = i;
		while (temp1 != n)
		{
			printf(" ");//ͷ�ո�
			temp1++;
		}
		printf("x");
		for (int j = 1; j <= i * 2 - 1; j++)
		{
			printf(" ");//�м�ո�
		}
		printf("x\n");
	}
	
	//���м��x
	for (int i = 1; i <= n; i++)
	{
		printf(" ");//ͷ�ո�
	}
	printf("x\n");

	//�����x
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n - i; j++)
		{
			printf(" ");//ͷ�ո�
		}
		printf("x");
		for (int j = 1; j <= 2 * i - 1; j++)
		{
			printf(" ");//�м�ո�
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