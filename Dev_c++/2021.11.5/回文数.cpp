#include<stdio.h>
#include<math.h>
int main()
{
	int n = 0, N1 = 0, N2 = 0, a[100] = { 0 }, c = 0, count = 0;
	scanf_s("%d",&n);
	for(int k = 1;k <= n;k ++)
	{
		scanf_s("%d",&N1);
		N2 = N1;
		for(int i = 0;N1 != 0;i ++)
		{
			a[i] = N1 % 10;
			N1 = N1 / 10; 
			count ++;
		} 
		for(int i = 0;i < count;i ++)
		{
			c += pow(10,count-1-i)*a[i];
		} 
		if(c == N2)
		{
			printf("Yes\n");
		} 
		else
		{
			printf("No\n");
		}
	}
	return 0; 
}
