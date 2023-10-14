#include <stdio.h>
int main()
{
	int price;
	int change;
	 
	printf("请输入金额（元）：\n");
	scanf("%d",&price);
	
	change = 100-price;
	
	printf("找您%d元。\n",change);
	return 0;
 } 
