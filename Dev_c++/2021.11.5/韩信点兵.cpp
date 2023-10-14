#include<stdio.h>
int main()
{
	int M,i;
	scanf("%d",&M);
	i = M;
	for(;;i ++)
	{
		if(i % 5 != 1)
		{
			continue;
		}
		if(i % 6 != 5)
		{
			continue;
		}
		if(i % 7 != 4)
		{
			continue;
		}
		if(i % 11 != 10)
		{
			continue;
		}
		break;
	}
	printf("%d",i);
	return 0;
}
