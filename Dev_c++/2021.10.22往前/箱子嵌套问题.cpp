#include<stdio.h>
int main()
{
	int a1,b1,c1;				//定义箱子A长宽高
	int a2,b2,c2;				//定义箱子B长宽高
	int t;						//定义参数t 
	int j;						//用于比较大小 
	scanf("%d",&t);
	for(int i = 1;i <= t;i ++)
	{
		scanf("%d %d %d",&a1,&b1,&c1);
		scanf("%d %d %d",&a2,&b2,&c2);
		if(a1<b1)								//A组开始排序 
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
		if(a2<b2)								//B组开始排序 
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
		}										//排序结束 
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
