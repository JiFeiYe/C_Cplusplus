#include<stdio.h>
int main()
{
	int a1,b1,c1;				//��������A�����
	int a2,b2,c2;				//��������B�����
	int t;						//�������t 
	int j;						//���ڱȽϴ�С 
	scanf("%d",&t);
	for(int i = 1;i <= t;i ++)
	{
		scanf("%d %d %d",&a1,&b1,&c1);
		scanf("%d %d %d",&a2,&b2,&c2);
		if(a1<b1)								//A�鿪ʼ���� 
		{										 
			j = a1;
			a1 = b1;
			b1 = j;
		}
		if(a1<c1)
		{
			j = a1;
			a1 = c1;
			c1 = j;
		}
		if(b1<c1)
		{
			j = b1;
			b1 = c1;
			c1 = j;
		}										//a1>b1>c1 
		if(a2<b2)								//B�鿪ʼ���� 
		{
			j = a2;
			a2 = b2;
			b2 = j;
		}
		if(a2<c2)
		{
			j = a2;
			a2 = c2;
			c2 = j;
		}
		if(b2<c2)
		{
			j = b2;
			b2 = c2;
			c2 = j;								//a2>b2>c2
		}										//������� 
		if(a1>a2 && b1>b2 && c1>c2) 
		{
			printf("yes\n");
		}
		else if(a1<a2 && b1<b2 && c1<c2)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	} 
	return 0;
} 
