#include<stdio.h>
int main()
{
	char cBig;
	char cSmall;
	
	puts("请输入一个大写字母：");			

	cBig = getchar();
	cSmall = cBig+32;						//利用ASCII码转换字符 
	
	puts("对应小写字母为：");
	putchar(cSmall);
	return 0; 
}
