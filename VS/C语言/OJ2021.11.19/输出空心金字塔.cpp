/*
#include<stdio.h>

//��ӡ������
void hollow_pyramid(int n)
{
	int j = 0, k = 0, l = 0;
	for (int i = 1; i <= n; i++)				//��i��
	{
		for (j = n - i; j != 0; j--)			//���ո�
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