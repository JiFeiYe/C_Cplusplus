#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c;				//���߳���
	scanf("%f %f %f",&a,&b,&c);
	if(a + b > c && a + c > b && b + c > a)
	{
		if(fabs(a-b)<0.001 && fabs(b-c)<0.001)
		{
			printf("�ȱ�������"); 
		} 
		else if(fabs(a-b)<0.001 || fabs(b-c)<0.001 || fabs(a-c)<0.001)
		{
			float j = pow(a,2);
			float k = pow(b,2);
			float l = pow(c,2);
			if(fabs(k+l-j)<0.001 || fabs(j+k-l)<0.001 || fabs(j+l-k)<0.001)
			{
				printf("����ֱ��������");
			} 
			else 
			{
				printf("����������");
			}
		}
		else
		{ 
		printf("��ͨ������");
		}
	}
	else
	{
		printf("��������");
	}
	return 0; 
} 
