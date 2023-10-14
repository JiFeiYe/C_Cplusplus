#include<stdio.h>
int main()
{
	char cString[30];			/*定义一个字符数组变量，表示30字节的连续储存空间
		 						若字符串大于30字节（包括\n）则报错*/ 
	gets(cString);
	puts(cString);
	return 0;
}
