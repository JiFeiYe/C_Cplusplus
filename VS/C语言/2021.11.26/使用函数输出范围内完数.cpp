/*
#include<stdio.h>

//�������
int factorsum(int number) {
	int sum = 0;
	for (int i = 1; i < number; i++)
	{
		if (number % i == 0)
		{
			sum += i;
		}
	}
	return sum;
}

//�ж��Ƿ�Ϊ����
int judge(int a)
{
	int sum = 0;
	sum = factorsum(a);
	if (sum == a)
		return 1;
	return 0;
}

//������
void print_n(int m, int n) {
	int judge_ = -1, temp = 0;
	scanf_s("%d%d", &m, &n);
	for (int a = m; a <= n; a++)
	{
		judge_ = judge(a);
		if (judge_ == 1)
		{
			printf("%d = ", a);
			for (int i = 1; i <= a / 2; i++)
			{
				if (a % i == 0 && i != a / 2)		//�м�ļ���
				{
					printf("%d + ", i);
				}
				if (a % i == 0 && i == a / 2)		//���һ������
				{
					printf("%d\n", i);
				}
			}
		}
		if (judge_ == 0)							//ǰ����ȫû������
		{
			temp++;
		}
		if (temp == (n - m + 1) || (m == n && judge_ == 0))
		{
			printf("No perfect number");
			break;
		}
	}
	return;
}

int main() {
	int m = 0, n = 0;
	print_n(m, n);
	return 0;
}
*/