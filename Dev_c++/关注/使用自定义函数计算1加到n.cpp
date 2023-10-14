//用自定义函数计算1加到n 
#include<stdio.h>

//自定义函数Sum 
int Sum(int m)							//形式参数m，也可以用数组作为形式参数 
{
	int sum = 0;
	for(int i = 1;i <= m;i ++)
	{
		sum += i;
	}
	return sum;							//自定义函数返回值sum 
} 

int main()
{
	int n,result;
	printf("请输入正整数n：");
	scanf("%d",&n);						//实际参数n 
	result = Sum(n);
	printf("从1加到n等于：%d",result);
	
	return 0;
} 
