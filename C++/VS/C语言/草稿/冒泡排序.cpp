/*
#include<stdio.h>
int main()
{
	int a[5] = { 9,8,10,21,2 };
	int temp = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 4; j > i; j--)
		{
			if (a[j] >= a[j - 1])//从大到小
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}
*/