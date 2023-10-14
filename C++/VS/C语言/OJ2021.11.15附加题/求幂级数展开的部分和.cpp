/*
#include<stdio.h>
#include<math.h>
int main()
{
	double x = 0, sum = 0, last = 1;
	scanf_s("%lf", &x);
	double k_ = 1;
	for (double k = 0; fabs(last) >= 0.00001; k++)
	{
		//先求k阶乘
		for (double i = k; i != 0; i--)
		{
			k_ *= i;
		}
		//再求表达式和
		sum += pow(x, k) / k_;
		last = pow(x, k) / k_;
		k_ = 1;
	}
	printf("%.4f", sum);
	return 0;
}
*/