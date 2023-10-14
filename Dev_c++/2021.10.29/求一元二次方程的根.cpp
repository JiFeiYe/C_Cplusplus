#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,d1,d2;								//abc为三个系数，d1d2为根 
	float d3,d4,d5;									//d3为虚数实部所用，d4d5为虚部 
	scanf("%f %f %f",&a,&b,&c);
	
	//判断系数情况
	if(a == 0 && b == 0 && c == 0)					//abc均为零 
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
		float i = 0;								//i作为德尔塔 
		i = pow(b,2) - 4*a*c;
		
		//判断系数情况 
		if(i > 0)									//两个不同的根 
		{
			d1 = ((-b) + sqrt(i)) / (2*a);
			d2 = ((-b) - sqrt(i)) / (2*a);
			printf("%.2f\n%.2f",d1,d2); 
		} 
		else if(i == 0)								//两个相同的根 
		{
			d1 = (-b) / (2*a);
			printf("%.2f",d1);
		}
		else										//虚数根 
		{
			d3 = (-b) / (2*a);						//d3实部
			d4 = sqrt(-i) / (2*a);					//d4为虚部  
			d5 = -sqrt(-i) / (2*a);					//d5为虚部 
			printf("%.2f+%.2fi\n",d3,d4);
			printf("%.2f%.2fi",d3,d5); 
		}
	}
	return 0;
}
