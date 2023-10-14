#include<stdio.h>
int main()
{
	int year,month,day;
	scanf("%d %d %d",&year,&month,&day);
	
	//判断是否为闰年
	int sum1,sum2; 
	if(year % 4 == 0 && year % 100 != 0)			//是闰年 
	{
		int b[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
		//计算月份前共几天 
		for(int i = 1;i < month;i ++)
		{
			sum1 += b[i-1];
		}
		//计算得出结果 
		sum2 = 366 - day - sum1;
	} 
	else				//不是闰年 
	{
		int b[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		//计算月份前共几天 
		for(int i = 1;i < month;i ++)
		{
			sum1 += b[i-1];
		} 
		//计算得出结果 
		sum2 = 365 - day - sum1;
	} 
	printf("%d",sum2);
	
	return 0;
}
