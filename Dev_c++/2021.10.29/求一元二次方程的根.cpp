#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,d1,d2;								//abcΪ����ϵ����d1d2Ϊ�� 
	float d3,d4,d5;									//d3Ϊ����ʵ�����ã�d4d5Ϊ�鲿 
	scanf("%f %f %f",&a,&b,&c);
	
	//�ж�ϵ�����
	if(a == 0 && b == 0 && c == 0)					//abc��Ϊ�� 
	{
		printf("Zero Equation");
	} 
	else if(a == 0 && b == 0 && c != 0)				//a=b=0,c!=0
	{
		printf("Not An Equation");
	}
	else if(a == 0 && b != 0)						//a=0
	{
		d1 = (-c / b);
		printf("%.2f",d1);
	} 
	else
	{
		float i = 0;								//i��Ϊ�¶��� 
		i = pow(b,2) - 4*a*c;
		
		//�ж�ϵ����� 
		if(i > 0)									//������ͬ�ĸ� 
		{
			d1 = ((-b) + sqrt(i)) / (2*a);
			d2 = ((-b) - sqrt(i)) / (2*a);
			printf("%.2f\n%.2f",d1,d2); 
		} 
		else if(i == 0)								//������ͬ�ĸ� 
		{
			d1 = (-b) / (2*a);
			printf("%.2f",d1);
		}
		else										//������ 
		{
			d3 = (-b) / (2*a);						//d3ʵ��
			d4 = sqrt(-i) / (2*a);					//d4Ϊ�鲿  
			d5 = -sqrt(-i) / (2*a);					//d5Ϊ�鲿 
			printf("%.2f+%.2fi\n",d3,d4);
			printf("%.2f%.2fi",d3,d5); 
		}
	}
	return 0;
}
