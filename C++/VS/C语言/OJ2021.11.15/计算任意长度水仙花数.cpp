/*
#include<stdio.h>
#include<math.h>

//�ж�ˮ�ɻ���
int judge(int n, int N)						//i->n,N->N
{
	int sum = 0 ,n1 = 0;
	n1 = n;									//��ֵһ��n
	for (int i = 1; i <= N; i++)
	{
		sum += pow(n % 10, N);
		n = n / 10;
	}
	if (sum == n1)
	{
		return 1;							//��ˮ�ɻ���
	}
	return 0;								//����ˮ�ɻ���
}


int main()
{
	int N = 0, i = 0, judge_ = 0;
	scanf_s("%d", &N);
	for (i = pow(10, N - 1); i < pow(10, N); i++)
	{
		judge_ = judge(i, N);
		if (judge_ == 1)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}
*/