/*
#include<stdio.h>
void order(int* p, int n)
{
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (*(p + j) < *(p + j - 1))//��С����
			{
				temp = *(p + j);
				*(p + j) = *(p + j - 1);
				*(p + j - 1) = temp;
			}
		}
	}
	return;
}
int main()
{
	int a[50] = { 0 }, n = 0;
	printf("����������Ԫ�ظ�����");
	scanf_s("%d", &n);
	printf("���������Ԫ�أ�");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", a + i);
	}
	order(a, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", *(a + i));
	}
	return 0;
}
*/