/*
#include<stdio.h>
int main()
{
	int n = 0, digit = 0, min = 10;
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf_s("%d", &digit);
		min = min > digit ? digit : min;			//三目运算符：将两者中小的那个赋值给min
	}
	printf("min = %d", min);
	return 0;
}
*/