/*
#include<stdio.h>

//�ж�����
int judge(int a)
{
	int i = 0;
	if (a == 1)
	{
		return 0;							//��������
	}
	for (i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			return 0;						//��������
		}
	}
	return 1;								//������
}
int main()
{
	int b[16383] = {0}, n = 0, count = 0;				//b�����������n�����жϣ�count������
	for (int a = 2; a <= 180500; a++)					/*****a��ÿһ��������, ���Ӷ���ʼ��������������****
	{
		n = judge(a);
		if (n == 1)
		{
			b[count] = a;
			count++;
		}
	}
	for (int i = 0; i < 16383; i++)
	{
		printf("%d\t", b[i]);
	}
	return 0;
}
*/