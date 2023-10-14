//尝试分数转评级 
#include<stdio.h>
int main()
{
	int grade,iSwitch;
	printf("请输入你的分数：\n");
	scanf("%d",&grade); 
	if(0 <= grade && grade<100)			//在分数区间是(0,100]时进入第一部分循环 
	{
		printf("你的评级为：");
		iSwitch = grade % 10;			//通过表达式为switch铺路 
		switch(iSwitch)
		{
			case 10: 
			case 9:
				printf("A");
				break;
			case 8:
				printf("B");
				break;
			case 7:
				printf("C");
				break;
			case 6:
				printf("D");
				break;
			case 5:
			case 4:
			case 3:
			case 2:
			case 0:
				printf("E");
				break;
			default:
				break;
		}
	}
	else if(grade == 100)				//表达式无法解释100就直接新加分支条件 
	{
		printf("你的评级为：A\n");
	}
	else 								//输入内容不对则不进行计算 
	{
		printf("这不是我要的数值。\n");
	}
	return 0; 
}
