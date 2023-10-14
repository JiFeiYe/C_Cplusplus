/*
#include<stdio.h>

int main()
{
	int t = 0, flag = 1;
	scanf_s("%d", &t);
	char a[6] = "BDAEC", b[6] = "A";
	for (int i = 1; i <= t; i++)
	{
		flag = 1;
		for (int j = 0; j < 5; j++)
		{
			getchar();
			scanf_s("%c", &b[j]);//***********************
			if (b[j] != a[j])
			{
				flag = 0;
			}
		}
		if (flag == 1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
*/