#include<stdio.h>
int main()
{
	char a,b,c,d;							//声明变量 
	a = 'H',b = 'e',c = 'l',d = 'o';		//赋值单字符需用'' 
	
	putchar(a);								//输出字符变量 
	putchar(b);
	putchar(c);
	putchar(c);
	putchar(d);
	putchar('\n');							//可单独输出转义字符，需用'' 
	return 0;
}
