//将华氏温度转换为摄氏温度 
#include<stdio.h>
int main()									//主函数 
{
	printf("请输入华氏温度：\n");			//界面显示 
	float F,C;								//定义浮点型变量 
	scanf("%f",&F);							//输入温度 
	C = 5*(F-32)/9;							//运算式 
	printf("%f",C);							//输出结果 
	return 0; 								//返回值 
}
