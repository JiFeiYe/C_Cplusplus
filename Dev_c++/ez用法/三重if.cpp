#include<stdio.h>
int main()
{
	int i;
	printf("输入一个数：\n");
	scanf("%d",&i);
	if(i>10)
	{
		printf("这个数大于十欸！\n");
	}
	if(i==10)
	{
		printf("这个数等于十欸！\n");
	}
	if(i<10)
	{
		printf("这个数小于十欸！\n");
	}
	return 0;
} 
