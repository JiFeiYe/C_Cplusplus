/*
#include<stdio.h>

//��׳�
double factorial(int n)//i -> n,���i�Ľ׳�
{
	double result = 1;
	for (double i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

double multiply(int m)//i -> m,����3*5*7*...��i��
{
	double result = 1;
	int count = 0;
	for (int i = 3; ; i += 2)
	{
		result *= i;
		count++;
		if (count == m)
		{
			return result;
		}
	}
}

int main()
{
	double eps = 0, halfPi = 1, Pi = 0, temp = 1.01;
	scanf_s("%lf", &eps);
	for (int i = 1; temp >= eps; i++)
	{
		halfPi += (factorial(i) / multiply(i));
		temp = factorial(i) / multiply(i);
	}
	Pi = 2 * halfPi;
	printf("PI = %.5f", Pi);
	return 0;
}
*/