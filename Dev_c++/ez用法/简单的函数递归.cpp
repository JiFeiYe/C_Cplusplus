#include<stdio.h>

//����򵥺��� 
void number(int a)
{
	int num = a;
	printf("����һ��������");
	scanf("%d",&num);
	if(num <= 0)
	{
		number(num);
	}
	else
	{
		printf("��������ǣ�%d",num);
	}
} 

//������ 
int main()
{
	int a; 
	number(a);
	return 0;
}
