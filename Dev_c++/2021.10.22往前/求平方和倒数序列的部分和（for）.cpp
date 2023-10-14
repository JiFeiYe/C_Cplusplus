#include<stdio.h>
#include<math.h>
int main()
{
	double m,n;
	scanf("%lf %lf",&m,&n);					// ‰»Îm°¢n 
	
	double sum=0;
	for(double i=m;i<=n;i++)
	{
		sum = sum + pow(i,2) + 1/i;			//«Ûm^2+1/(m)^2+(m+1)^2+1/(m+1)^2+...+n^2+1/(n)^2 
	}
	printf("sum = %.6f",sum);
	return 0;
}
