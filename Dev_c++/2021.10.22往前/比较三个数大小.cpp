//����������ͬ���������Ƚϴ�С��Ӵ�С��� 
#include<stdio.h>
int main()
{
	int a,b,c;
	printf("����������ͬ������:\n"); 
	scanf("%d %d %d",&a,&b,&c);					//�������� 
	int t;
	if(b>a)										//�Ƚϴ�С���� 
	{
		t = a;
		a = b;
		b = a;
	}
	if(a<c)
	{
		t = a;
		a = c;
		c = t;
	}
	if(c>b)
	{
		t = b;
		b = c;
		c = t;
	}											//�ȽϽ��� 
	printf("%d > %d > %d\n",a,b,c);
	return 0;
} 
