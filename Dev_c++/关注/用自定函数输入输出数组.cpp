#include<stdio.h>
void in(int iA[])
{
	int i = 0;
	for(i = 0;i < 10;i ++)
	{
		iA[i] = i;
	}
}

void out(int iB[])
{
	int i = 0;
	printf("数组所有数为："); 
	for(i = 0;i < 10;i ++)
	{
		printf("%d",iB[i]);
	}
}

int main()
{
	int iC[10];
	in(iC);
	out(iC);
	return 0;
}
