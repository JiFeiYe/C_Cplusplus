//用do...while实现1加到100 
#include<stdio.h>
int main()
{
	int iNum = 1,iSum = 0;
	do
	{
		iSum += iNum;
		iNum++; 
	}
	while(iNum<=100);
	
	printf("%d\n",iSum);
	return 0;
} 
