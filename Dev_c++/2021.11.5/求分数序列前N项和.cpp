#include<stdio.h>
int main()
{
	double a = 2;					//���� 
	double b = 1;					//��ĸ 
	double c = 0, N = 0, sum = 0;	//c�м��� 
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
