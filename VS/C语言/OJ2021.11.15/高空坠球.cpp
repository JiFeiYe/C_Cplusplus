/*
#include<stdio.h>
#include<math.h>
int main()
{
	double high = 0,journey = 0;			//high初始高度，journey多次反弹后经过的路程
	scanf_s("%lf", &high);
	int n = 0;
	scanf_s("%d", &n);
	double temp = high;						//复制一个high
	if (n == 1)
	{
		journey = high;
	}
	else
	{
		journey = high;
		for (int i = 1; i != n; i++)
		{
			journey += temp;
			temp /= 2;
		}
	}
	double rehigh = 0;						//rehigh第n次反弹后高度
	rehigh = pow(0.5, n) * high;
	printf("%.1f ", journey);
	printf("%.1f", rehigh);
	return 0;
}
*/