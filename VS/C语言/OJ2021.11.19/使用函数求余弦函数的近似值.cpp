/*
#include<stdio.h>
#include<math.h>

//��׳�
int factorial(int i)
{
	int factorial_ = 1;
	for (int j = i; j != 0; j--)
	{
		factorial_ *= j;
	}
	return factorial_;
}
//�����Һ�������ֵ
double funcos(double eps, double x)
{
	double last = 1, funcos_ = 0, flag = 1;
	for (int i = 0; last >= eps; i += 2)
	{
		funcos_ = funcos_ + flag * pow(x, i) / factorial(i);
		flag = -flag;
		last = pow(x, i) / factorial(i);
	}
	return funcos_;
}
int main()
{
	double eps = 0, x = 0;
	scanf_s("%lf%lf", &eps, &x);
	printf("cos(%.2f) = ", x);
	printf("%.6f", funcos(eps, x));
	return 0;
}
*/