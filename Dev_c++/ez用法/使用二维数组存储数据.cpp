#include<stdio.h>
int main()
{
	int a[2][2],b[2][2];						//定义数组 
	for(int i = 0;i < 2;i ++)					//for循环嵌套用以通过键盘给数组赋值 
	{
		for(int j = 0;j < 2;j ++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("输出二维数组：\n");					//输出提示 
	for(int i = 0;i < 2;i ++)					//for循环嵌套用以输出数组 
	{
		for(int j = 0;j < 2;j ++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");							//下一行数组换行 
	}
	return 0; 
} 
