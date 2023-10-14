#include<stdio.h>
int main()
{
	char a;
	a = getchar();			//在输入设备处得到字符 
	putchar(a);				//输出变量，免'' 
	putchar('\n');			//输出转义字符 
	
	getchar();				//得到回车字符（注意） 
	
	putchar(getchar());		//得到输入字符直接输出了 
	putchar('\n'); 
	
	return 0;
}
