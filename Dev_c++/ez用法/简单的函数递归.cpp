#include<stdio.h>

//定义简单函数 
void number(int a)
{
	int num = a;
	printf("输入一个正数：");
	scanf("%d",&num);
	if(num <= 0)
	{
		number(num);
	}
	else
	{
		printf("这个正数是：%d",num);
	}
} 

//主函数 
int main()
{
	int a; 
	number(a);
	return 0;
}
