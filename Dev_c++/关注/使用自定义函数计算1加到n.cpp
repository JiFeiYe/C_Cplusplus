//���Զ��庯������1�ӵ�n 
#include<stdio.h>

//�Զ��庯��Sum 
int Sum(int m)							//��ʽ����m��Ҳ������������Ϊ��ʽ���� 
{
	int sum = 0;
	for(int i = 1;i <= m;i ++)
	{
		sum += i;
	}
	return sum;							//�Զ��庯������ֵsum 
} 

int main()
{
	int n,result;
	printf("������������n��");
	scanf("%d",&n);						//ʵ�ʲ���n 
	result = Sum(n);
	printf("��1�ӵ�n���ڣ�%d",result);
	
	return 0;
} 
