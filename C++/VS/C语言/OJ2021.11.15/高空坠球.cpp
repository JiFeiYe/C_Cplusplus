/*
#include<stdio.h>
#include<math.h>
int main()
{
	double high = 0,journey = 0;			//high��ʼ�߶ȣ�journey��η����󾭹���·��
	scanf_s("%lf", &high);
	int n = 0;
	scanf_s("%d", &n);
	double temp = high;						//����һ��high
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
	double rehigh = 0;						//rehigh��n�η�����߶�
	rehigh = pow(0.5, n) * high;
	printf("%.1f ", journey);
	printf("%.1f", rehigh);
	return 0;
}
*/