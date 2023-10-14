#include<stdio.h>
int main()
{
	double a = 2;					//分子 
	double b = 1;					//分母 
	double c = 0, N = 0, sum = 0;	//c中间项 
	scanf("%lf",&N);
	for(int i = 1;i <= N;i ++)
	{
		sum += a/b;
		c = a+b;
		b = a;
		a = c;
	}
	printf("%.2f",sum);
	return 0;
} 
