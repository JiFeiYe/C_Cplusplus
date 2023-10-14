/*
#include<stdio.h>
int main()
{
	//获取数组*2
	int N1 = 0, N2 = 0;
	int a1[20] = { 0 }, a2[20] = { 0 };
	scanf_s("%d", &N1);
	for (int i = 0; i < N1; i++)
	{
		scanf_s("%d", &a1[i]);
	}
	scanf_s("%d", &N2);
	for (int i = 0; i < N2; i++)
	{
		scanf_s("%d", &a2[i]);
	}
	//遍历数组
	int flag = 1, index = 0;
	int any[40] = { 0 };
	for (int i = 0; i < N1; i++)
	{
		flag = 1;
		for (int j = 0; j < N2; j++)
		{
			if (a1[i] == a2[j])
			{
				flag = 0;
			}
		}
		if (flag == 1)
		{
			any[index] = a1[i];
			index++;
		}
	}
	for (int i = 0; i < N2; i++)
	{
		flag = 1;
		for (int j = 0; j < N1; j++)
		{
			if (a2[i] == a1[j])
			{
				flag = 0;
			}
		}
		if (flag == 1)
		{
			any[index] = a2[i];
			index++;
		}
	}
	//输出结果（不重复）
	printf("%d", any[0]);
	for (int i = 1; i < index; i++)
	{
		flag = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (any[j] == any[i])
			{
				flag = 0;
			}
		}
		if (flag == 1)
		{
			printf(" %d", any[i]);
		}
	}
	return 0;
}
*/