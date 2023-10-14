/*
#include<stdio.h>
int main()
{
	int digit = 0,a[100] = {0};
	scanf_s("%d", &digit);
	int i = 0;
	if (digit == 0)
	{
		printf("0");
	}
	else
	{
		for (; digit != 0; i++)
		{
			a[i] = digit % 10;
			digit /= 10;
		}
		do
		{
			printf("%d ", a[i - 1]);
			i--;
		} while (i != 0);
	}
	return 0;
}
*/