//输入三个不同的整数，比较大小后从大到小输出 
#include<stdio.h>
int main()
{
	int a,b,c;
	printf("输入三个不同的整数:\n"); 
	scanf("%d %d %d",&a,&b,&c);					//三个整数 
	int t;
	if(b>a)										//比较大小过程 
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
	}											//比较结束 
	printf("%d > %d > %d\n",a,b,c);
	return 0;
} 
