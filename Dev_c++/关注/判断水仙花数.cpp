#include<stdio.h>
#include<math.h> 							//包含数学函数的头文件（用于下方pow） 
int main()
{
	printf("请输入一个三位整数。"); 		//提示语 
	int i;
	scanf("%d",&i);
	if(i<100)								//判断输入值是否为三位数 
	{
		printf("Invalid Value.");
	}
	else if(i>999)
	{
		printf("Invalid Value.");
	}
	else									//核心 
	{
		int j,k,l;							//把三位数按位拆成三个数 
		j = i%10;							//个位 
		k = i%100/10;						//十位 
		l = i/100; 							//百位 
		if(i==pow(l,3)+pow(k,3)+pow(j,3))	//判断三个数各自三次幂后相加是否等于原数 
		{
			printf("Yes");					//若相等输出Yes 
		}
		else
		{
			printf("No");					//不相等则输出No 
		}
	}
	return 0;
}
