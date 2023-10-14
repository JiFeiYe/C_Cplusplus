//计算从1加到100的和 
#include<stdio.h>
int main()
{
	int iNum = 1,iSum = 0;
	while(iNum<=100) 
	{
		iSum = iSum + iNum;
		iNum++;
	}
	printf("%d",iSum);
	return 0;
} 
