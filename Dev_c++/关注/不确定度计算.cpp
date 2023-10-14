//不确定度计算 
#include<stdio.h>
#include<math.h>
int main()//输入所有数据，用回车分隔。
{
	int digit = 6; 
	double a[digit],Sum1;
	for(int i = 0;i < digit;i ++)										//数据存于一个数组中 
	{
		printf("a[%d]=",i);
		scanf("%lf",&a[i]);
		Sum1 += a[i];													//数据求和 
	}
	double average;
	average = Sum1 / digit;												//数据求平均 
	printf("平均数：%.6f\n",average);
	
	
	
	double Sum2;
	for(int i = 0;i < digit;i ++)
	{
		Sum2 += pow(average - a[i],2);
	}
	double uncertainty1;
	uncertainty1 = sqrt(Sum2 / (digit * (digit - 1)));					//数据求A类不确定度 
	printf("A类不确定度：%.6f\n",uncertainty1);
	
	
	
	double uncertainty2,error;											//求B类不确定度准备 
	printf("输入仪器误差：");
	scanf("%lf",&error);
	uncertainty2 = error / sqrt(3);										//仪器误差求B类不确定度 
	printf("B类不确定度：%.6f\n",uncertainty2); 
	
	
	
	double uncertainty3;												//合成不确定度准备 
	uncertainty3 = sqrt(pow(uncertainty1,2) + pow(uncertainty2,2));
	printf("合成不确定度：%.6f\n",uncertainty3);
	
	
	
	double uncertainty4;												//相对不确定度准备
	uncertainty4 = uncertainty3 / average;								//计算相对不确定度 
	printf("相对不确定度：%.6f\n",uncertainty4); 
	
	
	
	return 0;
} 
