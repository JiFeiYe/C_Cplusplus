#include<stdio.h>
int main()
{
	long i;							//定义长整型变量 
	short j;						//定义短整型变量 
	int k1 = 1;						//定义整型变量 
	int k2 = 2;
	char l[10];						//定义字符数组变量
	
	printf("Long:\n");
	scanf("%ld",&i);				//输入长整型数据（l） 
	
	printf("Short:\n");
	scanf("%hd",&j);				//输入短整型数据（h） 
	
	printf("Number:\n");
	scanf("%d*%d",&k1,&k2);			//输入整型数据，*表示忽略第二个输入值，即k2不会被重新赋值 
	
	printf("String:\n");
	scanf("%5s",l);					//输入字符串，5表示数据所占宽度，若输入数据过长则取前五位 
	
	printf("Long is:%ld\n",i);
	printf("Short is:%hd\n",j);
	printf("Number1 is:%d\n",k1);
	printf("Number2 is:%d\n",k2);
	printf("String is:%s\n",l);
	
	return 0;
}
