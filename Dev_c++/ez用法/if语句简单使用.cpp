#include<stdio.h>
int main()
{
	int i;
	printf("Please enter a number:\n");			
	scanf("%d",&i);
	if(i>=10) 									//判断若输入的i大于等于10则输出Nice！ 
	{
		printf("Nice!\n");						//若输出的语句有多句可以用花括号 
		printf("Nice again!");
	} 
	return 0;
}
