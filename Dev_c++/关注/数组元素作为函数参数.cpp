#include<stdio.h>

//自定函数 
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
	c = a[1] + sum(a[0]);				//选取数组某一元素赋值给自定函数进行计算 
	printf("%d",c);
	return 0;
}
