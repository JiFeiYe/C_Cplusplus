/*
#include<stdio.h>
#include<stdio.h>

//�жϻ�����
int text1(int n)
{
	int j = 0, k = 0;
	j = n;
	while (j)
	{
		k = k * 10 + j % 10;		//�������������
		j /= 10;
	}
	if (k == n)
	{
		return 1;					//�ǻ�����
	}
	return 0;						//���ǻ�����
}

//�ж�����
int text2(int n)
{
	if (n == 2)
	{
		return 1;							//������
	}
	else if (n == 1)
	{
		return 0;							//��������
	}
	else
	{
		for (int i = 2; i * i <= n; i++)
		{
			if (n % i == 0)					//��������
			{
				return 0;
			}
		}
	}
	return 1;								//������
}

int main()
{
	int T = 0, n = 0, text1_ = 1, text2_ = 1;					//T�����������nΪ������
	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf_s("%d", &n);
		text1_ = text1(n);
		text2_ = text2(n);
		if (text1_ == 1 && text2_ == 1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
*/