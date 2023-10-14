#include <stdio.h>
int main ()
{
	int Num1 = 1,Num2 = 2,Num3;
	
	printf("The first number is:%d\n",Num1);
	printf("The second number is:%d\n",Num2);
	
	Num3 = Num1+10;
	printf("The first number add 10 is:%d\n",Num3);
	
	Num3 = Num2+20;
	printf("The second number add 20 is:%d\n",Num3);
	
	Num3 = Num1+Num2;
	printf("The first number add the second number is:%d\n",Num3);
	
	return 0;
} 
