#include<stdio.h>
int main()
{
	printf("你的宠物受伤了，你要\n");
	printf("-----------做出抉择-------------\n"); 
	printf("1、使用治疗术   2、召回宠物\n");					//尝试做一个选择菜单 
	printf("3、反击         4、聚气\n");
	printf("--------------------------------\n");
	
	int i;
	scanf("%d",&i);
	
	if(i==1)													//开始判断 
	{
		printf("你对宠物使用了治疗术！妙手回春！\n"); 
	}
	else if(i==2)
	{
		printf("你召回了宠物！狼狈而逃！\n"); 
	}
	else if(i==3)
	{
		printf("你的宠物使用了会心一击！效果拔群！\n"); 
	}
	else if(i==4)
	{
		printf("你的宠物正在进行聚气！金刚不坏！\n");
	}
	else
	{
		printf("由于你做出错误的抉择，你的宠物被击败了！下次再来挑战吧。\n"); 
	}
	
	return 0; 
}
