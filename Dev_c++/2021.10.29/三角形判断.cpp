#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c;				//三边长度
	scanf("%f %f %f",&a,&b,&c);
	if(a + b > c && a + c > b && b + c > a)
	{
		if(fabs(a-b)<0.001 && fabs(b-c)<0.001)
		{
			printf("等边三角形"); 
		} 
		else if(fabs(a-b)<0.001 || fabs(b-c)<0.001 || fabs(a-c)<0.001)
		{
			float j = pow(a,2);
			float k = pow(b,2);
			float l = pow(c,2);
			if(fabs(k+l-j)<0.001 || fabs(j+k-l)<0.001 || fabs(j+l-k)<0.001)
			{
				printf("等腰直角三角形");
			} 
			else 
			{
				printf("等腰三角形");
			}
		}
		else
		{ 
		printf("普通三角形");
		}
	}
	else
	{
		printf("非三角形");
	}
	return 0; 
} 
