//ע��mn��ͬ�����
#include<stdio.h>

//�ж��Ƿ�Ϊ����
int judge (int a)
{
	int sum = 0;
	for (int i = 1;i < a; i++)
	{
		if (a % i == 0)
		{
			sum += i;
		}
	}
	if (sum == a)
		return 1;
	return 0;
}

int main()
{
	int m = 0, n = 0, judge_ = -1, temp = 0;
	scanf("%d%d", &m, &n);
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
		if (temp == n - m + 1 ||(m == n && judge_ == 0))
		{
			printf("None");
			break;
		}
	}
	return 0;
}
