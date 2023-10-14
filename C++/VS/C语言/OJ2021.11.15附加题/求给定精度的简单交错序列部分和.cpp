/*
#include<stdio.h>
#include<math.h>
int main()
{
	int flag = 1;
	double eps = 0, sum = 0,temp = 0;
	scanf_s("%lf", &eps)
	eps = fabs(eps);
	double i = 1;
	temp = fabs(1 / i);
	for (i = 1; temp > eps; i += 3)
	{
		sum += flag * 1 / i;
		flag *= -1;
		temp = fabs(1 / i);
	}
	printf("sum = %.6f", sum);
	return 0;
}
*/