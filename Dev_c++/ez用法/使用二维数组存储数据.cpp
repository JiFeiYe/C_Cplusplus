#include<stdio.h>
int main()
{
	int a[2][2],b[2][2];						//�������� 
	for(int i = 0;i < 2;i ++)					//forѭ��Ƕ������ͨ�����̸����鸳ֵ 
	{
		for(int j = 0;j < 2;j ++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	printf("�����ά���飺\n");					//�����ʾ 
	for(int i = 0;i < 2;i ++)					//forѭ��Ƕ������������� 
	{
		for(int j = 0;j < 2;j ++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");							//��һ�����黻�� 
	}
	return 0; 
} 
