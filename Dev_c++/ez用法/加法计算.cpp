/*尝试简单加减乘（整数）*/ 
#include <stdio.h>
int main ()											//主函数 
{
	int Num1,Num2,Num3;
	printf("请输入两个整数x和y，输入后回车\n"); 	//解释说明 
	
	scanf("%d %d",&Num1,&Num2);						//%d是格式控制字符串，表示十进制有符号整数；
													//&取地址符，&x表示x的地址
	Num3 = Num1/Num2;								/*表达式主体，改变符号即可加减乘除；
													若除法包含负数则是“向零取整”*/ 
	printf("%d\n",Num3);
	return 0;
} 
