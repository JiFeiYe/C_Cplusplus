#include<stdio.h>
int main()
{
	long long i=999999;
	printf("The Long is:%ld\n",i);			//字母l表示输出长整型变量，搭配d等使用 
	
	printf("That is:%s\n","Love");			//s表示输出字符串，后面字符串需""
	printf("That is:%9s\n","Love");			//%后的数字表示空格数
	printf("That is:%-9s\n","Love");		//%后负号表示向左靠，后面带空格 
	printf("That is:%9.3s\n","Love");		//.3表示取字符串的前三位，后面带空格；实数则是取小数点后三位 
	printf("That is:%-9.3s\n","Love");		//取前三位并向左靠 
	return 0;
 }
