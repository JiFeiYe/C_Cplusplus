#include<stdio.h>

//�Զ����� 
int sum(int i) 
{
	int b;
	b = i*2;
	return b;
}

 
int main()
{
	int a[] = {7,2,5};
	int c = 0;
	c = a[1] + sum(a[0]);				//ѡȡ����ĳһԪ�ظ�ֵ���Զ��������м��� 
	printf("%d",c);
	return 0;
}
