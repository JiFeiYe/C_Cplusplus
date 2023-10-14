//ì³²¨ÄÇÆõÊýÁÐ
#include<stdio.h>
int main()
{
	int N,a,b,c,temp;
	a = 1;b = 0;c = 1;temp = 0;
	
	scanf("%d",&N);
	int i;
	if(N == 1)
	{
		printf("1");
	}
	else
	{
		for(i = 2;c < N;i ++)
		{
			c += a;
			temp = a;
			a += b;
			b = temp;
		}
		printf("%d",i);
	}

	return 0;
}
