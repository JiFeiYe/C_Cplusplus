#include<stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	getchar();
	int a,letter = 0,blank = 0,digit = 0,other = 0;
	for(int i = 1;i <= N;i ++)
	{
		a = getchar();
		if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		{
			letter ++;
		}
		else if(a == ' ' || a == '\n')
		{
			blank ++;
		}
		else if(a >= '0' && a <= '9')
		{
			digit ++;
		}
		else
		{
			other ++;
		}
	}
	printf("letter = %d, blank = %d, digit = %d, other = %d",letter,blank,digit,other);
	
	
	
	return 0;
}
